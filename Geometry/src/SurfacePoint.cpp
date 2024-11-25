#include "SurfacePoint.h"
#define TOLERANCE 1e-6
using namespace Geometry;

SurfacePoint::SurfacePoint()
	:mX(0.0),
	mY(0.0),
	mZ(0.0)
{
}

SurfacePoint::SurfacePoint(double x, double y, double z)
	:mX(x),
	mY(y),
	mZ(z)
{
}

SurfacePoint::~SurfacePoint()
{
}
double SurfacePoint::X() const
{
	return mX;
}

double SurfacePoint::Y() const
{
	return mY;
}

double SurfacePoint::Z() const
{
	return mZ;
}

bool SurfacePoint::operator()(const SurfacePoint& other) const
{
	if (mX > other.mX) return true;
	if (mX < other.mX) return false;
	return mZ > other.mZ;
}


bool SurfacePoint::operator==(const SurfacePoint& other) const
{
	return (fabs(mX - other.mX) < TOLERANCE) && (fabs(mY - other.mY) < TOLERANCE) && (fabs(mZ - other.mZ) < TOLERANCE);
}




