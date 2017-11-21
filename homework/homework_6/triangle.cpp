#include "triangle.h"

Triangle::Triangle()
{
	points[0] = Vector();
	points[1] = Vector();
	points[2] = Vector();
};

Triangle::Triangle(double x1, 
double y1, 
double z1, 
double x2, 
double y2, 
double z2, 
double x3, 
double y3, 
double z3)
{
	points[0] = Vector(x1,y1,z1);
	points[1] = Vector(x2,y2,z2);
	points[2] = Vector(x3,y3,z3); 
};

Triangle::Triangle(const Vector& pt1, const Vector& pt2, const Vector& pt3) 
{
	points[0] = pt1;
	points[1] = pt2;
	points[2] = pt3;
};

double Triangle::get_area()
{
	Vector a = points[1] - points[0];
	Vector b = points[2] - points[0];
	Vector c = vec_multi(a, b);
	return 0.5*c.vec_len();
};

void Triangle::show()
{
	cout << "Triangle(point 1): x = " << points[0].x << ", y = " << points[0].y << ", z = " << points[0].z << endl;
	cout << "Triangle(point 2): x = " << points[1].x << ", y = " << points[1].y << ", z = " << points[1].z << endl; 
	cout << "Triangle(point 3): x = " << points[2].x << ", y = " << points[2].y << ", z = " << points[2].z << endl; 
};
