/////////////////////////////////////
//////////SLL CHECK///////////////
///////////////////////////////////
#include <iostream> 
#include <string>
#include "SinglyLinkedList.h"

using namespace std;

int main()
{
	int key;
	cout << "enter -1 to exit & print \n";
	cout << "Enter Number to add: ";
	cin >> key;
	cout << endl;

	SinglyLinkedList<int>* list = new SinglyLinkedList<int>();
	while (key != -1)
	{
		list->AppendItem(key);
		cout << endl;
		cout << "Enter Number to add: ";
		cin >> key;
	}
	cout << "-----------------------------------------------\n";
	cout << "List: ";
	list->print();
	return 0;
}