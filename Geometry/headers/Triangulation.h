#pragma once
#include "Triangle.h"
#include <vector>
#include "SurfacePoint.h"
#include "BoundingBox.h"
#include <limits>
namespace Geometry
{
    class Triangulation
    {
    public:
        std::vector<double> uniqueNumbers;
        std::vector<Triangle> Triangles;

        BoundingBox boundingBox;

        Triangulation();
        ~Triangulation();

        SurfacePoint getRealPoint(const Point&) const;
    };
}