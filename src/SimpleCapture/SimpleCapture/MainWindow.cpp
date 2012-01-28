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
#include <QVTKWidget.h>

MainWindow::MainWindow(boost::shared_ptr<pcl::OpenNIGrabber> grabber):
_grabber(grabber)
{
   _ui.setupUi(this);

   /*
  _mainViewWidget = new QVTKWidget();
  _pclVis.reset (new pcl::visualization::PCLVisualizer ("", false));

  setCentralWidget(_mainViewWidget);
  */

  // Create a timer and fire it up every 5ms
  _vis_timer = new QTimer (this);
  _vis_timer->start (5);

//  connect (_vis_timer, SIGNAL (timeout ()), this, SLOT (timeoutSlot()));

  //  SetRenderWindow();
  //  SetRenderWindowForTest(_mainViewWidget);
}

MainWindow::~MainWindow(void)
{
  delete _vis_timer;
}

/*
void MainWindow::SetRenderWindow()
{
  assert(_mainViewWidget);

  _mainViewWidget->SetRenderWindow( _pclVis->getRenderWindow());

//  _pclVis->setupInteractor (_mainViewWidget->GetInteractor(), _mainViewWidget->GetRenderWindow());
//  vis_->getInteractorStyle ()->setKeyboardModifier (pcl::visualization::INTERACTOR_KB_MOD_SHIFT);
//  ui_->qvtk_widget->update (); 

  // Start the OpenNI data acquision
  boost::function<void (const CloudConstPtr&)> f = boost::bind (&MainWindow::CloudCallback, this, _1);
  boost::signals2::connection c = _grabber->registerCallback (f);
  _grabber->start ();

  _mainViewWidget->update ();

  // Set defaults
  _pass.setFilterFieldName ("z");
  _pass.setFilterLimits (0.5, 5.0);
}


void MainWindow::SetRenderWindowForTest(QVTKWidget* mainViewWidget)
{
  assert(mainViewWidget);

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

  mainViewWidget->SetRenderWindow(renderWindow);
}
*/

/*
void MainWindow::timeoutSlot()
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
  if (!_pclVis->updatePointCloud (temp_cloud, "cloud_pass"))
  {
    _pclVis->addPointCloud (temp_cloud, "cloud_pass");
    _pclVis->resetCameraViewpoint ("cloud_pass");
  }
  FPS_CALC ("visualization");
  _mainViewWidget->update ();
}


void MainWindow::CloudCallback(const CloudConstPtr& cloud)
{
  QMutexLocker locker (&_mtx);  
  FPS_CALC ("computation");

  // Computation goes here
  _cloud_pass.reset (new Cloud);
  _pass.setInputCloud (cloud);
  _pass.filter (*_cloud_pass);
}


void MainWindow::CreateActions()
{
}

*/