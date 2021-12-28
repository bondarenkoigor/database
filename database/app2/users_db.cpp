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
void users_db::load()
{
	FILE* pf;
	fopen_s(&pf, "C:\\Users\\Public\\Documents\\data.txt", "rt");
	if (pf != nullptr)
	{
		char tmp_name[50], tmp_fname[50];
		int tmp_age = 0, tmp_id = 0;
		for (int i = 0; !feof(pf); i++)
		{
			fscanf_s(pf, "%s%s%i%li", tmp_name, 50, tmp_fname, 50, &tmp_age, &tmp_id);
			add(user(tmp_name, tmp_fname, tmp_age, tmp_id));
		}
		this->size--;
	}
}
void users_db::remove(int pos)
{
	if (pos < size)
	{
		user* new_arr = new user[size - 1];
		for (int i = 0; i < pos; i++)
		{
			new_arr[i] = users[i];
		}
		for (int i = pos; i < size - 1; i++)
		{
			new_arr[i] = users[i + 1];
		}
		delete[] users;
		users = new_arr;
		size--;
	}
}
user users_db::getById(int id)
{
	for (int i = 0; i < size; i++)
	{
		if (users[i].getId() == id) return users[i];
	}
	return users[0];
}
user& users_db::operator[](int index)
{
	if (index < this->size)
		return users[index];
	return users[0];
}
users_db::~users_db()
{
	delete[] users;
}

std::ostream& operator<<(std::ostream& out, const users_db& db)
{
	for (int i = 0; i < db.size; i++)
	{
		out << db.users[i] << "\n";
	}
	return out;
}