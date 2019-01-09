#include "linkedList.h"


bool linkedList::initNode(Data data)
{
	if (isEmpty())
	{
		Node *newNode = new Node;
		newNode->putData(data);
		newNode->key = keyNum++;

		this->head = newNode;

		m_length++;
		return true;
	}
	else
	{
		cout << "already initialization is done" << endl;
		return false;
	}

}
bool linkedList :: frontAddNode(Data data)
{
	if (!isEmpty())
	{
		Node *newNode = new Node;
		newNode->putData(data);
		newNode->key = keyNum++;

		newNode->nextNode = this->head;
		this->head = newNode;

		m_length++;
		return true;
	}
	else
	{
		cout << "you have to initialize first" << endl;
		return false;
	}
}
bool linkedList ::lastAddNode(Data data)
{
	if (!isEmpty())
	{
		Node *ptrNode = this->head;
		while (ptrNode->nextNode != nullptr)
			ptrNode = ptrNode->nextNode;

		Node *newNode = new Node;
		newNode->putData(data);
		newNode->key = keyNum++;

		ptrNode->nextNode = newNode;

		m_length++;
		return true;
	}
	else
	{
		cout << "you have to initialize first" << endl;
		return false;
	}
}
bool linkedList ::insertNode(Data data, int key)
{

	if (!isEmpty())
	{
		Node *ptrNode = this->head;

		while (ptrNode->nextNode != nullptr)
		{
			if (ptrNode->key == key)
			{

				Node *newNode = new Node;
				newNode->putData(data);
				newNode->key = keyNum++;

				newNode->nextNode = ptrNode->nextNode;
				ptrNode->nextNode = newNode;

				m_length++;

				return true;
			}

			ptrNode = ptrNode->nextNode;

		}

		//lastAddNode is executed
		lastAddNode(data);
		return true;
		
	}
	else
	{
		cout << "you have to initialize first" << endl;
		return false;
	}

}

bool linkedList :: deleteNode(int key)
{
	if (!isEmpty())
	{
		Node *ptrNode = this->head;
		Node *delNode;
		if (ptrNode->key == key)
		{
			if (ptrNode->nextNode != nullptr)
			{
				this->head = ptrNode->nextNode;
				delete ptrNode;
			}
			else
			{
				this->head = nullptr;
				delete ptrNode;
			}

			m_length--;
			return true;

		}


		while (ptrNode->nextNode != nullptr)
		{
			if (ptrNode->nextNode->key == key)
			{
				delNode = ptrNode->nextNode;
				ptrNode->nextNode = ptrNode->nextNode->nextNode;


				delete delNode;
				m_length--;
				return true;
			}

			ptrNode = ptrNode->nextNode;
		}
		cout << "no erase data" << endl;
		return false;
	}
	else
	{
		cout << "no erase data" << endl;
		return false;
	}
}
void linkedList :: deleteAll()
{
	if (!isEmpty())
	{
		Node *ptrNode = this->head;
		Node *delNode = ptrNode;

		

		while (ptrNode->nextNode != nullptr)
		{
			ptrNode = ptrNode->nextNode;
			delNode->nextNode = nullptr;
			delete delNode;
			m_length--;
			delNode = ptrNode;

		}

		delete delNode;
		m_length--;
		this->head = nullptr;

	}
}

bool linkedList::changeData(Data data, int key)
{
	if (!isEmpty())
	{
		Node *ptrNode = this->head;

		if (ptrNode->key == key)
		{
			ptrNode->putData(data);
			cout << "changed key :" << ptrNode->key << endl;
			cout << "changed data :" << ptrNode->getData().data << endl;
			return true;
		}

		while (ptrNode->nextNode != nullptr)
		{
			ptrNode = ptrNode->nextNode;

			if (ptrNode->key == key)
			{
				ptrNode->putData(data);
				cout << "changed key :" << ptrNode->key << endl;
				cout << "changed data :" << ptrNode->getData().data << endl;
				return true;
			}

		}
		cout << "no data" << endl;
		return false;
	}
	else
	{
		cout << "no data" << endl;
		return false;
	}

}

