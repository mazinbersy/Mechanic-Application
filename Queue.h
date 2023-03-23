#ifndef Queue_h
#define Queue_h
#include <iostream>
#include <string>


using namespace std;

template<class T>
class Queue
{
private:
	int front; // front index
	int rear; // rear index
	int counter; // number of elements
	int maxSize; // size of array queue
	T* values; // element array

public:

	Queue(int size)
	{
		values = new T[size];
		maxSize = size;
		front = 0;
		rear = -1;
		counter = 0;
	}// constructor

	~Queue() { delete[] values; } // destructor

	bool IsEmpty()
	{
		if (counter != 0)
			return false;
		else
			return true;

	}
	bool IsFull()
	{
		if (counter < maxSize)
			return false;
		else
			return true;

	}
	bool Enqueue(T x)
	{
		if (IsFull()) {
			cout << "Error: the queue is full." << endl;
			return false;
		}
		else {
			// calculate the new rear position (circular)
			rear = (rear + 1) % maxSize;
			// insert new item
			values[rear] = x;
			// update counter
			counter++;
			return true;
		}

	}
	bool Dequeue(T& x)
	{
		if (IsEmpty()) {
			cout << "Error: the queue is empty." << endl;
			return false;
		}
		else {
			// retrieve the front item
			x = values[front];
			// move front
			front = (front + 1) % maxSize;
			// update counter
			counter--;
			return true;
		}

	}
	void DisplayQueue()
	{
		cout << "front -->";
		for (int i = 0; i < counter; i++) {
			if (i == 0) cout << "\t";
			else cout << "\t\t";
			cout << values[(front + i) % maxSize];
			if (i != counter - 1)
				cout << endl;
			else
				cout << "\t<-- rear" << endl;
		}

	}
};

#endif