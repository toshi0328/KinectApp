#pragma once

#include "common.h"

#include <QMainWindow>
#include <QMutex>

#include <pcl/filters/passthrough.h>
#include "ui_MainWindow.h"

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
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
  MainWindow(boost::shared_ptr<pcl::OpenNIGrabber> grabber);
  ~MainWindow(void);

protected:
//  void closeEvent(QCloseEvent *event);

private slots:
//  void timeoutSlot();

private:
  void CloudCallback(const CloudConstPtr& cloud);

//  void SetRenderWindow();
//  void SetRenderWindowForTest(QVTKWidget* mainViewWidget);

private:
//  QVTKWidget* _mainViewWidget;
  boost::shared_ptr<pcl::visualization::PCLVisualizer> _pclVis;
  boost::shared_ptr<pcl::OpenNIGrabber> _grabber;
  
  CloudPtr _cloud_pass;
  pcl::PassThrough<pcl::PointXYZRGB> _pass;

  QTimer* _vis_timer;
  QMutex _mtx;

  private:
    Ui::MainWindow _ui;
};