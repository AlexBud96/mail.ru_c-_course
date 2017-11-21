#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
#include "vector.h"

class Circle: public Shape
{
	private:
		double radius;
		Vector point;
	public:
		double get_area();
		void show();
		Circle();
		Circle(double radius, Vector& pt1);
		Circle(double radius, double x1, double y1, double z1);
};

#endif
