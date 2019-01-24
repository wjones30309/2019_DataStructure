#pragma once
#include <iostream>
#define dataType int

using namespace std;

struct Data
{
	dataType data = 0;

};

class Node
{
private :
	Data m_data;
public:
	Node *nextNode = nullptr;

	Data getData() const { return m_data; }
	void putData(const Data data) { m_data = data; }
};

class nodeQueue
{
private:
	Node *head = nullptr;
	Node *tail = nullptr;
public:


	void enQueue(Data data);
	void deQueue();


};