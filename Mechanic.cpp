#include "Mechanic.h"

Mechanic::Mechanic()
{
	counter = 0;
    arr = new appointment[100];
}
Mechanic::Mechanic(int i, int a, string n) : Person( a,  i,  n)
{
	counter = 0;
	arr = new appointment[100];
}
void Mechanic::setCounter(int c)
{
	counter = c;
}
int Mechanic::getCounter() const
{
	return counter;
}
void Mechanic::setAppointments(appointment y)
{
   
        arr[counter].hours = y.hours;
        arr[counter].mins = y.mins;
        counter++;

}
appointment* Mechanic::getAppointments() const
{
	return arr;
}

bool Mechanic::isAvailable(appointment u)
{
    int f = 0, k = 0, y = 0, j = 0;
    if (u.mins < 20)
    {
        y = u.hours - 1;
        int rem = 20 - u.mins;
        f = 60 - rem;
        j = u.mins + 40;
        k = u.hours;
        j = u.mins;
    }
    else if (u.mins)
    {
        k = u.hours + 1;
        int rem = 60 - u.mins;
        j = 20 - rem;
        f = u.mins - 40;
        y = u.hours;
        f = u.mins;
    }
    else if (u.mins >= 20 && u.mins <= 40)
    {
        y = u.hours;
        k = u.hours;
        f = u.mins - 20;
        j = u.mins + 20;
    }

    for (int i = 0; i < counter; i++)
    {
        if (arr[i].hours >= y && arr[i].hours <= k)
        {
            if (arr[i].hours > y && f - arr[i].mins <= 40)
            {
                return false;
            }
            if (arr[i].hours < k && arr[i].mins - j <= 40)
            {
                return false;
            }
            if (y == arr[i].hours && arr[i].mins - f <= 20)
            {
                return false;
            }
            if (k == arr[i].hours && j - arr[i].mins <= 20)
            {
                return false;
            }
        }
    }
    return true;
}

