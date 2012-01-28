#include "MainWindow.h"

#include <cassert>

#include <pcl/io/openni_grabber.h>
#include <pcl/visualization/pcl_visualizer.h>

#include <vtkSmartPointer.h>
#include <vtkSphereSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkImageViewer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkInteractorStyleImage.h>
#include <vtkRenderer.h>
#include <vtkJPEGReader.h>

#include <QtGui>
#include <QMutexLocker>
#include <QVTKWidget.h>

#include "CapturedPoints.h"

using namespace SimpleCapture;

MainWindow::MainWindow(boost::shared_ptr<pcl::OpenNIGrabber> grabber):
_grabber(grabber),
_capturedPoints(new CapturedPoints())
{
  _ui.setupUi(this);

  SetControllers();
  SetPCL();
  SetWindowForPCLVisualizer(_ui.widgetView1, _pclVisRealtime);
  SetWindowForPCLVisualizer(_ui.widgetView2, _pclVisCaptured);
//  SetWindowForTest(_ui.widgetView2);
}

MainWindow::~MainWindow(void)
{
//  QMutexLocker locker (&_mtx);
  if (_grabber->isRunning())
  { 
    _grabber->stop();
  }
  delete _vis_timer;
}

#pragma region setup
void MainWindow::SetPCL()
{
  _pclVisRealtime.reset (new pcl::visualization::PCLVisualizer ("", false));
  _pclVisCaptured.reset (new pcl::visualization::PCLVisualizer ("", false));

  // Start the OpenNI data acquision
  boost::function<void (const CloudConstPtr&)> f = boost::bind (&MainWindow::CloudCallback, this, _1);
  boost::signals2::connection c = _grabber->registerCallback (f);
  _grabber->start ();

  // Set defaults
  _pass.setFilterFieldName ("z");
  _pass.setFilterLimits (0.5, 5.0);
}

void MainWindow::SetControllers()
{
  // Create a timer and fire it up every 50ms
  _vis_timer = new QTimer (this);
  _vis_timer->start (50);
  connect (_vis_timer, SIGNAL (timeout ()), this, SLOT (TimeoutSlot()));

  // Slider
  _ui.fieldValueSlider->setRange (5, 50);
  _ui.fieldValueSlider->setValue (30);
  connect (_ui.fieldValueSlider, SIGNAL (valueChanged (int)), this, SLOT (AdjustPassThroughValuesSlot (int)));

  // Button
  connect(_ui.captureButton, SIGNAL( clicked()), this, SLOT(CaptureSlot()));
  connect(_ui.clearButton, SIGNAL( clicked()), this, SLOT(ClearSlot()));
}

void MainWindow::SetWindowForPCLVisualizer(QVTKWidget* viewWidget, boost::shared_ptr<pcl::visualization::PCLVisualizer> pclVis)
{
  assert(viewWidget);

  viewWidget->SetRenderWindow( pclVis->getRenderWindow());
  viewWidget->update ();

  //  _pclVis->setupInteractor (_mainViewWidget->GetInteractor(), _mainViewWidget->GetRenderWindow());
  //  vis_->getInteractorStyle ()->setKeyboardModifier (pcl::visualization::INTERACTOR_KB_MOD_SHIFT);
  //  ui_->qvtk_widget->update (); 
}

void MainWindow::SetWindowForTest(QVTKWidget* viewWidget)
{
  assert(viewWidget);

  //setup sphere
  vtkSmartPointer<vtkSphereSource> sphereSource = vtkSmartPointer<vtkSphereSource>::New();
  sphereSource->Update();
  vtkSmartPointer<vtkPolyDataMapper> sphereMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
  sphereMapper->SetInputConnection(sphereSource->GetOutputPort());
  vtkSmartPointer<vtkActor> sphereActor = vtkSmartPointer<vtkActor>::New();
  sphereActor->SetMapper(sphereMapper);

  //setup window
  vtkSmartPointer<vtkRenderWindow> renderWindow = vtkSmartPointer<vtkRenderWindow>::New();

  //setup renderer
  vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
  renderWindow->AddRenderer(renderer);

  renderer->AddActor(sphereActor);
  renderer->ResetCamera();

  viewWidget->SetRenderWindow(renderWindow);
}

#pragma region slot
void MainWindow::TimeoutSlot()
{
  if (!_cloud_pass)
  {
    boost::this_thread::sleep (boost::posix_time::milliseconds (1));
    return;
  }

  CloudPtr temp_cloud;
  {
    QMutexLocker locker (&_mtx);
    temp_cloud.swap (_cloud_pass); 
  }
  // Add to the 3D viewer
  if (!_pclVisRealtime->updatePointCloud (temp_cloud, "cloud_pass"))
  {
    _pclVisRealtime->addPointCloud (temp_cloud, "cloud_pass");
    _pclVisRealtime->resetCameraViewpoint ("cloud_pass");
  }
  FPS_CALC ("visualization");
  _ui.widgetView1->update ();
}

void MainWindow::AdjustPassThroughValuesSlot(int new_value)
{
  _pass.setFilterLimits (0.5, new_value / 10.0f);
}

void MainWindow::CaptureSlot()
{
  {
    QMutexLocker locker (&_mtx);
    if(_cloud_pass == NULL) return ;
    _capturedPoints->AddPoint(_cloud_pass);
  }

  // Add to the 3D viewer
  if (!_pclVisCaptured->updatePointCloud (_capturedPoints->GetPoints(), "cloud_captured"))
  {
    _pclVisCaptured->addPointCloud (_capturedPoints->GetPoints(), "cloud_captured");
    _pclVisCaptured->resetCameraViewpoint ("cloud_captured");
  }
  _ui.widgetView2->update ();
}

void MainWindow::ClearSlot()
{
  _pclVisCaptured->removePointCloud ("cloud_captured");
  _capturedPoints->ClearPoint();
}

#pragma endregion


#pragma region callback
void MainWindow::CloudCallback(const CloudConstPtr& cloud)
{
  if(_ui.realTimeUpdateCheckBox->checkState() != Qt::Checked)
  {
    return;
  }

  QMutexLocker locker (&_mtx);  
  FPS_CALC ("computation");

  // Computation goes here
  _cloud_pass.reset (new Cloud);
  _pass.setInputCloud (cloud);
  _pass.filter (*_cloud_pass);
}

#pragma endregion
