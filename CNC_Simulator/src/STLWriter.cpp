#include "STLWriter.h"
#include<fstream>
#include<iomanip>
using namespace Geometry;
using namespace std;

std::string STLWriter::formulateText(const Triangulation& triangulation, const Point& point)
{
    double x = triangulation.uniqueNumbers[point.X()];
    double y = triangulation.uniqueNumbers[point.Y()];
    double z = triangulation.uniqueNumbers[point.Z()];

    return std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(z) + "\n";
}

void STLWriter::write(const std::string& filename, const Triangulation& triangulation)
{
    std::ofstream outfile(filename);

    if (outfile.is_open())
    {
        outfile << "solid cube - ascii" << endl;
        for (Triangle triangle : triangulation.Triangles)
        {
            outfile << std::fixed << std::setprecision(6)
                << "    facet normal " << formulateText(triangulation, triangle.Normal());
            outfile << "        outer loop\n";
            outfile << "            vertex " << formulateText(triangulation, triangle.P1());
            outfile << "            vertex " << formulateText(triangulation, triangle.P2());
            outfile << "            vertex " << formulateText(triangulation, triangle.P3());
            outfile << "        endloop\n";
            outfile << "    endfacet\n";
        }
        outfile << "endsolid";
    }
}