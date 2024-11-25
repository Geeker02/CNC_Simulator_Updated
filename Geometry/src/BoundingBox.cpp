#include "BoundingBox.h"
using namespace Geometry;
BoundingBox::BoundingBox()
{
}
BoundingBox::BoundingBox(SurfacePoint& sp1, SurfacePoint& sp2)
    :   lowestBound(sp1),
    highestBound(sp2)
{
}

BoundingBox::~BoundingBox()
{
}

std::vector<SurfacePoint> BoundingBox::getBounds()
{
    SurfacePoint topBackLeftPoint(lowestBound.X(), highestBound.Y(), lowestBound.Z());
    SurfacePoint topBackRightPoint(highestBound.X(), highestBound.Y(), lowestBound.Z());
    SurfacePoint topFrontLeftPoint(lowestBound.X(), highestBound.Y(), highestBound.Z());
    SurfacePoint topFrontRightPoint(highestBound.X(), highestBound.Y(), highestBound.Z());
    SurfacePoint bottomBackLeftPoint(lowestBound.X(), lowestBound.Y(), lowestBound.Z());
    SurfacePoint bottomBackRightPoint(highestBound.X(), lowestBound.Y(), lowestBound.Z());
    SurfacePoint bottomFrontLeftPoint(lowestBound.X(), lowestBound.Y(), highestBound.Z());
    SurfacePoint bottomFrontRightPoint(highestBound.X(), lowestBound.Y(), highestBound.Z());
    std::vector<SurfacePoint> bounds = { topBackLeftPoint, topBackRightPoint, topFrontLeftPoint, topFrontRightPoint, bottomBackLeftPoint, bottomBackRightPoint, bottomFrontLeftPoint, bottomFrontRightPoint };

    return bounds;
}
