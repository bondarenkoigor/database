#pragma once
#include"user.h"
class users_db
{
private:
	user* users;
	int size;
public:
	users_db();
	void add(user new_user);
	void save();
	~users_db();
};

