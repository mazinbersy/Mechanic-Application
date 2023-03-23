#include <iostream>
#include <string>
#include "Customer.h"
#include "Person.h"
#include "Mechanic.h"
#include "Queue.h"
#include "appointment.h"

using namespace std;

int main()
{
    int size;
    int age, id;
    string name;

    cout << "Enter Number of available Mechanics: ";
    cin >> size;

    Mechanic* mechanics = new Mechanic[size];  //creates array of mechanics

    for (int i = 0; i < size; i++)
    {
        cout << "Enter Mechanic's Name: ";
        cin >> name;
        cout << "Enter Mechanic's ID: ";
        cin >> id;
        cout << "Enter Mechanic's Age: ";
        cin >> age;

        mechanics[i].setName(name);
        mechanics[i].setID(id);
        mechanics[i].setAge(age);
    } //user input for mechanic data

    int customerNo;
    appointment y;

    cout << "Enter Number of Customers: ";
    cin >> customerNo;

    Customer* customers = new Customer[customerNo]; //creates array of customers

    for (int i = 0; i < customerNo; i++)
    {
        cout << "Enter Customer's Name: ";
        cin >> name;
        cout << "Enter Customer's ID: ";
        cin >> id;
        cout << "Enter Customer's Age: ";
        cin >> age;
        cout << "Enter the hour of appointment: ";
        cin >> y.hours;
        cout << "Enter the minutes of appointment: ";
        cin >> y.mins;

        customers[i].setName(name);
        customers[i].setAge(age);
        customers[i].setID(id);
        customers[i].setAppointment(y);
    } //user input for customer data
    int size2 = size;
    for (int i = 0; i < customerNo; i++)
    {
        bool temp = false;
        while (size2 > 0)
        {
            if (mechanics[size - size2].isAvailable(customers[i].getAppointment())) //checks availibility of the first mechanic in line and then the next and so on
            {
                mechanics[size - size2].setAppointments(customers[i].getAppointment());
                customers[i].setMechanicID(mechanics[size - size2].getID());
                size2--; 
                temp = true;  break;
            }
            size2--;
        }
        if(size2==0)
        size2 = size;
        if (!temp)
        {
            cout << "Appointment Cancelled: No Mechanic is Available at that time"<<endl;
            appointment q; q.hours = -1; q.mins = -1;
            customers[i].setAppointment(q);
        }

    }
   for (int i = 0; i < customerNo; i++)
{
    for (int j = 0; j < size; j++)
    {
        if(customers[i].getMechanicID()==mechanics[j].getID()) //checks that the mechanic's ID matches the one assigned to the customer
        {
            
            cout << customers[i].getName() << " should be appointed to "
                << mechanics[j].getName() << " at "
                << customers[i].getAppointment().hours << ":";
            if (customers[i].getAppointment().mins < 10)
                cout << "0" << customers[i].getAppointment().mins<<endl;
            else
               cout << customers[i].getAppointment().mins << endl;
            break;
        } //prints info about customer's appointment
    }
}


    Customer temp;

    for (int i = 0; i < customerNo - 1; i++)
    {
        for (int j = i + 1; j < customerNo; j++)
        {
            if (customers[i] > customers[j]) //sorts customers in ascending order of appointments
            {
    
            temp = customers[i];
                customers[i] = customers[j];
                customers[j] = temp;
            }
        }
    }

    Queue<Customer> queue(customerNo); //defines a template Queue of type Customer

    for (int i = 0; i < customerNo; i++)
    {
        queue.Enqueue(customers[i]); //inserts customers in queue in ascending order
    }
    cout << "----------------------------------------------------------------------------" << endl;
    for (int i = 0; i < customerNo; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (customers[i].getMechanicID() == mechanics[j].getID()) //checks that the mechanic's ID matches the one assigned to the customer
            {

                cout << customers[i].getName() << " has an appointment "
                     << "at "
                    << customers[i].getAppointment().hours << ":";
                if (customers[i].getAppointment().mins < 10)
                    cout << "0" << customers[i].getAppointment().mins;
                else
                    cout << customers[i].getAppointment().mins;
                cout << " with " << mechanics[j].getName()<<endl;
                break;
            }
        }
    } //prints confirmed information about customers' appointments
    return 0;
}
