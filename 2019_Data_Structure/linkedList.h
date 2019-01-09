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

//Data of linkedList
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


//struture
class linkedList
{
private:
	Node *head;
	
public:
	int m_length = 0;

	bool initNode(Data data); // initialize linkedList
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

/*
class Node
{
private:
	int m_nAge;
	int m_nGrade;
	string m_nName;

public:
	Node* m_poNext = nullptr;

	void setAge(const int age) { m_nAge = age; };
	void setGrade(const int grade) { m_nGrade = grade; };
	void setName(const string name) { m_nName = name; };

	int getAge() const { return m_nAge; };
	int getGrade() const { return m_nGrade; };
	string getName() const { return m_nName; };
};

class linkedList
{
private:
	Node* root = nullptr;
public:

	void add(const int age, const int grade, const string name, int index);
	void erase(int index);
	Node show(int index);
	int length();
	
};

*/