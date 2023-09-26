/*
Author : Mhd Taha Daboul
Date : 21/6/2023
*/
#include <iostream>
#include <string>

using namespace std;

template <class T>
class Stack
{
public:
	Stack()
	{
		top = NULL;
	}
	void push(T newelement)
	{

		node* newelementptr = new node;//Creating obj from node
		if (newelementptr == NULL)
		{
			cout << "There is a problem";
		}
		else
		{
			newelementptr->element = newelement; //storing value inside the element
			newelementptr->next = top; //pointing on the previous element
			top = newelementptr; //letting the top pointing on the new element 
		}

	}
	bool isEmpty()//chacking if the stack is empty
	{
		return top == NULL;
	}
	void pop(T& num)
	{
		if (isEmpty())
		{
			cout << "The stack has no element sorry\n";
		}
		else
		{
			node* temp;//Creating obj from node
			temp = top;//letting temp pointing on top to avoid lack on mamory
			num = top->element;//saving element before you delete it 
			top = top->next;//letteing top pointing on next element
			temp = temp->next = NULL;// deleting element

		}

	}

	void print()
	{
		if (isEmpty())
		{
			cout << "The stack has no element sorry\n";
		}
		current = top;//avoid losing data because if we use top we are gonna lose our data 
		cout << "[ ";
		while (current != NULL)//printing the element
		{
			cout << current->element << " ";
			current = current->next;
		}
		cout << " ] " << endl;
	}

	~Stack()
	{
		delete top;
		top = nullptr;
		delete current;
		current = nullptr;
		cout << "Done";
	}

private:
	struct node //Structure of element
	{
		T element; //Storing the value of element
		node* next;  //point on the next element for linking
	};
	node* top; //pointing on specific node
	node* current; //usefull in printing
};



int main()
{
	Stack<int> ob;
	ob.push(5);
	ob.push(10);
	ob.push(15);
	ob.push(20);
	ob.print();
	int x = 0;
	ob.pop(x);
	cout << x << endl;
	ob.print();
}