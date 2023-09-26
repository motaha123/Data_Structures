/*
Author : Mhd Taha Daboul 
Date : 13/7/2023 
*/

#include <iostream>
#include <algorithm>

using namespace std;


template<class T>
void selectionSortingAsc(T arr[], int size)
{
	
	int index = 0;
	for (size_t i = 0; i < size; i++)
	{
		index = i;
		for (size_t j = (i + 1); j < size; j++)
		{
			if (arr[j]<=arr[index])
			{	
				index = j;
			}
		}
		swap(arr[i], arr[index]);
	}
}


template<class T>
void selectionSortingDec(T arr[], int size)
{

	int index = 0;
	for (size_t i = 0; i < size; i++)
	{
		index = i;
		for (size_t j = (i + 1); j < size; j++)
		{
			if (arr[j] >= arr[index])
			{
				index = j;
			}
		}
		swap(arr[i], arr[index]);
	}
}

template <class T>
void print(T arr[], int size)
{
	cout << "[ ";
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << " ] " << endl;
}


int main()
{
    std::cout << "Hello World!\n";
	int arr[5] = { 3,2,4,1,5 };
	int size = sizeof(arr) / sizeof(arr[0]);//culecting the size
	selectionSortingAsc(arr, size);
	print(arr,size);
	selectionSortingDec(arr, size);
	print(arr, size);
}

