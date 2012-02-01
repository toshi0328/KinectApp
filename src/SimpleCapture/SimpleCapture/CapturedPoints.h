#pragma once

#include "common.h"

namespace SimpleCapture{
  class CapturedPoints
  {
  public:
    CapturedPoints(void);
    ~CapturedPoints(void);

    std::string AddPoints(CloudPtr& addingCloud);
    void ClearPoints();

   CloudPtr GetPoints(const std::string& pointID){ return _savedCloud[pointID];}

  private:
    CloudPtr Downsizing(CloudPtr& addingCloud);
    CloudPtr DownsizingUsingApprox(CloudPtr& addingCloud);

    CloudPtr Smoothing(CloudPtr& addingCloud);

    std::map<std::string,CloudPtr> _savedCloud;
    int _savedCloudCnt;
  };

}