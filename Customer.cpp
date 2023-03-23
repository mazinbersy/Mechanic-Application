#include "Customer.h"

Customer::Customer()
{
	mechanicID = 0;
	x.hours = 0;
	x.mins = 0;
}
Customer::Customer(int i, int a, string n, int id, appointment y) : Person(a, i, n)
{
	mechanicID = id;
	x.hours = y.hours;
	x.mins = y.mins;
}
void Customer::setMechanicID(int i)
{
	mechanicID = i;
}
void Customer::setAppointment(appointment y)
{
	x.hours = y.hours;
	x.mins= y.mins;
}
int Customer::getMechanicID() const
{
	return mechanicID;
}
appointment Customer::getAppointment() const
{
	return x;
}
bool Customer:: operator <(const Customer& c2)
{
	if (c2.x.hours < x.hours)
	{
		return false;
}
	if (c2.x.hours == x.hours)
		if (c2.x.mins < x.mins)
			return false;
	return true;
}
bool Customer::operator >(const Customer& c2)
{
	if (c2.x.hours > x.hours)
	{
		return false;
	}
	if (c2.x.hours == x.hours)
		if (c2.x.mins > x.mins)
			return false;
	return true;
}
bool Customer::operator ==(const Customer& c2)
{
	if (c2.x.hours == x.hours)
		if (c2.x.mins == x.mins)
			return true;
	return false;
}

