#include "term.h"
#include "polynomial.h"
#include <stdio.h>
#include <typeinfo>

int main()
{
	Term one(10, 1);
	Term two(2, 2);
	Term three(4, 3);
	Term ten[10];
	cout << ten[0];
	cout << two;
	cout << three << endl;
	ten[0] = three;
	ten[1] = ten[9] + ten[8];
	ten[2] = ten[9] - ten[8];
	ten[3] = ten[3] * three;
	ten[4] = ten[4] * 3;
	ten[5]++;
	ten[6]--;

	for(int i = 0; i<10; i++)
		{
			printf("ten[%d] = ", i);
			cout << ten[i] << endl;
		};

	Polynomial poly(ten, 10);
	Polynomial poly2(ten, 10);
	cout << "poly = " << poly;
	cout << "poly2 = " << poly2;
	cout <<"-----------------------\n";
	Polynomial poly3 = poly + poly2;
	cout <<  "poly3 = " << poly3;
	cout <<"-----------------------\n";
	poly2 = poly2 + ten[0];
	cout <<  "poly2 = " << poly2;
	cout << "poly = " << poly;
	cout <<"-----------------------\n";
	Polynomial poly4 = poly + poly2;
	cout << "poly4 =" << poly4;
	cout <<"-----------------------\n";
	cout << "poly3 =" << poly3;
	cout << "poly3 =" << poly4;
	Polynomial poly5 = poly4 + poly3;
	cout << "poly5 = poly4 + poly3 = " << poly5;
};
