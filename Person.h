#ifndef Person_h
#define Person_h
#include <iostream>
#include <string>
#include "appointment.h"
using namespace std;


class Person
{
protected:
	int id;
	int age;
	string name;

public:
	Person(); //default constructor
	Person(int, int, string); //overloaded constructor
	void setName(string); //setter for name
	void setID(int); //setter for ID
	void setAge(int); //setter for Age
	int getID() const; //getter for ID
	int getAge() const; //getter for Age
	string getName() const; //getter for name
	void printInfo() const; //prints information about a person

};

#endif