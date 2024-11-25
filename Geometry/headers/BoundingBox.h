#pragma once
#include "SurfacePoint.h"
#include <vector>
namespace Geometry 
{
    class BoundingBox
    {

    private:

        SurfacePoint lowestBound;
        SurfacePoint highestBound;


    public:
        BoundingBox();
        BoundingBox(SurfacePoint& sp1, SurfacePoint& sp2);
        ~BoundingBox();

        std::vector<SurfacePoint> getBounds();
    };
}