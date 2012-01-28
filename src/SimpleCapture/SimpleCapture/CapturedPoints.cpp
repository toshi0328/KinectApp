#include "CapturedPoints.h"

#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/surface/mls.h>
#include <pcl/filters/voxel_grid.h>

using namespace SimpleCapture;

CapturedPoints::CapturedPoints(void)
{
}


CapturedPoints::~CapturedPoints(void)
{
}


void CapturedPoints::AddPoint(CloudPtr& addingCloud)
{
  CloudPtr downsizedPoints = Downsizing(addingCloud); 
  CloudPtr outputPoints = Smoothing(downsizedPoints); 

  if(_cloud_saved == NULL)
  {
    _cloud_saved = outputPoints;
  }else{
    // 位置あわせ


    *_cloud_saved += *outputPoints;

    // 点を減らす

    // メッシュ
  }
}

CloudPtr CapturedPoints::Downsizing(CloudPtr& addingCloud)
{
  pcl::VoxelGrid<pcl::PointXYZRGB> sor;
  sor.setInputCloud (addingCloud);
  float gridSize = 0.007f;
  sor.setLeafSize (gridSize, gridSize, gridSize);

  CloudPtr downsizedPoints( new Cloud );
  sor.filter(*downsizedPoints);
  return downsizedPoints;
}

CloudPtr CapturedPoints::Smoothing(CloudPtr& inputCloud)
{
  pcl::MovingLeastSquares<pcl::PointXYZRGB, pcl::Normal> mls;
  mls.setInputCloud(inputCloud);

  // set parameters
  pcl::search::KdTree<pcl::PointXYZRGB>::Ptr tree (new pcl::search::KdTree<pcl::PointXYZRGB>);
  mls.setPolynomialFit (true);
  mls.setSearchMethod (tree);
  mls.setSearchRadius (0.05);

  // reconstruct
  pcl::MovingLeastSquares<pcl::PointXYZRGB, pcl::Normal>::PointCloudIn mlsOutput;
  mls.reconstruct(mlsOutput);
  return mlsOutput.makeShared();
}

void CapturedPoints::ClearPoint()
{
  _cloud_saved.reset();
}