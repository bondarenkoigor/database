#pragma once
#include<iostream>
#include"user.h"
class users_db
{
private:
	user* users;
	int size;
public:
	users_db();
	void add(user new_user);
	void load();
	void remove(int pos);
	user getById(int id);
	friend std::ostream& operator<<(std::ostream& out, const users_db& db);
	user& operator[](int index);
	~users_db();
};

