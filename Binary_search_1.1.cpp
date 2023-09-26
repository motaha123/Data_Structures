/*
Author : Mhd Taha Daboul
Date : 18/7/2023
*/
#include <iostream>
#include<algorithm>
#include "Sorting.h"

using namespace std;

int binarySearchRec(int arr[], int l, int h, int element)
{
	if (h >= l) {
		int mid = (l + h) / 2;//Calculate the mid of the array

		if (arr[mid] == element)//If it's the mid return it else
			return mid; 

		if (arr[mid] > element)//Else breake the array to two sides
			return binarySearchRec(arr, l, mid - 1, element);

		return binarySearchRec(arr, mid + 1, h, element);
	}
	return -1;
}

void printTheNumebr(int num, int arr[])
{
	if (num > 0)
	{
		cout << "The number " << arr[num] << " has found at index " << num << endl;
	}
	else
	{
		cout << "The number  has not found " << endl;
	}
}


int main()
{
    std::cout << "Hello World!\n";
	int num = 0;
	int array1[] = { 3,2,4,1,5 };
	cout << "Enter the number to find: ";
	cin >> num;
	heapSort(array1,5);//Function to sort the array
	num=binarySearchRec(array1, 0, 4, num);

	printTheNumebr(num,array1);

}
