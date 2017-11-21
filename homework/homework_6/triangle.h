#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"
#include "vector.h"

class Triangle: public Shape
{
	private:
		Vector points[3];
	public:
		Triangle();
		Triangle(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3); // (...args)
		Triangle(const Vector& pt1, const Vector& pt2, const Vector& pt3);
		double get_area();
		void show();
};

#endif
