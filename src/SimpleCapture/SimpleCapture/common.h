
#include <boost/shared_ptr.hpp>

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

typedef pcl::PointXYZRGB PointType;

typedef pcl::PointCloud<PointType> Cloud;
typedef Cloud::Ptr CloudPtr;
typedef Cloud::ConstPtr CloudConstPtr;

#define FPS_CALC(_WHAT_) \
  do \
{ \
  static unsigned count = 0;\
  static double last = pcl::getTime ();\
  double now = pcl::getTime (); \
  ++count; \
  if (now - last >= 1.0) \
{ \
  std::cout << "Average framerate("<< _WHAT_ << "): " << double(count)/double(now - last) << " Hz" <<  std::endl; \
  count = 0; \
  last = now; \
} \
}while(false)