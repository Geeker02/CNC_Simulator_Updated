#include "Edge.h"

Geometry::Edge::Edge(Point& p1, Point& p2)
	:start(p1),
	end(p2)
{
}

Geometry::Edge::~Edge()
{
}

bool Geometry::Edge::operator==(Edge& other)
{

	return (((start == other.start) ||
			(start == other.end)) && 
			((end == other.end) || 
			(end == other.start)));
}
