#include "rectangle.h"

Rectangle::Rectangle()
{
	points[0] = Vector();
	points[1] = Vector();
	points[2] = Vector();
	points[3] = Vector();
};

Rectangle::Rectangle(double x1, 
double y1, 
double z1, 
double x2, 
double y2, 
double z2, 
double x3, 
double y3, 
double z3, 
double x4, 
double y4, 
double z4)
{
	points[0] = Vector(x1,y1,z1);
	points[1] = Vector(x2,y2,z2);
	points[2] = Vector(x3,y3,z3);
	points[3] = Vector(x3,y3,z3);
};

Rectangle::Rectangle(const Vector& pt1, const Vector& pt2, const Vector& pt3, const Vector& pt4)
{
	points[0] = pt1;
	points[1] = pt2;
	points[2] = pt3;
	points[3] = pt4;
};

double Rectangle::get_area()
{
	Vector a = points[0] - points[3];
	Vector b = points[2] - points[3];
	Vector c = points[1] - points[2];
	Vector d = vec_multi(a, b);
	Vector e = vec_multi(c, b);
	if(e.vec_len() != d.vec_len())
		{
			cout << "This is not a rectangle.\n";
			return 1;
		}
	return d.vec_len();
};

void Rectangle::show()
{
	cout << "Rectangle(point 1): x = " << points[0].x << ", y = " << points[0].y << ", z = " << points[0].z << endl;
	cout << "Rectangle(point 2): x = " << points[1].x << ", y = " << points[1].y << ", z = " << points[1].z << endl; 
	cout << "Rectangle(point 3): x = " << points[2].x << ", y = " << points[2].y << ", z = " << points[2].z << endl;
	cout << "Rectangle(point 4): x = " << points[3].x << ", y = " << points[3].y << ", z = " << points[3].z << endl; 
};
