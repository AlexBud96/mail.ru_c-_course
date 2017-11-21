#include "vector.h"

Vector Vector::operator-(const Vector& vec) const
{
	double x = vec.x - this->x;
	double y = vec.y - this->y;
	double z = vec.z - this->z;
	return Vector(x, y, z);	
};

Vector Vector::operator+(const Vector& vec) const
{
	double x = vec.x + this->x;
	double y = vec.y + this->y;
	double z = vec.z + this->z;
	return Vector(x, y, z);	
};

const bool Vector::operator!=(const Vector& vec) const
{
	if(this->x != vec.x)
		return true;
	if(this->y != vec.y)
		return true;
	if(this->y != vec.y)
		return true;
	return false;
};

Vector vec_multi(const Vector& fr, const Vector& sc)
{
	Vector rez;
	rez.x = fr.y*sc.z - fr.z*sc.y;
	rez.y = fr.z*sc.x - fr.x*sc.z;
	rez.z = fr.x*sc.y - fr.y*sc.x;
	return rez;
};

double Vector::vec_len()
{
	return sqrt(pow(x,2) + pow(y,2) + pow(z,2));
};
