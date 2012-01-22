#pragma once

#include "common.h"

#include "Qt/QMainWindow.h"
#include "Qt/QMutex.h"

#include <pcl/filters/passthrough.h>

namespace pcl{
  class OpenNIGrabber;
  namespace visualization
  {
    class PCLVisualizer;
  }
};

class QAction;
class QLabel;
class QVTKWidget;

class MainWin : public QMainWindow
{
//  Q_OBJECT

public:
  MainWin(boost::shared_ptr<pcl::OpenNIGrabber> grabber);
  ~MainWin(void);

protected:
//  void closeEvent(QCloseEvent *event);

private slots:
  void timeoutSlot();

private:
  void CloudCallback(const CloudConstPtr& cloud);

  void CreateActions();

  void SetRenderWindow();
//  void SetRenderWindowForTest(QVTKWidget* mainViewWidget);

private:
  QVTKWidget* _mainViewWidget;
  boost::shared_ptr<pcl::visualization::PCLVisualizer> _pclVis;
  boost::shared_ptr<pcl::OpenNIGrabber> _grabber;
  
  CloudPtr _cloud_pass;
  pcl::PassThrough<pcl::PointXYZRGB> _pass;

  QTimer* _vis_timer;
  QMutex _mtx;

  QAction* _newAct;
  QAction* _openAct;
  QAction* _aboutQtAction;



};

