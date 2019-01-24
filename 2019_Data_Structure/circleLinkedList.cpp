#include "circleLinkedList.h"


bool circleLinkedList::initNode(Data data)
{
	if (isEmpty())
	{
		Node *newNode = new Node;
		newNode->putData(data);
		newNode->key = keyNum++;

		this->head = newNode;
		newNode->nextNode = this->head; // 추가된점

		m_length++;
		return true;
	}
	else
	{
		cout << "already initialization is done" << endl;
		return false;
	}

}
bool circleLinkedList::frontAddNode(Data data)
{
	if (!isEmpty())
	{
		Node *newNode = new Node;
		newNode->putData(data);
		newNode->key = keyNum++;

		Node *ptrNode = this->head;
		while (ptrNode->nextNode != this->head)
			ptrNode = ptrNode->nextNode;

		newNode->nextNode = this->head;
		ptrNode->nextNode = newNode;
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
bool circleLinkedList::lastAddNode(Data data)
{
	if (!isEmpty())
	{
		Node *ptrNode = this->head;
		while (ptrNode->nextNode != this->head)
			ptrNode = ptrNode->nextNode;

		Node *newNode = new Node;
		newNode->putData(data);
		newNode->key = keyNum++;

		ptrNode->nextNode = newNode;
		newNode->nextNode = this->head; // 추가한 점

		m_length++;
		return true;
	}
	else
	{
		cout << "you have to initialize first" << endl;
		return false;
	}
}
bool circleLinkedList::insertNode(Data data, int key)
{

	if (!isEmpty())
	{
		Node *ptrNode = this->head;

		while (ptrNode->nextNode != this->head)
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

bool circleLinkedList::deleteNode(int key)
{
	if (!isEmpty())
	{
		Node *ptrNode = this->head;
		Node *delNode;
		if (ptrNode->key == key)
		{
			//변경된 부분
			//link the last node to head
			Node *ptrLastNode2 = this->head;

			while (ptrLastNode2->nextNode != this->head)
				ptrLastNode2 = ptrLastNode2->nextNode;

			ptrLastNode2->nextNode = ptrNode->nextNode;

			if (ptrNode->nextNode != this->head)
				this->head = ptrNode->nextNode;
			else
				this->head = nullptr;

			delete ptrNode;

			m_length--;
			return true;

		}

		while (ptrNode->nextNode != this->head)
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
void circleLinkedList::deleteAll()
{
	if (!isEmpty())
	{
		Node *ptrNode = this->head;
		Node *delNode = ptrNode;



		while (ptrNode->nextNode != this->head)
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

bool circleLinkedList::changeData(Data data, int key)
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

		while (ptrNode->nextNode != this->head)
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

bool circleLinkedList::showData(int key)
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

		while (ptrNode->nextNode != this->head)
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
void circleLinkedList::showAll()
{
	if (!isEmpty())
	{
		Node *ptrNode = this->head;

		cout << "key :" << ptrNode->key << ", ";
		cout << "data :" << ptrNode->getData().data << endl;

		while (ptrNode->nextNode != this->head)
		{
			ptrNode = ptrNode->nextNode;

			cout << "key :" << ptrNode->key << ", ";
			cout << "data :" << ptrNode->getData().data << endl;
		}
	}
	else
		cout << "no data" << endl;
}
