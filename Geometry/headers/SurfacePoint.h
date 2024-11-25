#pragma once
#include <iostream>

namespace Geometry
{
	class SurfacePoint
	{
	private:
		double mX;
		double mY;
		double mZ;
	public:

		SurfacePoint();
		SurfacePoint(double x, double y, double z);
		~SurfacePoint();


		double X() const;
		double Y() const;
		double Z() const;

		bool operator==(const SurfacePoint& other) const;

		bool operator()(const SurfacePoint& other) const;


	};
}