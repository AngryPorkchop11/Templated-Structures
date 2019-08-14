#pragma once
#include <cassert>

using namespace std;

template<class T>
class SinglyLinkedList
{
public:
	void print()
	{
		Node* ptr = _head;
		cout << "[";
		while (ptr)
		{
			cout << ptr->data;
			ptr = ptr->next;
			if (ptr != NULL)
				cout << ",";
		}
		cout << "]\n";
		cout << "SIZE: " << GetSize() << endl;
	}
	//Constructor
	SinglyLinkedList()
	{
		_head = NULL;
		_size = 0;
	}
	//Returns first link
	T Peek()
	{
		if (_size == 0)
			exit(1);
		return _head->data;
	}

	unsigned int GetSize()
	{
		return _size;
	}
	//Add item at back in O(N) time
	bool AppendItem(T t)
	{
		//Alocate a new node and fill data w/ current object
		Node* ptrNew = new Node;
		ptrNew->data = t;

		//If the list is empty
		if (_size == 0)
		{
			_head = ptrNew;
			_head->next = NULL;
			_size++;
			return true;
		}

		Node* ptr = _head;
		Node* run = _head;
		while (ptr)
		{
			run = ptr;
			ptr = ptr->next;
		}
		//Insert at end
		ptrNew->next = NULL;
		run->next = ptrNew;
		_size++;
		return true;
	}
	//Add item at top
	bool PrependItem(T t)
	{
		Node* ptrNew = new Node;
		ptrNew->data = t;
		//If empty list
		if (_size == 0)
		{
			_head = ptrNew;
			_head->next = NULL;
			_size++;
			return true;
		}
		//Insert at beginning of list
		ptrNew->next = _head;
		_head = ptrNew;
		_size++;
		return true;
	}
	//Delete from top
	T DeleteItem()
	{
		Node* ptr = _head;
		Node* run = _head;
		// Check for empty list
		if (_size == 0)
		{
			exit(1);
		}
		// If only one element
		else if (_size == 1)
		{
			_head = NULL;
			_size--;
			T info = ptr->data;
			delete ptr;
			return info;
		}
		// Remove from front
		else
		{
			_head = _head->next;

			_size--;
			T info = ptr->data;
			delete ptr;
			return info;
		}
	}
	//Destructor
	~SinglyLinkedList()
	{
		if (_size == 0)
			return;

		Node* ptr = _head;
		Node* run = _head;
		while (ptr)
		{
			run = ptr->next;
			delete ptr;
			ptr = run;
		}
		delete run;
	}

private:
	unsigned int _size;
	struct  Node
	{
		Node* next;
		T data;
	};
	Node* _head;
};
