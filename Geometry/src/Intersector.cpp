#include "Intersector.h"
using namespace Geometry;

Point* Intersector::isIntersecting( Point& p1, Point& p2, double y, const vector<double>& uniqueValues)
{

    if ((uniqueValues[p1.Y()] - y) *(uniqueValues[p2.Y()] - y) <= 0) {
        double ty = (y - uniqueValues[p1.Y()]) / (uniqueValues[p2.Y()] - uniqueValues[p1.Y()]);
        double x_ = uniqueValues[p1.X()] + ty * (uniqueValues[p2.X()] - uniqueValues[p2.X()]);
        double z_ = uniqueValues[p1.Z()] + ty * (uniqueValues[p2.Z()] - uniqueValues[p2.Z()]);
        return new Point(x_, y, z_);
    }
    return nullptr;
}

vector<Point> Intersector::intersect(const Triangle& triangle, double y, const Triangulation& tri)
{
    vector<Point> intersectingPts;

    Point p1 = t.P1();
    Point p2 = t.P2();
    Point p3 = t.P3();

    Point* ptOnEdge1 = isIntersecting(p1, p2, y, tri.UniqueNumbers);
    Point* ptOnEdge2 = isIntersecting(p3, p2, y, tri.UniqueNumbers);
    Point* ptOnEdge3 = isIntersecting(p1, p3, y, tri.UniqueNumbers);

    if (ptOnEdge1)
        intersectingPts.push_back(*ptOnEdge1);
    if (ptOnEdge2)
        intersectingPts.push_back(*ptOnEdge2);
    if (ptOnEdge3)
        intersectingPts.push_back(*ptOnEdge3);

    return intersectingPts;
}