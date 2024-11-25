#include "Triangulation.h"
using namespace Geometry;
Triangulation::Triangulation()
{

}

Triangulation::~Triangulation()
{

}

SurfacePoint Triangulation::getRealPoint(const Point& p) const
{
    double x;
    double y;
    double z;

    x = uniqueNumbers[p.X()];
    y = uniqueNumbers[p.Y()];
    z = uniqueNumbers[p.Z()];

    return SurfacePoint(x,y,z);
}
