#include "MainWin.h"

#include <cassert>

#include <vtkSmartPointer.h>
#include <vtkSphereSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkImageViewer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkInteractorStyleImage.h>
#include <vtkRenderer.h>
#include <vtkJPEGReader.h>

#include <QtGui/QtGui>
#include <QVTKWidget.h>

MainWin::MainWin(void)
{
  _mainViewWidget = new QVTKWidget();
  setCentralWidget(_mainViewWidget);

  SetRenderWindowForTest(_mainViewWidget);

  CreateActions();


  this->resize(600,400);
}

MainWin::~MainWin(void)
{
  delete _mainViewWidget;
}

void MainWin::SetRenderWindow(QVTKWidget* mainViewWidget)
{
  assert(mainViewWidget);
}

void MainWin::SetRenderWindowForTest(QVTKWidget* mainViewWidget)
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

void MainWin::CreateActions()
{
}