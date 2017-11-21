#ifndef RANDOM_CUSTOMER_H
#define RANDOM_CUSTOMER_H

#include <stdlib.h>
#include <time.h>

namespace random_customer{

	extern char surnames[10][30];
	extern char names[10][30];
	extern char middle_names[10][30];
	extern char addresses[10][30];

	char* get_random_surname();
	char* get_random_name();
	char* get_random_middle_name();
	char* get_random_address();
	//long long* get_random_phone_number();

};
#endif
