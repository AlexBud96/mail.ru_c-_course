#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"
#include "vector.h"

class Rectangle: public Shape
{
	private:
		Vector points[4];
	public:
		Rectangle();
		Rectangle(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3, double x4, double y4, double z4);
		Rectangle(const Vector& pt1, const Vector& pt2, const Vector& pt3, const Vector& pt4);
		double get_area();
		void show();
};

#endif
