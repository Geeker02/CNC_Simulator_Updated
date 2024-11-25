#pragma once
#include <string>
#include "Writer.h"
#include "Triangulation.h"
using namespace Geometry;

class STLWriter : public Writer
{
public:
    void write(const std::string& filename, const Triangulation& triangulation);

private:
    std::string formulateText(const Triangulation& triangulation, const Point& point); // Passing parameters as const references.
};