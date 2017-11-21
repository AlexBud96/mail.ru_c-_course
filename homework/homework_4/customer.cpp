#include "customer.h"

	Customer::Customer():phone_number(0), credit_card_number(0), bank_account_number(0), amount_of_purchases_for_the_last_week(0){};

	Customer::Customer(const char* surname, const char* name, const char* middle_name, const char* address, const long long phone_number, const long long credit_card_number, const long long bank_account_number, const long double amount_of_purchases_for_the_last_week)
	: phone_number(phone_number), credit_card_number(credit_card_number), bank_account_number(bank_account_number), amount_of_purchases_for_the_last_week(amount_of_purchases_for_the_last_week)
		{
			fill_string_member(this->surname, surname);
			fill_string_member(this->name, name);
			fill_string_member(this->middle_name, middle_name);
			fill_string_member(this->address, address);
		};

	Customer::Customer(const Customer& other)
	: phone_number(other.phone_number), credit_card_number(other.credit_card_number), bank_account_number(other.bank_account_number), amount_of_purchases_for_the_last_week(other.amount_of_purchases_for_the_last_week)
		{
			fill_string_member(this->surname, other.surname);
			fill_string_member(this->name, other.name);
			fill_string_member(this->middle_name, other.middle_name);
			fill_string_member(this->address, other.address);
		};

	const Customer& Customer::operator = (const Customer& other)
		{
			fill_string_member(this->surname, other.surname);
			fill_string_member(this->name, other.name);
			fill_string_member(this->middle_name, other.middle_name);
			fill_string_member(this->address, other.address);
			set_phone_number(other.phone_number);
			set_credit_card_number(other.credit_card_number);
			set_bank_account_number(bank_account_number);
			set_amount_of_purchases_for_the_last_week(amount_of_purchases_for_the_last_week);
			
			return *this;
		};

	Customer::~Customer()
		{
			//if(this->surname != nullptr)
				delete[] surname;
			//if(this->name != nullptr)
				delete[] name;
			//if(this->middle_name != nullptr)
				delete[] middle_name;
			//if(this->address != nullptr)
				delete[] address;
		};

	void Customer::set_surname(const char* source)
		{fill_string_member(this->surname, source);}
	void Customer::set_name(const char* source)
		{fill_string_member(this->name, source);}
	void Customer::set_middle_name(const char* source)
		{fill_string_member(this->middle_name, source);}
	void Customer::set_address(const char* source)
		{fill_string_member(this->address, source);}
	void Customer::set_phone_number(const long long& source)
		{phone_number = source;}
	void Customer::set_credit_card_number(const long long& source)
		{credit_card_number = source;}
	void Customer::set_bank_account_number(const long long& source)
		{bank_account_number = source;}
	void Customer::set_amount_of_purchases_for_the_last_week(const long double& source)
		{amount_of_purchases_for_the_last_week = source;}

	const char* Customer::get_surname() const
		{ return this->surname; }
	const char* Customer::get_name() const
		{ return this->name; }
	const char* Customer::get_middle_name() const
		{ return this->middle_name; }
	const char* Customer::get_address() const
		{ return this->address; }
	const long long Customer::get_phone_number() const
		{ return phone_number; }
	const long long Customer::get_credit_card_number() const
		{ return credit_card_number; }
	const long long Customer::get_bank_account_number() const
		{ return bank_account_number; }
	const long double Customer::get_amount_of_purchases_for_the_last_week() const
		{ return amount_of_purchases_for_the_last_week; }

	void Customer::show_surname() const
		{printf("%s\n", surname);}
	void Customer::show_name() const
		{printf("%s\n", name);}
	void Customer::show_middle_name() const
		{printf("%s\n", middle_name);}
	void Customer::show_address() const
		{printf("%s\n", address);}
	void Customer::show_phone_number() const
		{printf("%.0lld\n", phone_number);}
	void Customer::show_credit_card_number() const
		{printf("%.0lld\n", credit_card_number);}
	void Customer::show_bank_account_number() const
		{printf("%.0lld\n", bank_account_number);}
	void Customer::show_amount_of_purchases_for_the_last_week() const
		{printf("%.2Lf\n", amount_of_purchases_for_the_last_week);}

	void Customer::fill_string_member(char*& destination, const char* source)
		{
		 	if(destination != nullptr)
				delete[] destination;
			destination = new char[strlen(source)+1];
			memcpy(destination, source, strlen(source)+1);
		};

	//qsort_Customers_array(Customer)
