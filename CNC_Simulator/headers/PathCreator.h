#pragma once
#include "Triangulation.h"
using namespace Geometry;
class PathCreator
{
private:
	std::vector<Triangle> sortTriangles(std::vector<Triangle>&);	// To sort triangles which are intersecting the xz plane
	std::vector<SurfacePoint> sortPoints(std::vector<Triangle>&, Triangulation&, double);	// To sort intersection points to form polyline
public:
	PathCreator();
	~PathCreator();
	std::vector<std::vector<SurfacePoint>> createPath(Triangulation& tri, double, double);	// Creates polylines for each xz plane
	
};