bool linkedList :: showData(int key)
{
	if (!isEmpty())
	{
		Node *ptrNode = this->head;
		
		if (ptrNode->key == key)
		{
			cout << "key :" << ptrNode->key << ", ";
			cout << "data :" << ptrNode->getData().data << endl;
			return true;
		}

		while (ptrNode->nextNode != nullptr)
		{
			ptrNode = ptrNode->nextNode;

			if (ptrNode->key == key)
			{
				cout << "key :" << ptrNode->key << ", ";
				cout << "data :" << ptrNode->getData().data << endl;
				return true;
			}
			
		}
		cout << "no data" << endl;
		return false;
	}
	else
	{
		cout << "no data" << endl;
		return false;
	}

}
void linkedList :: showAll()
{
	if (!isEmpty())
	{
		Node *ptrNode = this->head;

		cout << "key :" << ptrNode->key << ", ";
		cout << "data :" << ptrNode->getData().data << endl;

		while (ptrNode->nextNode != nullptr)
		{
			ptrNode = ptrNode->nextNode;

			cout << "key :" << ptrNode->key << ", ";
			cout << "data :" << ptrNode->getData().data << endl;
		}
	}
	else
		cout << "no data" << endl;
}


/*
void linkedList::add(const int age, const int grade, const string name, int index)
{
	Node* newNode = new Node; // create newNode

	//input data to newNode
	newNode->setAge(age);
	newNode->setGrade(grade);
	newNode->setName(name);

	if (index < 1 && index > length()+1)
	{
		cout << "out of range" << endl;
		delete newNode;
	}
	else if (index == 1 && length() == 0)
	{
		root = newNode;
	}
	else if (index == (length()+1) )
	{
		Node* ptr_Node = root;

		while (ptr_Node->m_poNext != nullptr)
			ptr_Node = ptr_Node->m_poNext;

		ptr_Node->m_poNext = newNode;
	}
	else
	{
		Node* ptr_Node = root;

		if (index == 1)
		{
			newNode->m_poNext = ptr_Node;
			root = newNode;
		}
		else
		{
			while (index != 1)
			{
				ptr_Node = ptr_Node->m_poNext;
				index--;
			}

			newNode->m_poNext = ptr_Node->m_poNext;
			ptr_Node->m_poNext = newNode;
		}

	}

}
void linkedList::erase(int index)
{
	Node* del_Node = root;

	if (index == 1) // first data
	{
		root = del_Node->m_poNext;
		delete del_Node;
	}
	else if (index == length()) // last data
	{
		Node* ptr_Node = root;

		if (ptr_Node->m_poNext->m_poNext != nullptr)
			ptr_Node = ptr_Node->m_poNext;

		del_Node = ptr_Node->m_poNext;
		ptr_Node->m_poNext = del_Node->m_poNext;

		delete del_Node;
	}
	else // middle data
	{
		Node* ptr_Node = root;

		while (index != 2)
		{
			ptr_Node = ptr_Node->m_poNext;
			index--;
		}

		del_Node = ptr_Node->m_poNext;
		ptr_Node->m_poNext = del_Node->m_poNext;

		delete del_Node;
	}
}

Node linkedList::show(int index)
{
	Node* ptr_Node = root;

	if (index < 1 && index > length()+1)
	{
		cout << "out of range" << endl;
	}
	else
	{

		while (index != 1)
		{
			ptr_Node = ptr_Node->m_poNext;
			index--;
		}

	}

	return *ptr_Node;
}

int linkedList::length()
{
	int m_nLength = 0;

	if (root == nullptr)
		return m_nLength;
	else
	{
		m_nLength++;

		Node* ptr_Node = root;

		while (ptr_Node->m_poNext != nullptr)
		{
			ptr_Node = ptr_Node->m_poNext;
			m_nLength++;
		}

		return m_nLength;
	}

}
*/