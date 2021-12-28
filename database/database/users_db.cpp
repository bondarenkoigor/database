#include "users_db.h"

users_db::users_db()
{
	this->users = nullptr;
	this->size = 0;
}

void users_db::add(user new_user)
{
	user* new_arr = new user[size + 1];
	for (int i = 0; i < size; i++)
	{
		new_arr[i] = this->users[i];
	}
	new_arr[size] = new_user;
	delete[] this->users;
	this->users = new_arr;
	size++;
}

void users_db::save()
{
	FILE* pf;
	fopen_s(&pf, "C:\\Users\\Public\\Documents\\data.txt", "wt");
	if (pf != nullptr) 
	{
		for (int i = 0; i < size; i++)
		{
			fprintf_s(pf, "%s\t%s\t%i\t%li\n", users[i].getName().c_str(), users[i].getFname().c_str(), users[i].getAge(), users[i].getId());
		}
		fclose(pf);
	}
}

users_db::~users_db()
{
	delete[] users;
}