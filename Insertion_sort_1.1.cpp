/*
Author : Mhd Taha Daboul
Date:16/7/2023
*/

#include <iostream>

using namespace std;

template<class T>
void insertionSortAsc(T arr[], int size)
{
    int current = 0,j=0;
	for (size_t i = 1; i < size; i++)
	{
		current = arr[i];//Current number
		j = i - 1;//Number for looping until we find the right place for current

		while (j>=0&&arr[j]>current)//Loop for shifting
		{
			arr[j + 1] = arr[j];
			j--;
		}

		
			arr[j+1] = current;//Put current in the right place
	}
}


template <class T>
void insertionSortDsc(T arr[], int size)
{
	int current = 0, j = 0;
	for (size_t i = 1; i < size; i++)
	{
		current = arr[i];//Current number
		j = i - 1;//Number for looping until we find the right place for current

		while (j >= 0 && arr[j] < current)//Loop for shifting
		{
			arr[j + 1] = arr[j];
			j--;
		}

		if (j == i - 1)
		{
			continue;
		}
		else
		{
			arr[j + 1] = current;//Put current in the right place
		}
	}
}

template<class T>
void print(T arr[], int size)
{
	cout << "[ ";
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << " ]" << endl;
}

int main()
{
    std::cout << "Hello World!\n";
	
	int arr[7] = { 2,4,1,3,5,8,6 };
	int size = sizeof(arr) / sizeof(arr[0]);

	insertionSortAsc(arr,size);

	print(arr,size);

	insertionSortDsc(arr, size);

	print(arr, size);
}

