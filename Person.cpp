#include "Person.h"

Person::Person()
{
	age = 0;
	id = 0;
	name = "";
}
Person::Person(int a, int i, string n)
{
	name = n;
	age = a;
	id = i;
}
void Person::setName(string n)
{
	name = n;
}
void Person::setID(int i)
{
	id = i;
}
void Person::setAge(int a)
{
	age = a;
}
int Person::getID() const
{
	return id;
}
int Person::getAge() const
{
	return age;
}
string Person::getName() const
{
	return name;
}
void Person::printInfo() const
{
	cout << "Name is: " << name << endl;
	cout << "ID is: " << id << endl;
	cout << "Age is: " << age << endl;


}