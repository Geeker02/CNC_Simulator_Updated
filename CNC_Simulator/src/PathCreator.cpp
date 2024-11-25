#include "PathCreator.h"
#include "Intersector.h"
#include <unordered_map>
#include<stdexcept>
#include <iostream>
using namespace std;
PathCreator::PathCreator()
{
}

PathCreator::~PathCreator()
{
}

vector<vector<SurfacePoint>> PathCreator::createPath(Triangulation& tri, double y_max, double y_min)
{
	vector<vector<SurfacePoint>> path;
	double y = y_max;

	for (; y >= y_min; y = y - 0.05)
	{
		vector<Triangle> yIntersecingTrs;
		for (auto t:tri.Triangles)
		{
			bool intersect = false;

			Point p1 = t.P1();
			Point p2 = t.P2();
			Point p3 = t.P3();

			SurfacePoint sp1 = tri.getRealPoint(p1);
			SurfacePoint sp2 = tri.getRealPoint(p2);
			SurfacePoint sp3 = tri.getRealPoint(p3);

			if ((sp1.Y() <= y && sp2.Y() > y) ||
				(sp1.Y() > y && sp2.Y() <= y) ||
				(sp1.Y() <= y && sp3.Y() > y) ||
				(sp1.Y() > y && sp3.Y() <= y) ||
				(sp2.Y() <= y && sp3.Y() > y) ||
				(sp2.Y() > y && sp3.Y() <= y))
			{ 
				intersect = true; 
			}
			if (intersect)
			{
				yIntersecingTrs.push_back(t);
			}
		}
		vector<Triangle> sortedTriangles = sortTriangles(yIntersecingTrs);
		vector<SurfacePoint> sortedPoints = sortPoints(sortedTriangles, tri, y);
		path.push_back(sortedPoints);
	}
	return path;
}

vector<Triangle> PathCreator::sortTriangles(vector<Triangle>& coplanarTriangles)
{
	if (coplanarTriangles.empty()) 
	{
		return {};
	}

	vector<Triangle> sortedTriangles;
	sortedTriangles.push_back(coplanarTriangles.front());
	coplanarTriangles.erase(coplanarTriangles.begin());

	while (!coplanarTriangles.empty()) 
	{
		bool foundNext = false;

		for (auto it = coplanarTriangles.begin(); it != coplanarTriangles.end(); ++it) 
		{
			if (sortedTriangles.back().areAdjacent(*it)) 
			{
				sortedTriangles.push_back(*it); 
				coplanarTriangles.erase(it);
				foundNext = true;
				break;
			}
		}

		if (!foundNext) 
		{
			throw runtime_error("Triangles do not form a closed loop!");
		}
	}

	if (!sortedTriangles.front().areAdjacent(sortedTriangles.back())) 
	{
		throw runtime_error("The sorted triangles do not form a closed loop!");
	}

	return sortedTriangles;
}

vector<SurfacePoint> PathCreator::sortPoints(vector<Triangle>& sortedTriangles, Triangulation& tri, double yValueOfXZPlane)
{
	if (sortedTriangles.empty())
	{
		return {};
	}

	vector<vector<SurfacePoint>> IntersectionPtsOfEachTrs;
	vector<SurfacePoint> sortedPoints;
	unordered_map<SurfacePoint, int, SurfacePoint> map;

	Intersector intersector;
	for (auto triangle : sortedTriangles)
	{
		SurfacePoint sp1 = tri.getRealPoint(triangle.P1());
		SurfacePoint sp2 = tri.getRealPoint(triangle.P2());
		SurfacePoint sp3 = tri.getRealPoint(triangle.P3());

		IntersectionPtsOfEachTrs.push_back(intersector.triangleXZPlaneIntersection(sp1, sp2, sp3, yValueOfXZPlane));
	}

	for (auto intersection : IntersectionPtsOfEachTrs)
	{
		for (int i = 0; i < intersection.size(); i++)
		{
			auto pair = map.find(intersection[i]);
			if (pair == map.end())
			{
				sortedPoints.push_back(intersection[i]);
				map[intersection[i]] = sortedPoints.size() - 1;
			}
		}
	}
	return sortedPoints;
}
