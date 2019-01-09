//#include "linkedList.h"
//#include "doubleLinkedList.h"
#include "circleLinkedList.h"
#include <iostream>
#include <string>
using namespace std;

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