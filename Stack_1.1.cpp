/*
Author : Mhd Taha Daboul
Date : 20/6/2023 
*/
#include <iostream>
#include <string>
#include <queue>
using namespace std;


template <class T>
class Stack //Our structure
{
public:
	Stack()
	{
		top = 0;
		arr = new T[100];
		size = 0;
	}
	bool isEmpty()//Checking if the stack has any elements 
	{
		if (top==-1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void push(T num)// adding element to our stack
	{
		top++;
		arr[top] = num;
		size++;
	}
	void pop()// deleting element from our stack
	{
		if (isEmpty())
		{
			cout << "Sorry the stack dosn't have any element\n";
		}
		else
		{
			top--;
			size--;
		}
	}
	T returnTop()//return our top
	{
		if (isEmpty())
		{
			cout << "Sorry the stack dosn't have any element\n";
		}
		else
		{
			return arr[top];
		}
	}
	void print()//printing element
	{
		if (isEmpty())
		{
			cout << "Sorry the stack dosn't have any element\n";
		}
		else
		{
			cout << "[ ";
			for (int i = top; i > 0; i--)
			{
				if (i==0)
				{
					cout << arr[i] << " ";
					break;
				}
				cout << arr[i]<<" , ";
				
			}
			cout << "]" << endl;
		}
	}
	~Stack()// deleting dynamic array and saving memory | - _ - |
	{
		delete arr;
		arr = nullptr;
		cout << "Done \n";
	}
	void copyToReverse(queue<T>& obj)
	{
		if (top != NULL)
		{
			obj.push(returnTop());
			pop();
			copyToReverse(obj);
		}
	}
	//Function for put the queue element in a stack using FIFO and then the stack will be reverse using recursion
	void insertToReverse(queue<T>& obj)
	{
		if (!obj.empty())
		{
			push(obj.front());
			obj.pop();
			insertToReverse(obj);
		}
	}

	void reverseStack()
	{
		queue<T> ob;
		copyToReverse(ob);
		insertToReverse(ob);
	}

	void removeMid()
	{
		Stack obj;
		for (size_t i = 0; i < (size / 2)+1 ; i++)
		{
			obj.push(returnTop());
			pop();
		}
		obj.pop();
		for (size_t i = 0; i < (size/2); i++)
		{
			push(obj.returnTop());
			obj.pop();
		}
			
		

	}

	
private:
	T* arr;
	int top;
	int size;
};





int main()
{
    std::cout << "Hello World!\n";
	Stack<int> s;
	s.push(5);
	s.push(10);
	s.push(15);
	s.push(20);
	s.print();
	s.pop();
	s.print();
	s.reverseStack();
	s.print();
	s.push(100);
	s.print();
	s.removeMid();
	s.print();
	
}
