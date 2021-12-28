#include<iostream>
#include"users_db.h"
int main()
{
	users_db db;
	db.load();
	std::cout << db << "\n";

	db.remove(1);
	std::cout << db << "\n";

	std::cout << db.getById(2) << "\n";

	std::cout << db[1];
}