#ifndef SHAPE_H
#define SHAPE_H

#include <stdio.h>
#include <iostream>

using namespace std;


class Shape
{
	public:
		virtual double get_area() = 0;
		virtual void show() = 0;
		//virtual ~Shape();
};

#endif
