#ifndef VECTOR_H
#define VECTOR_H

#include <math.h>


typedef struct Vector
{
				double x;
				double y;
				double z;
				friend Vector vec_multi(const Vector& fr, const Vector& sc); // operator *?
				double vec_len();
				Vector(): x(0), y(0), z(0){};
				Vector(double x, double y, double z): x(x), y(y), z(z){};
				const bool operator!=(const Vector&) const;
				Vector operator-(const Vector&) const;
				Vector operator+(const Vector&) const;			
}Vector;
// какие отличия?

typedef struct VectorDerived: public Vector {} V1;
#endif
