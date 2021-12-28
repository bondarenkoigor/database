#pragma once
#include<iostream>
class user
{
private:
	long id;
	std::string name;
	std::string fname;
	int age;
public:
	user();
	user(std::string name, std::string fname, int age, long id);

	std::string getName() const
	{
		return name;
	}
	std::string getFname() const
	{
		return fname;
	}
	int getAge() const
	{
		return age;
	}
	long getId() const
	{
		return id;
	}
	void setName(std::string name);
	void setFname(std::string fname);
	void setAge(int age);

	friend std::ostream& operator<<(std::ostream& out, const user& user);
};