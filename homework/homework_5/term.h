#ifndef TERM_H
#define TERM_H


#include <iostream>
using namespace std;

class Term
{
 private:
    double coefficient;
    int exponent;
 public:
	Term();
    Term(int coef, int exp);
	Term(const Term& other);
	~Term();
	const Term& operator = (const Term& other);
	Term operator + (const Term& t);
	Term operator - (const Term& t);
	Term operator * (const Term& t);
	Term operator * (const int i);
	const Term& operator ++ (int);
	const Term& operator -- (int);
	friend ostream& operator<<(ostream& os, const Term& t);
	friend const bool operator<(const Term& t1, const Term& t2);
	friend const bool operator==(const Term& t1, const Term& t2);
	const double& get_coef() const;
	const int& get_exp() const;
};

struct TermComparator
{
    bool operator()(const Term& lhs, const Term& rhs) 
	{
        return lhs.get_exp() < rhs.get_exp();
    }
};


#endif
