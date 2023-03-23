#ifndef Customer_h
#define Customer_h
#include <iostream>
#include <string>
#include "Person.h"	
using namespace std; 

class Customer: public Person
{
private:
	int mechanicID;
	appointment x;

public:
	Customer(); //default constructor
	Customer(int,int, string, int, appointment); //overloaded constructor
	void setMechanicID(int); //setter for mechanicID
	void setAppointment(appointment); //setter for appointment
	int getMechanicID() const; //getter for mechanicID
	appointment getAppointment() const; //getter for appointment
	bool operator <(const Customer&); //overloads < sign to compare the appointments of 2 customers
	bool operator >(const Customer&); //overloads > sign to compare the appointments of 2 customers
	bool operator ==(const Customer&); //overloads == sign to compare the appointments of 2 customers


};

#endif