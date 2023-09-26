/*
Name : Mhd Taha Daboul
Date : 26/6/2023
*/

#include <cassert>
#include <iostream>
#include <string>

using namespace std;


/*
Recycle rule is num = (num+1) % maxsize
*/

template <class T>
class queue
{
public:
	queue()//Default constructor
	{
		cout << "Welcome to the queue\n";
	}

	queue(int size)//Constractor that takes the size from user
	{
		front = 0;
		maxSize = size;
		arr = new T[maxSize];//Initializing the Queue
		rear = maxSize-1;
		length = 0;
	}
	
	bool isEmpty()
	{
		return length == 0;
	}

	bool isFull()
	{
		return length == maxSize;
	}

	void enqueue(T element)
	{
		assert(!isFull());//Function if the parameter return false it will not continue the block
		rear = (rear + 1) % maxSize;//Make the new rear index of the new element
		arr[rear] = element;
		length++;
	}

	void dequeue()
	{
		assert(!isEmpty());
		front = (front + 1) % maxSize;//Make the new front index of the new element
		length--;
	}

	T getFront()
	{
		return arr[front];
	}

	T getRear()
	{
		return arr[rear];
	}

	void printQueque()
	{
		assert(!isEmpty());
		for (size_t i = front; i != rear; )//Starting from front ending with rear walking recycle
		{
			cout << arr[i] << " ";
			i = (i + 1) % maxSize;
		}
		cout << arr[rear] << endl;
	}
	
	int search(T element)
	{
		int index = -1;
		assert(!isEmpty());
		for (size_t i = front; i != rear ; i = (i + 1) % maxSize)
		{
			if (arr[i]==element||arr[rear]==element)
			{
				index = i;
			}
			
		}
		return index;//return the index of the element if exist else return -1
	}

	~queue()//free the memory
	{
		cout << "Done";
		delete arr;
		arr = nullptr;
	}

private:
	int front;
	int rear ;
	int length;
	int maxSize ;
	T* arr;
};



int main()
{
    std::cout << "Hello World!\n";
	queue<int> q(5);
	q.enqueue(5);
	q.enqueue(10);
	q.enqueue(15);
	q.enqueue(20);
	q.printQueque();
	q.dequeue();
	q.enqueue(12);
	q.enqueue(13);
	q.printQueque();
	cout << q.getFront() << endl;
	cout << q.search(15) << endl;

}

