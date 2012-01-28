#pragma once

#include "common.h"

namespace SimpleCapture{
  class CapturedPoints
  {
  public:
    CapturedPoints(void);
    ~CapturedPoints(void);

    void AddPoint(CloudPtr& addingCloud);
    void ClearPoint();

    CloudPtr GetPoints(){ return _cloud_saved;}

  private:
    CloudPtr Downsizing(CloudPtr& addingCloud);
    CloudPtr Smoothing(CloudPtr& addingCloud);


    CloudPtr _cloud_saved;
  };

}