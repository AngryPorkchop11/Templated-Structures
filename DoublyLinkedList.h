#pragma once
#include <cassert>

using namespace std;

template<class T>
class DoublyLinkedList
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
	DoublyLinkedList() 
	{
		_head = NULL;
		_tail = NULL;
		_size = 0;
	}
//Returns first link
	T Peek()
	{
		if (_size == 0)
			exit(1);
		 cout << _head->data;
	}

	T PeekEnd()
	{
		if (_size == 0)
			exit(1);
		cout << _tail->data;
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
			_tail = ptrNew;

			_tail->next = NULL;
			_tail->prev = NULL;

			_head->next = NULL;
			_head->prev = NULL;
			_size++;
			return true;
		}

		Node *ptr = _head;
		Node *run = _head;
		while (ptr)
		{
			run = ptr;
			ptr = ptr->next;
		}
		//Insert at end
		ptrNew->prev = run;
		ptrNew->next = NULL;
		run->next = ptrNew;
		_tail = ptrNew;
		_size++;
		return true;
	}
//Add item at back in O(1) time
	void AppendItemO1(T t)
	{
		Node* ptrNew = new Node;
		ptrNew->data = t;

		//If the list is empty
		if (_size == 0)
		{
			_head = ptrNew;
			_tail = ptrNew;

			_tail->next = NULL;
			_tail->prev = NULL;

			_head->next = NULL;
			_head->prev = NULL;

			_size++;
			return;
		}
		//Insert at end O(1)
		ptrNew->prev = _tail;
		_tail->next = ptrNew;
		ptrNew->next = NULL;
		_tail = ptrNew;
		_size++;
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
			_tail = ptrNew;
			_tail->next = NULL;
			_tail->prev = NULL;

			_head->next = NULL;
			_head->prev = NULL;
			_size++;
			return true;
		}
		//Insert at beginning of list
		ptrNew->next = _head;
		ptrNew->prev = NULL;
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
			_tail = NULL;
			_size--;
			T info = ptr->data;
			delete ptr;
			return info;
		}
		// Remove from front
		else
		{
			_head->next->prev = NULL;
			_head = _head->next;

			_size--;
			T info = ptr->data;
			delete ptr;
			return info;
		}
	}
//Destructor
	~DoublyLinkedList()
	{
		if (_size == 0)
			return;
		
		Node *ptr = _head;
		Node *run = _head;
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
		Node* prev;
		int data;
	};
	Node* _head;
	Node* _tail;
};
