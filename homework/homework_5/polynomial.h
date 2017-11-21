#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <set>
#include "term.h"


class Polynomial
{
private:
    std::set<Term, TermComparator> terms;
public:
    Polynomial(){};
	Polynomial(Term* const& t, const int& size);
    ~Polynomial(){};
	const double isthere_exp(const int& exponent);
	const Polynomial& operator = (const Polynomial& other);
    //const Polynomial& operator+(const Polynomial& p);
    Polynomial operator+(const Polynomial& p);
	Polynomial operator+(const Term& t);
	friend ostream& operator<<(ostream& os, const Polynomial& p);
};

#endif
