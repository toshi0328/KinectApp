#include "common.h"

#include <pcl/io/openni_grabber.h>

#include <QApplication>

#include "MainWindow.h"

int main (int argc, char ** argv)
{
  // Open the first available camera
  boost::shared_ptr<pcl::OpenNIGrabber> grabber(new pcl::OpenNIGrabber("#1"));
  // Check if an RGB stream is provided
  if (!grabber->providesCallback<pcl::OpenNIGrabber::sig_cb_openni_point_cloud_rgb> ())
  {
    return (-1);
  }

  QApplication app(argc, argv);
  MainWindow mainWin(grabber);
  mainWin.show();
  return app.exec();
}