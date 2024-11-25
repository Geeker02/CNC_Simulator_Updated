#include "Intersector.h"
#define TOLERANCE 0.0000001
using namespace Geometry;
using namespace std;

Intersector::Intersector()
{
}

Intersector::~Intersector()
{
}

SurfacePoint* Intersector::edgeXZPlaneIntersection(const SurfacePoint& p1, const SurfacePoint& p2, double yValueOfXZPlane)
{
    // check if the edge intersects the y-axis of the plane
    if ((p1.Y() - yValueOfXZPlane) * (p2.Y() - yValueOfXZPlane) <= 0)
    {
        double interpolatingConst = (yValueOfXZPlane - p1.Y()) / (p2.Y() - p1.Y());   // Interpolating Intersection Point
        double x = p1.X() + interpolatingConst * (p2.X() - p1.X());
        double z = p1.Z() + interpolatingConst * (p2.Z() - p1.Z());

        return new SurfacePoint(x, yValueOfXZPlane, z);
    }
    return nullptr; //if no intersection is there then return nullptr
}

vector<SurfacePoint> Intersector::triangleXZPlaneIntersection(const SurfacePoint& sp1, const SurfacePoint& sp2, const SurfacePoint& sp3, double yValueOfXZPlane)
{
    vector<SurfacePoint> intersectingPts;

    SurfacePoint* ptOnEdge1 = edgeXZPlaneIntersection(sp1, sp2, yValueOfXZPlane);
    SurfacePoint* ptOnEdge2 = edgeXZPlaneIntersection(sp3, sp2, yValueOfXZPlane);
    SurfacePoint* ptOnEdge3 = edgeXZPlaneIntersection(sp1, sp3, yValueOfXZPlane);

    // Lambda function to add a unique intersection point to the result vector
    auto addUniquePoint = [&intersectingPts](SurfacePoint* pt) 
        {
            if (pt) 
            {
                // Check if the point is already in the list to avoid duplicates
                if (find(intersectingPts.begin(), intersectingPts.end(), *pt) == intersectingPts.end()) 
                {
                    intersectingPts.push_back(*pt);
                }
            }
        };

    // Add the intersection points of each edge if they are valid and unique
    addUniquePoint(ptOnEdge1);
    addUniquePoint(ptOnEdge2);
    addUniquePoint(ptOnEdge3);

    //  Deleting pointers to avoid memory leak
    delete ptOnEdge1;
    delete ptOnEdge2;
    delete ptOnEdge3;

    return intersectingPts;
}