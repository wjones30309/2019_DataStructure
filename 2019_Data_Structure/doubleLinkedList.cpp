#include "doubleLinkedList.h"

bool doubleLinkedList::initNode(Data data)
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
bool doubleLinkedList::frontAddNode(Data data)
{
	if (!isEmpty())
	{
		Node *newNode = new Node;
		newNode->putData(data);
		newNode->key = keyNum++;

		newNode->nextNode = this->head;
		this->head = newNode;

		newNode->preNode = this->head;

		m_length++;
		return true;
	}
	else
	{
		cout << "you have to initialize first" << endl;
		return false;
	}
}
bool doubleLinkedList::lastAddNode(Data data)
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
		newNode->preNode = ptrNode;

		m_length++;
		return true;
	}
	else
	{
		cout << "you have to initialize first" << endl;
		return false;
	}
}
bool doubleLinkedList::insertNode(Data data, int key)
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

				newNode->preNode = ptrNode->nextNode->preNode;
				newNode->nextNode = ptrNode->nextNode;

				ptrNode->nextNode->preNode = newNode;
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

bool doubleLinkedList::deleteNode(int key)
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
				ptrNode->preNode = nullptr;
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

				if (delNode->nextNode != nullptr)
				{
					delNode->nextNode->preNode = delNode->preNode;
					ptrNode->nextNode = ptrNode->nextNode->nextNode;
				}
				else
				{
					ptrNode->nextNode = nullptr;
					delNode->preNode = nullptr;
				}

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
void doubleLinkedList::deleteAll()
{
	if (!isEmpty())
	{
		Node *ptrNode = this->head;
		Node *delNode = ptrNode;



		while (ptrNode->nextNode != nullptr)
		{
			ptrNode = ptrNode->nextNode;
			delNode->nextNode = nullptr;
			ptrNode->preNode = nullptr;

			delete delNode;
			m_length--;
			delNode = ptrNode;

		}

		delete delNode;
		m_length--;
		this->head = nullptr;

	}
}

bool doubleLinkedList::changeData(Data data, int key)
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

bool doubleLinkedList::showData(int key)
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
void doubleLinkedList::showAll()
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