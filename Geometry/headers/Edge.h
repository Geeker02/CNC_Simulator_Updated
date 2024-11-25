#pragma once
#include "Point.h"

namespace Geometry
{
	class Edge
	{
	public:
		Point start;
		Point end;

		Edge(Point&, Point&);
		~Edge();

		bool operator==(Edge&);
	};
}