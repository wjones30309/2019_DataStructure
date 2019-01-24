#include "array_Queue.h"

bool array_Queue :: enQueue(dataType data)
{
	if (isFull())
	{
		cout << "it is full" << endl;
		return false;
	}
	else
	{
		queue_data[tail] = data;
		tail = (tail + 1) % queueSIze;
		return true;
	}
}

bool array_Queue::deQueue()
{
	if (isEmpty())
	{
		cout << "it is empty" << endl;
		return false;
	}
	else
	{
		cout << queue_data[head] << endl;
		head = (head + 1) % queueSIze;

		return true;
	}
}
