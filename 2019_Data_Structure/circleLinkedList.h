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

//Data of circleLinkedList
class Node
{
private:
	Data m_data; //Data in Node


public:
	int key; // for finding wanted Node

	Node *nextNode = nullptr;

	Data getData() const { return m_data; }
	void putData(const Data data) { m_data = data; }

};

//circleLinkedList
class circleLinkedList
{
private:
	Node *head;

public:
	int m_length = 0;

	bool initNode(Data data); // initialize circleLinkedList
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