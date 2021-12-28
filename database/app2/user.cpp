#include "user.h"

user::user()
{
	this->name = this->fname = "unknown";
	this->age = 0;
	this->id = 0;
}

user::user(std::string name, std::string fname, int age, long id)
{
	this->name = name;
	this->fname = fname;
	this->age = age;
	this->id = id;
}

void user::setName(std::string name)
{
	this->name = name;
}

void user::setFname(std::string fname)
{
	this->fname = fname;
}

void user::setAge(int age)
{
	this->age = age;
}

std::ostream& operator<<(std::ostream& out, const user& user)
{
	out << "first name: " << user.name << "\tlast name: " << user.fname << "\tage: " << user.age << "\tid: " << user.id;
	return out;
}
