/*
Author : Mhd Taha Daboul
Date : 5/7/2023
*/

#include <cassert>
#include <iostream>
#include <string>

using namespace std;

template<class T>
class Doubly_list
{
private:
	struct node
	{
		T element;
		node* previous;
		node* next;
	};
	
	node* head;
	node* tail;
	int length;

public:
	Doubly_list()
	{
		length = 0;
		head = tail = nullptr;
	}

	bool isEmpty()
	{
		return length == 0;
	}

	void insertAtHead(T element)
	{
		node* newelement=new node;
		newelement->element = element;
		if (isEmpty())
		{
			head = tail = newelement;
			head->next = NULL;
			head->previous = NULL;
			tail = head;
		}
		else 
		{
			head->previous = newelement;
			newelement->next=head;
			head = newelement;
			head->previous = NULL;
		}
		length++;
	}

	void print()
	{
		node* current=head;
		cout << "[ ";
		while (current!=NULL)
		{
			cout << current->element<<" ";
			current = current->next;
		}
		cout << " ]" << endl;
	}

	void insertAtTail(T element)
	{
		node* newelement = new node;
		newelement->element = element;
		if (isEmpty())
		{
			insertAtHead(element);
		}
		else
		{
			tail->next = newelement;
			newelement->previous = tail;
			tail=newelement;
			tail->next = NULL;
			length++;
		}
	}

	void insertAtPosition(int index, T element)
	{
		node* newelement=new node;
		newelement->element=element;
		if (index<0||index>length)
		{
			cout << "Wrong index\n";
		}
		else if (index==0)
		{
			insertAtHead(element);
		}
		else if (index==length)
		{
			insertAtTail(element);
		}
		else
		{
			node* current=head;
			while ((index-1)!=-1)
			{
				current=current->next;
				index--;
			}
			newelement->next = current->next;
			newelement->previous = current;
			current->next->previous = newelement;
			current->next = newelement;
			length++;
		}
	}

	void removeHead() 
	{
		node* temp = head;
		head=head->next;
		head->previous = nullptr;
		temp = NULL;
		delete temp;
		temp = nullptr;
		length--;
	}

	void removeTail()
	{
		node* temp = tail;
		tail = tail->previous;
		temp = NULL;
		tail->next = NULL;
		delete temp;
		temp = nullptr;
		length--;
	}

	void removeIndex(int index)
	{
		if (index<0||index>length-1)
		{
			cout << "Wrong index\n";
		}
		else if (index==0)
		{
			removeHead();
		}
		else if (index==length-1)
		{
			removeTail();
		}
		else
		{
			node* current = head->next;
			for (size_t i = 0; i < index-1; i++)
			{
				current = current->next;
			}
			current->next->previous = current->previous;
			current->previous->next = current->next;
			current = NULL;
			delete current;
			current = nullptr;
		}
	}

	void printReverse()
	{
		node* current = tail;
		cout << "[ ";
		while (current != NULL)
		{
			cout << current->element << " ";
			current = current->previous;
		}
		cout << " ]" << endl;
	}

	~Doubly_list()
	{
		while (head!=NULL)
		{
			head = head->next;
			head = NULL;
		}
		delete head;
		head = nullptr;
		delete tail;
		tail = nullptr;
		cout << "Done";
	}

};



int main()
{
    std::cout << "Hello World!\n";
	Doubly_list<int> list;
	list.insertAtHead(2);
	list.insertAtHead(5);
	list.insertAtHead(7);
	list.insertAtTail(9);
	list.print();
	list.insertAtPosition(4,1);
	list.insertAtPosition(0,3);
	list.insertAtPosition(2, 4);
	list.print();
	list.removeHead();
	list.print();
	list.removeTail();
	list.print();
	list.removeIndex(2);
	list.print();
	list.printReverse();
}


