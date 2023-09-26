/*
Author : Mhd Taha Daboul
Date : 3/7/2023
*/

#include <string>
#include <iostream>
#include <cassert>

using namespace std;


template <class T>
class linkedList
{
private:
	struct node
	{
		T element;
		node* next;
	};
	node* head;
	node* tail;
	int length;

public:
	linkedList()
	{
		length = 0;
		head = NULL;
		tail = NULL;
	}

	void addElement(T element)
	{
		node* newElement = new node;
		newElement->element = element;

		if (length == 0) {
			head = tail = newElement;//Tail and head are pointing in the same address
			newElement->next = NULL;
		}
		else
		{
			tail->next = newElement;//Letting the tail = new element
			newElement->next = NULL;
			tail = newElement;
		}
		length++;
	}

	void addAtPosition(int index, T element)
	{
		node* newElement = new node;
		if (length==0||index==length)
		{
			addElement(element);
		}
		else
		{
			newElement->element = element;
			node* current = head;//Defining new pointer for looping until it find the index 
			for (size_t i = 0; i < (index-1); i++)
			{
				current=current->next;
			}
			newElement->next = current->next;//Letting the current = new element
			current->next = newElement;
		}
		length++;
	}

	bool isEmpty()
	{
		return length == 0;
	}

	void print()
	{
		assert(!isEmpty());
		node* current = head;
		cout << "[ ";
		while (current!=NULL)
		{
			cout << current->element<<" ";
			current = current->next;
		}
		cout << " ] " << endl;
	}
	
	void removeHead()
	{
		assert(!isEmpty());
		if (length==1)
		{
			tail = nullptr;
			head = nullptr;//Tail = null -> mean delete all element int the list
		}
		else
		{
			node* temp = head;//Temp pointer pointing the same head address to avoid lack in memory
			head = head->next;
			temp->next = NULL;
			delete temp;
			temp = nullptr;
			length--;
		}
		
	}

	void removeTail()
	{
		assert(!isEmpty());
		if (length==1)
		{
			head=tail=nullptr;
		}
		else
		{
			/*
			1- Current will loop until reaching the tail to avoid lack in memory
			2- tail will be delete
			3- tail = current
			4- delete the current * _ *
			*/
			node* current = head;
			while (current->next!=tail)
			{
				current = current->next;
			}
			delete tail;
			current->next = NULL;
			tail = current;
		}
		length--;
	}

	void removeAtPosition(int index)
	{
		assert(!isEmpty());
		if (index > length||index<0)
		{
			cout << "The index is out of range\n";
		}
		else
		{
			/*
			Like the previous one but we will not touch the tail
			*/
			node* current = head;
			node* previous = head;
			for (size_t i = 0; i < index; i++)
			{
				current = current->next;
				if (i==index)
				{
					break;
				}
				else if (i==0)
				{
					continue;
				}
				else
				{
					previous = previous->next;
				}
			}
			previous->next = current->next;
			delete current;
			current = nullptr;

		}
	}

	void reverse()
	{
		node* current;
		node* previous;
		node* next;
		previous = NULL;//Previous at index 0 will be null
		current = head;//Current at index 0 will be = head 
		next = current->next;//Next from it's name
		/*
		Every loop Current ->, next->next->next, previous->current, current->next = previous
		for reversing
		*/
		while (next!=NULL)
		{
			next = current->next;
			current->next = previous;
			previous = current;
			current = next;

		}
		head = previous;//Head will be the previous
	}

	int search(T element)
	{
		int position = 0;
		node* current = head;
		while (current!=NULL)
		{
			if (element==current->element)
			{
				return position;
			}
			else
			{
				position++;
				current = current->next;
			}
		}
		return -1;
	}

	~linkedList()
	{
		delete head;
		head = nullptr;
		delete tail;
		tail = nullptr;
	}
};



int main()
{
    std::cout << "Hello World!\n";
	linkedList<int> list;
	list.addElement(10);
	list.addElement(20);
	list.addElement(30);
	list.addAtPosition(3, 40);
	list.addAtPosition(2, 50);
	list.print();
	list.removeHead();
	list.print();
	list.removeTail();
	list.print();
	list.removeAtPosition(1);
	list.print();
	list.addElement(200);
	list.addElement(300);
	list.print();
	list.reverse();
	list.print();
	list.reverse();
	list.print();
	cout<<list.search(200)<<endl;
}
