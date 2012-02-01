#include "CapturedPoints.h"

#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/surface/mls.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/filters/approximate_voxel_grid.h>
#include <pcl/registration/icp.h>

#include <time.h>

using namespace SimpleCapture;

CapturedPoints::CapturedPoints(void):
_savedCloudCnt(0)
{
  _savedCloud.clear();
}


CapturedPoints::~CapturedPoints(void)
{
}


std::string CapturedPoints::AddPoints(CloudPtr& addingCloud)
{
  std::string pointID = (boost::format("points_%d") % _savedCloudCnt).str() ;
  _savedCloud[pointID] = addingCloud;
  _savedCloudCnt++;

  return pointID;
  /*
  printf("pointSize(before) : %d\n", addingCloud->size());

  //  CloudPtr downsizedPoints = Downsizing(addingCloud); 
  CloudPtr downsizedPoints = DownsizingUsingApprox(addingCloud); 
  CloudPtr outputPoints = downsizedPoints;
  //  CloudPtr outputPoints = Smoothing(downsizedPoints); 

  printf("pointSize(after) : %d\n", outputPoints->size());


  if(_cloud_saved == NULL)
  {
    _cloud_saved = outputPoints;
  }else{
    // 位置あわせ
    {
      pcl::IterativeClosestPoint<pcl::PointXYZRGB, pcl::PointXYZRGB> icp;
      icp.setInputCloud(outputPoints);
      icp.setInputTarget(_cloud_saved);

      // Set the max correspondence distance to 5mm (e.g., correspondences with higher distances will be ignored)
      icp.setMaxCorrespondenceDistance (0.005);
      // Set the maximum number of iterations (criterion 1)
      icp.setMaximumIterations (50);
      // Set the transformation epsilon (criterion 2)
      icp.setTransformationEpsilon (1e-8);
      // Set the euclidean distance difference epsilon (criterion 3)
      icp.setEuclideanFitnessEpsilon (1);

      clock_t start = clock();
      CloudPtr alignedPoints( new Cloud );

      icp.align(*alignedPoints);
      printf("pointSize(after) : %d\n", alignedPoints->size());
      double interval = (double)(clock() - start) / CLOCKS_PER_SEC;
      *_cloud_saved += *alignedPoints;
      printf("Interva:%lf\n", interval);

      std::cout << "has converged:" << icp.hasConverged() << " score: " << icp.getFitnessScore() << std::endl;
      std::cout << icp.getFinalTransformation() << std::endl;

      _cloud_saved = DownsizingUsingApprox(_cloud_saved); 
    }

    // 点を減らす

    // メッシュ
  }
  */
}

CloudPtr CapturedPoints::Downsizing(CloudPtr& addingCloud)
{
  pcl::VoxelGrid<PointType> sor;
  sor.setInputCloud (addingCloud);
  float gridSize = 0.005f;
  sor.setLeafSize (gridSize, gridSize, gridSize);

  CloudPtr downsizedPoints( new Cloud );
  sor.filter(*downsizedPoints);
  return downsizedPoints;
}

CloudPtr CapturedPoints::DownsizingUsingApprox(CloudPtr& addingCloud)
{
  pcl::ApproximateVoxelGrid<PointType> voxelGrid;
  voxelGrid.setInputCloud (addingCloud);
  float gridSize = 0.005f;
  voxelGrid.setLeafSize (gridSize, gridSize, gridSize);

  CloudPtr downsizedPoints( new Cloud );
  voxelGrid.filter(*downsizedPoints);
  return downsizedPoints;
}

CloudPtr CapturedPoints::Smoothing(CloudPtr& inputCloud)
{
  pcl::MovingLeastSquares<PointType, pcl::Normal> mls;
  mls.setInputCloud(inputCloud);

  // set parameters
  pcl::search::KdTree<PointType>::Ptr tree (new pcl::search::KdTree<PointType>);
  mls.setPolynomialFit (true);
  mls.setSearchMethod (tree);
  mls.setSearchRadius (0.05);

  // reconstruct
  pcl::MovingLeastSquares<PointType, pcl::Normal>::PointCloudIn mlsOutput;
  mls.reconstruct(mlsOutput);
  return mlsOutput.makeShared();
}

void CapturedPoints::ClearPoints()
{
  _savedCloud.clear();
  _savedCloudCnt = 0;
}