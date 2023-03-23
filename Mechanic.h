#ifndef Mechanic_h
#define Mechanic_h
#include <iostream>
#include <string>
#include "Person.h"
using namespace std; 

class Mechanic: public Person
{
private:
	int counter;
	appointment *arr;

public:
	Mechanic(); //default constructor
	Mechanic(int, int, string); //overloaded constructor
	void setCounter(int); //sets counter
	int getCounter() const; //getter for counter
	void setAppointments(appointment); //adds an appointment to the array
	appointment* getAppointments() const; //returns pointer that points to array of appointments
	bool isAvailable(appointment); //checks availability of mechanic assuming that appointment takes 20 minutes
};

#endif