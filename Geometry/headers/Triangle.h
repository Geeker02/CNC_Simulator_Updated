#pragma once
#include <vector>
#include "Point.h"
#include "Edge.h"
using namespace std;
namespace Geometry
{
    class Triangle
    {
        // Three points representing the vertices of the triangle
    private:
        Point p1;
        Point p2;
        Point p3;
        Point normal;
        Edge e1;
        Edge e2;
        Edge e3;
        vector<Edge> edges = {e1,e2,e3};

    public:
        Triangle(Point normal, Point p1, Point p2, Point p3);
        ~Triangle();


        // Getter functions to access the private members 
        Point P1();
        Point P2();
        Point P3();
        Point Normal();

        vector<Edge> getEdges();

        vector<Point> Points();
        bool areAdjacent(Triangle&);
    };
}
