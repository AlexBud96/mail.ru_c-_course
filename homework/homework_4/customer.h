#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <cstring>
#include <stdio.h>


class Customer
{
public:
	Customer();

	Customer(const char* surname, const char* name, const char* middle_name, const char* address, const long long phone_number, const long long credit_card_number, const long long bank_account_number, const long double amount_of_purchases_for_the_last_week);

	Customer(const Customer& other);
	
	const Customer& operator = (const Customer& other);

	~Customer();

	void set_surname(const char* source);
	void set_name(const char* source);
	void set_middle_name(const char* source);
	void set_address(const char* source);
	void set_phone_number(const long long& source);
	void set_credit_card_number(const long long& source);
	void set_bank_account_number(const long long& source);
	void set_amount_of_purchases_for_the_last_week(const long double& source);

	const char* get_surname() const;
	const char* get_name() const;
	const char* get_middle_name() const;
	const char* get_address() const;
	const long long get_phone_number() const;
	const long long get_credit_card_number() const;
	const long long get_bank_account_number() const;
	const long double get_amount_of_purchases_for_the_last_week() const;

	void show_surname() const;
	void show_name() const;
	void show_middle_name() const;
	void show_address() const;
	void show_phone_number() const;
	void show_credit_card_number() const;
	void show_bank_account_number() const;
	void show_amount_of_purchases_for_the_last_week() const;
	
private:
	void fill_string_member(char*& destination, const char* source);
    char* surname = nullptr;
	char* name = nullptr;
	char* middle_name = nullptr;
	char* address = nullptr;
  	long long phone_number;
	long long credit_card_number;
	long long bank_account_number;
	long double amount_of_purchases_for_the_last_week;
};

#endif
