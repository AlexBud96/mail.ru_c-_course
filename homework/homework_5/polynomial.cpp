#include "polynomial.h"


const double Polynomial::isthere_exp(const int& exponent)
{
	auto my_it = terms.begin();
	for(; my_it != terms.end(); my_it++)
		{
			if(exponent == (*my_it).get_exp())
				{
					terms.erase(*my_it);
					return (*my_it).get_coef();
				};
		}
	return 0.0;
};

const Polynomial& Polynomial::operator = (const Polynomial& other)
{
	this->terms = other.terms;
	return *this;
};

Polynomial::Polynomial(Term* const& t, const int& size)
{
	for(int i =0; i<size; i++)
		{
			int exponent = t[i].get_exp();	
			double coef = (*this).isthere_exp(exponent);
			if(coef != 0)
				{
					terms.insert(Term(t[i].get_coef() + coef , exponent));
				}
			else
				{
					terms.insert(t[i]);
				}
		};
};

Polynomial Polynomial::operator+(const Term& t)
{
	int exponent = t.get_exp();
	double coef = (*this).isthere_exp(exponent);
	if(coef != 0)
				{
					terms.insert(Term(t.get_coef() + coef , exponent));
				}
			else
				{
					terms.insert(t);
				}
	return *this;
};

Polynomial Polynomial::operator+(const Polynomial& p)
{
    auto my_it = terms.begin();
    auto p_it = p.terms.begin();
	Polynomial result;

    while (my_it != terms.end() && p_it != p.terms.end())
    {
        if (my_it->get_exp() > p_it->get_exp())
        {
            result.terms.insert(*my_it);
            ++my_it;
        }
        else if (my_it->get_exp() == p_it->get_exp())
        {
            result.terms.insert(Term(my_it->get_coef() + p_it->get_coef(), my_it->get_exp()));
            ++my_it;
            ++p_it;
        }
        else
        {
            result.terms.insert(*p_it);
            ++p_it;
        }
    }

    return result;
};

ostream& operator<<(ostream& os, const Polynomial& p)
{
	auto iter = p.terms.begin();
	//if(p.terms.begin() == p.terms.end()){cout << "$ ";};
	while(iter != --p.terms.end())
		{	
		std::cout << (*iter++) <<" + ";
		};
	std::cout << (*iter);
	std::cout << endl;
	return os;
};




