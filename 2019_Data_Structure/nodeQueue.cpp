#include "nodeQueue.h"


void nodeQueue::enQueue(Data data)
{
	Node *newNode = new Node;
	newNode->putData(data);

	if (head == nullptr)
	{		
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->nextNode = newNode;
		tail = tail->nextNode;
	}
}

void nodeQueue::deQueue()
{
	if (head == nullptr)
		cout << "it is empty" << endl;
	else
	{
		Node *delNode = this->head;

		cout << head->getData().data << endl;

		head = head->nextNode;

		delete delNode;

	}
}