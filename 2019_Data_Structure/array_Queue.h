#pragma once
#include <iostream>

using namespace std;

#define queueSIze 11
#define dataType int


class array_Queue
{
private:
	dataType queue_data[queueSIze] = { 0, };
	int head = 0;
	int tail = 0;

public:


	bool enQueue(dataType data);
	bool deQueue();
	dataType front()
	{
		return queue_data[head];
	}

	bool isFull()
	{
		if ((tail + 1) % queueSIze == head)
			return true;
		else
			return false;
	}

	bool isEmpty()
	{
		if (head == tail)
			return true;
		else
			return false;
	}

};