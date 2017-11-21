#include "customer.h"
#include "random_customer.h"

//using namespace random_customer;

/*char* get_lexicographic_string(const Customer& Client)
	{
		char* str = new char[strlen(Client.get_surname())+strlen(Client.get_name())+strlen(Client.get_middle_name())+1];
		strcat(str, Client.get_surname());
		strcat(str, Client.get_name());
		strcat(str, Client.get_middle_name());
		return str;
	}*/

int sign(const int x)
			{
				if (x > 0) return 1;
				if (x < 0) return -1;
				return 0;
			};

int compareCustomers (const void * a, const void * b)
	{
		Customer* First = (Customer*)a;
		Customer* Second = (Customer*)b;
		
		int surname_comp = strcmp(First->get_surname(), Second->get_surname());
		switch (sign(surname_comp))
			{
				case 1: return 1;
				case -1: return -1;
				case 0: break;
		    };
		int name_comp = strcmp(First->get_name(), Second->get_name());
		switch (sign(name_comp))
			{
				case 1: return 1;
				case -1: return -1;
				case 0: break;
		    };
		int m_name_comp = strcmp(First->get_middle_name(), Second->get_middle_name());
		switch (sign(m_name_comp))
			{
				case 1: return 1;
				case -1: return -1;
				case 0: return 0;
		    };
		return 0;
	};

int credit_card_check (Customer* csts, int size, const int& a, const int& b)
	{
		for(int i=0; i< size; i++)
			{
				if (csts[i].get_credit_card_number() >= a && csts[i].get_credit_card_number() <= b)
				{
					csts[i].show_surname();
					csts[i].show_name();
					csts[i].show_middle_name();
					csts[i].show_address();
					csts[i].show_phone_number();
					csts[i].show_credit_card_number();
					csts[i].show_bank_account_number();
					csts[i].show_amount_of_purchases_for_the_last_week();	
				};
			};
		return 0;
	};

int print_array(Customer* csts, int size)
	{
		for(int i=0; i<size; i++)
			{
					csts[i].show_surname();
					csts[i].show_name();
					csts[i].show_middle_name();
					csts[i].show_address();
					csts[i].show_phone_number();
					csts[i].show_credit_card_number();
					csts[i].show_bank_account_number();
					csts[i].show_amount_of_purchases_for_the_last_week();
					printf("\n\n");	
				};
		return 0;
	};


int main(){
	srand (time(NULL)); // seed for random
	Customer Pavel;
	Customer Users[20];
	for(int i=0; i<20;i++) //initialize random customers array
		{
			Users[i].set_surname(random_customer::get_random_surname());
			Users[i].set_name(random_customer::get_random_name());
			Users[i].set_middle_name(random_customer::get_random_middle_name());
			Users[i].set_address(random_customer::get_random_address());
			Users[i].set_phone_number(88005553535 + i);
			Users[i].set_credit_card_number(1234123412341234 + i);
			Users[i].set_bank_account_number(359359359 + i);
			Users[i].set_amount_of_purchases_for_the_last_week(1000 + 100*i);
		}

	/*for(int i=0; i<20;i++)
		{
			printf("\n----------------------------\n");
			Users[i].show_surname();
			Users[i].show_name();
			Users[i].show_middle_name();
			Users[i].show_address();
			Users[i].show_phone_number();
			Users[i].show_credit_card_number();
			Users[i].show_bank_account_number();
			Users[i].show_amount_of_purchases_for_the_last_week();
		}*/
	
	//int rez = compareCustomers(&Users[5], &Users[6]);
	//printf("%d\n", rez);
	
	//print_array(Users, 20);
	
	printf("\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
	printf("\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
	printf("\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");

	qsort (Users, 20, sizeof(Customer), compareCustomers);

	//printf("\nAfter qsort:\n");

	//print_array(Users);
	
	credit_card_check(Users, 20, 1100, 2800);
	//qsort_
	return 0;
}
