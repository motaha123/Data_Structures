/*
Author : Mhd Taha Daboul
Date : 17/7/2023
*/

#include <iostream>
#include <algorithm>

using namespace std;

template <class T>
int partitioning(T arr[], int small,int heigh)
{
    int pivot = arr[small];//Number for starting sorting 
    int i = small, j = heigh;

    while (i<j)
    {
        while (arr[i] <= pivot)//Increase i until you find number bigger than pivot
        {
            i++;
        }
        while (arr[j]>pivot)//Decrease i until you find number smaller than pivot
        {
            j--;
        }
        if (i<j)
        {
            swap(arr[i], arr[j]);//Swap between the smaller number comparing with pivot and bigger one
        }
    }
    swap(arr[j], arr[small]);//Put the pivot in the right place
    return j;
}

template <class T>
void quickSort(T arr[], int small, int heigh)
{
    if (small < heigh)
    {
        int pivot = partitioning(arr, small, heigh);//Get the pivot from function that break the array todeal with  
        quickSort(arr, small, pivot);
        quickSort(arr, pivot + 1, heigh);
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
    cout << "]" << endl;
}

int main()
{
    std::cout << "Hello World!\n";
    int arr[6] = { 2,-10,-22,24,11,0 };
    quickSort(arr, 0, 5);
    print(arr, 6);
}