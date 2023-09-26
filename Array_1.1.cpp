/*
Author : Mhd Taha Daboul
Date : 2/7/2023
*/

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

template <class T>
class Array
{
public:
	Array(int size=10)
	{
		if (size < 0)
		{
			this->size = 10;
		}
		else
		{
			this->size = size;
		}
		arr = new T[size];
	}
	
	bool isFull()
	{
		return  length==size;
	}

	bool isEmpty()
	{
		return length == 0;
	}

	void insertInIndex(int index, T  element)//Replace the element of index and shift the old one
	{
		assert(!isFull());
		for (int i = length; i > index; i--)
		{
			arr[i] = arr[i - 1];
		}
		arr[index] = element;
		length++;
	}

	void insertAtEqual(int index, T element)//Adding element without shiffiting
	{
		assert(!isFull()); 
		arr[index] = element;
		length++;
	}

	bool searchForElment(T element)//Searching for element if exist or not
	{
		assert(!isEmpty());
		for (size_t i = 0; i < length; i++)
		{
			if (element==arr[i])
			{
				return true;
			}
		}
		return false;
	}

	void insertWithoutDublication(int index,T element)//Adding element without dublication in array
	{
		assert(!isFull());
		if (searchForElment(element))
		{
			cout << "Item is exist\n";
		}
		else
		{
			insertAtEqual(index, element);
		}
	}

	void removeFromArray(int index)//Removing element with shifft left for athers element
	{
		assert(!isEmpty());
		for (size_t i = index; i < length; i++)
		{
			arr[i] = arr[i + 1];
		}
		length--;
	}

	void print()
	{
		assert(!isEmpty());
		for (size_t i = 0; i < length; i++)
		{
			cout << arr[i]<<" ";
		}
		cout << endl;
	}

	~Array() //Free the memory
	{
		delete[]arr;
		arr = nullptr;
	}

private:
	T* arr;
	int size;
	int length;
};



int main()
{
    std::cout << "Hello World!\n";
	Array<int> arr(10);
	arr.insertInIndex(0, 1);
	arr.insertInIndex(1, 2);
	arr.insertInIndex(2, 3);
	arr.insertInIndex(2, 4);
	arr.print();
	arr.insertAtEqual(4, 7);
	arr.insertWithoutDublication(5, 6);
	arr.print();
	arr.removeFromArray(5);
	arr.print();
}

