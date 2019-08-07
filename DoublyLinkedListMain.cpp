/////////////////////////////////////
//////////DLL CHECK///////////////
///////////////////////////////////
#include <iostream> 
#include <string>
#include "DoublyLinkedList.h"

using namespace std;

int main()
{
	int key;
	cout << "enter -1 to exit & print \n";
	cout << "Enter Number to add: ";
	cin >> key;

	DoublyLinkedList<int> *list = new DoublyLinkedList<int>();
	while (key != -1)
	{
		list->PrependItem(key);
		cout << endl;
		cout << "Enter Number to add: ";
		cin >> key;
	}
	cout << "-----------------------------------------------\n";
	cout << "List: ";
	list->print();

	cout << "HEAD = ";
	list->Peek();
	cout << endl;
	cout << "TAIL = ";
	list->PeekEnd();
	return 0;
}
