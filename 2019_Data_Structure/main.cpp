//#include "linkedList.h"
//#include "doubleLinkedList.h"
//#include "circleLinkedList.h"
//#include "array_Queue.h"
#include "nodeQueue.h"
#include "Sort.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000
using namespace std;

int main()
{
	srand(time(NULL));

	sorting sort;

	vector<int> vec;

	for (int i = 0; i < SIZE; i++)
		vec.push_back((rand() % SIZE) + 1);

	cout << "----------------before doing mergesort----------------" << endl;

	for (int i = 0; i < SIZE; i++)
		cout << vec[i] << endl;


	sort.mergeSort(vec);



	return 0;
}

/*
int main(void)
{
	nodeQueue queue;

	Data data[5];
	
	for (int i = 0; i < 5; i++)
	{
		data[i].data = i;
	}

	queue.enQueue(data[0]);
	queue.enQueue(data[1]);
	queue.deQueue();
	queue.deQueue();

	return 0;
}
*/
/*
int main()
{
	array_Queue queue;
	for(int i= 0; i<10; i++)
		queue.enQueue(i);

	for (int i = 0; i < 5; i++)
	{
		cout << queue.front();
		queue.deQueue();
	}

	for (int i = 0; i < 3; i++)
		queue.enQueue(i);

	for (int i = 0; i < 9; i++)
	{
		cout << queue.front();
		queue.deQueue();
	}

	return 0;
}
*/

/*
int main(void)
{
	circleLinkedList list;

	Data data[4];
	data[0].data = 0;
	data[1].data = 1;
	data[2].data = 2;
	data[3].data = 3;

	list.initNode(data[0]);
	list.frontAddNode(data[1]);
	list.lastAddNode(data[2]);
	list.insertNode(data[3],1);

	list.deleteNode(0);
	list.showAll();
	
	cout << endl;

	list.showData(3);
	return 0;
}
*/