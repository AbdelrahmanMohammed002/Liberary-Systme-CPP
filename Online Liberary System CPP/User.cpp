#include "User.h"


int User::count = 0;

User::User() :name(""), age(0), email(""), password("")
{
	count++;
	id = count;
}

User::User(string name, int age, string email, string password)
{
	this->name = name;
	this->age = age;
	this->email = email; 
	this->password = password;

	count++;
	id = count;
}

User::User(const User& user)
{
	name = user.name;
	age = user.age;
	email = user.age;
	password = user.password; 

	id = user.id; 
}

bool User::operator==(const User& user)
{
	if (name != user.name || age != user.age || email != user.email || password != user.password || id != user.id) {
		return false;
	}
	return true;
}

void User::setName(string name)
{
	this->name = name;
}

string User::getName() const
{
	return name;
}

void User::setPassword(string password)
{
	this->password = password;
}

string User::getPassword() const
{
	return password;
}

void User::setEmail(string email)
{
	this->email = email;
}

string User::getEmail() const
{
	return email;
}

void User::setAge(int age)
{
	this->age = age;
}

int User::getAge() const
{
	return age;
}

void User::setId(int id)
{
	this->id = id;
}

int User::getId() const
{
	return id;
}

void User::DisplayInfo()
{
	cout << "///////////////////////////////////////////" << endl;
	cout << "Name: " << name << endl;
	cout << "ID: " << id << endl;
	cout << "Email: " << email << endl;
	cout << "Age:	" << age << endl;
	cout << "///////////////////////////////////////////" << endl;
}
/*
void User::operator=(const User& user)
{
	name = user.name;
	age = user.age;
	email = user.age;
	password = user.password;
}
*/
ostream& operator<<(ostream& output, const User& user)
{
	cout << "////////////////////////////////////////////////" << endl;
	cout << "User " << user.id << "'s Informations: " << endl;
	output << "Name: " << user.name << endl;
	output << "Age: " << user.age << endl;
	output << "Email: " << user.email << endl;
	cout << "////////////////////////////////////////////////" << endl;

	return output;
}

istream& operator>>(istream& input, User& user)
{
	cout << "Please Enter User Information." << endl;
	cout << "Name: "; input >> user.name; 
	cout << "Age: "; input >> user.age; 
	cout << "Email: "; input >> user.email; 
	cout << "Password: "; input >> user.password; 

	return input;

}
