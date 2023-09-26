/*
Author : Mhd Taha Daboul 
Date : 18/7/2023
*/

#include <iostream>

using namespace std;

int linearSearch(int arr[], int size, int num)
{
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] == num)
		{
			return i;
		}
	}
	return -1;
}


void printTheNumebr(int num,int arr[])
{
	if (num > 0)
	{
		cout << "The number " << arr[num] << " has found at index " << num << endl;
	}
	else
	{
		cout << "The number  has not found "<<endl;
	}
}

int main()
{
    std::cout << "Hello World!\n";
	int size=0,num=0;
	cout << "Please enter your size: ";
	cin >> size;
	int arr[100];
	for (size_t i = 0; i <size ; i++)
	{
		cin >> arr[i];
	}
	cout << "Enter the number that you search for ";
	cin >> num;
	num = linearSearch(arr, size, num);
	printTheNumebr(num, arr);
}
