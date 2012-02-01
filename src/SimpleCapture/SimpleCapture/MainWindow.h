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

namespace SimpleCapture{
  class CapturedPoints;
  class MainWindow : public QMainWindow
  {
    Q_OBJECT
  public:
    MainWindow(boost::shared_ptr<pcl::OpenNIGrabber> grabber);
    ~MainWindow(void);

  private slots:
      void TimeoutSlot();
      void AdjustPassThroughValuesSlot(int new_value);
      void CaptureSlot();
      void CapturedListChangeValueSlot(QListWidgetItem* sender);
      void ClearSlot();

  private:
    void SetControllers();
    void SetPCL();
    void SetWindowForPCLVisualizer(QVTKWidget* mainViewWidget, boost::shared_ptr<pcl::visualization::PCLVisualizer> pclVis);
    void SetWindowForTest(QVTKWidget* mainViewWidget);

    void CloudCallback(const CloudConstPtr& cloud);

    void AddToCapturedList(const std::string& pointID);
    void RemoveAllCapturedList();
//    void UpdateCapturedList(boost::shared_ptr<CapturedPoints> capturedPoints);

  private:
    boost::shared_ptr<pcl::visualization::PCLVisualizer> _pclVisRealtime;
    boost::shared_ptr<pcl::visualization::PCLVisualizer> _pclVisCaptured;
    boost::shared_ptr<pcl::OpenNIGrabber> _grabber;

    CloudPtr _cloud_pass;
    pcl::PassThrough<PointType> _pass;

    boost::shared_ptr<CapturedPoints> _capturedPoints;

    QTimer* _vis_timer;
    QMutex _mtx;

  private:
    Ui::MainWindow _ui;
  };
}