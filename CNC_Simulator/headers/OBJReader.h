#pragma once
#include <QStringList>
#include "Triangulation.h"
#include "Reader.h"
using namespace Geometry;

class OBJReader : public Reader
{
public:
	OBJReader();
	~OBJReader();

	void read(const std::string& fileName, Triangulation& tri);
	bool operator()(double a, double b) const;

private:
	Point vectorReader(const QStringList& lineList, std::map<double, int, OBJReader>& uniqueMap, Triangulation& tri);
};