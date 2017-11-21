#include "random_customer.h" 

			 char random_customer::surnames[10][30] = {"Хусейн", "Тодзио", "Ленин", "Сёва", "Кайши", "Сталин", "Цзэдун", "Путин", "Медведев", "Ын"}; 
			char random_customer::names[10][30] = {"Саддам", "Хидэки", "Владимир", "Хирохито", "Чан", "Иосиф", "Владимир", "Мао", "Дмитрий", "Ким"};
			char random_customer::middle_names[10][30] = {"Абд Аль-Маджид", "Хидэнори", "Ильич", "Есихито", "Жуйюань", "Виссарионович", "Владимирович", "Жуньчжи", "Анатольевич", "Чен"};
			char random_customer::addresses[10][30] = {"Ирак", "Япония", "СССР", "Япония", "Китай", "СССР", "Китай", "Россия", "Мордор", "КНДР"};
		char* random_customer::get_random_surname()
			{
				//srand (time(NULL));
				return surnames[rand() % 10];
			};
		char* random_customer::get_random_name()
			{
				//srand (time(NULL));
				return names[rand() % 10];
			};
		char* random_customer::get_random_middle_name()
			{
				//srand (time(NULL));
				return middle_names[rand() % 10];
			};
		char* random_customer::get_random_address()
			{
				//srand (time(NULL));
				return addresses[rand() % 10];
			};
		/*long long* get_random_phone_number()
			{
				return rand() % 9999999999 + 80000000000;
			};*/
		//void get_random_credit_card_number(const int& source);
		//void get_random_bank_account_number(const int& source);
		//void get_random_amount_of_purchases_for_the_last_week(const int& source);
