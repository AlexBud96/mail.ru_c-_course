#include "shape.h"
#include "triangle.h"
#include "rectangle.h"
#include "circle.h"
#include "vector.h"

int main() // какие здесь аргументы?
{
	Vector fs(0, 0, 0);
	Vector sc(5, 10, 0);
	Vector th(0, 10, 0);
    Vector fr(5, 0, 0);
	//Triangle tre(fs, sc, th);
	Shape* sh = new Triangle(fs, sc, th);
	//Rectangle rec(fs, sc, th, fr);
	//Shape& sh2 = rec;
	//Circle cr(5, fr);
	//Shape& sh3 = cr;
	cout << "Triangle area = " << sh->get_area() << endl;
	sh->show();
	//cout << "Rectangle area = " << sh2.get_area() << endl;
	//sh2.show();
	//cout << "Circle area = " << sh3.get_area() << endl;
	//sh3.show();
	delete sh;

	return 0;
};

// sublime text
// CLian 
