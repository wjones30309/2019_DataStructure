#pragma once
#include <iostream>

using namespace std;
static int keyNum;

// all of Data
class Data
{
public:
	int data = 0;

};

//Data of DoublelinkedList
class Node
{
private:
	Data m_data; //Data in Node


public:
	int key; // for finding wanted Node

	Node *preNode = nullptr;
	Node *nextNode = nullptr;

	Data getData() const { return m_data; }
	void putData(const Data data) { m_data = data; }

};


//struture
class doubleLinkedList
{
private:
	Node *head;

public:
	int m_length = 0;

	bool initNode(Data data); // initialize DoublelinkedList
	bool frontAddNode(Data data);
	bool lastAddNode(Data data);
	bool insertNode(Data data, int key);

	bool deleteNode(int key);
	void deleteAll();

	bool changeData(Data data, int key);

	bool showData(int key);
	void showAll();

	bool isEmpty()
	{
		if (this->m_length == 0)
			return true;
		else
			return false;
	}
};