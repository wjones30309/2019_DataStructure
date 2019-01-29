#pragma once
#include <iostream>

using namespace std;

class Data
{
public:
	int key = 0;
};

class Node
{
private:
	Data data;

public:
	Node *left = nullptr;
	Node *right = nullptr;

	Data getData() const { return data; }
	void putData(const Data data) { this -> data = data; }
} ;

class jinTree
{
public:
	Node *root = nullptr;

	bool add(Data data);
	bool remove(int m_key);

	void showDataInOrder(Node* tmpNode);
	
	bool isEmpty()
	{
		if (root == nullptr) 
			return true; 
		else
			return false; 
	}
};