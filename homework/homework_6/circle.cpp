#include "circle.h"

double Circle::get_area()
{
	return M_PI*pow(radius, 2);
};

void Circle::show()
{
	cout << "Circle(radius) = " << radius << endl;
	cout << "Point on circle: x = " << point.x << ", y = " << point.y << ", z = " << point.z << endl;
}; 

Circle::Circle()
{
	radius = 0.0;
	point = Vector();
};

Circle::Circle(double radius, Vector& pt1): radius(radius), point(pt1)
{};

Circle::Circle(double radius, double x1, double y1, double z1): radius(radius)
{
	point = Vector(x1,y1,z1);	
};
