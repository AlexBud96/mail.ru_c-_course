#include "term.h"

Term::Term() : coefficient(1), exponent(1)
{};

Term::Term(int coef, int exp) : coefficient(coef), exponent(exp)
{};

Term::Term(const Term& other): coefficient(other.coefficient), exponent(other.exponent)
{};

Term::~Term()
{};

const Term& Term::operator = (const Term& other)
{
	this->coefficient = other.coefficient;
	this->exponent = other.exponent;
	return *this;
};

Term Term::operator + (const Term& t)
{
	Term result(this->coefficient + t.coefficient, this->exponent);
	return result;
};

Term Term::operator - (const Term& t)
{
	//Term* result = new Term[1];
	Term result(this->coefficient - t.coefficient, this->exponent);
	return result;
};

Term Term::operator * (const Term& t)
{
	Term result(this->coefficient * t.coefficient, this->exponent + t.exponent);
	return result;
};

Term Term::operator * (const int i)
{
	Term result(this->coefficient * i, this->exponent);
	return result;
};

const Term& Term::operator ++ (int)
{
	this->coefficient++;
	return *this;
};

const Term& Term::operator -- (int)
{
	this->coefficient--;
	return *this;
};

ostream& operator<<(ostream& os, const Term& t)  
{  
    os << t.coefficient <<"*" << "x^" << t.exponent;  
    return os;
};

const bool operator==(const Term& t1, const Term& t2)
{
	return (t1.exponent == t2.exponent) ? true : false;
};

const bool operator<(const Term& t1, const Term& t2)
{
	return (t1.exponent < t2.exponent) ? true : false;
};

const double& Term::get_coef() const
{
	return this->coefficient;
};

const int& Term::get_exp() const
{
	return this->exponent;
};
