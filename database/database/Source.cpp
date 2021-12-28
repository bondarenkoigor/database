#include<iostream>
#include<string>
#include"users_db.h"
int main()
{
	users_db db;
	db.add(user("user1", "123", 20, 0));
	db.add(user("user2", "456", 21, 1));
	db.add(user("user3", "789", 22, 2));
	db.save();
}