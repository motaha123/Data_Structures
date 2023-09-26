/*
Author : Mhd Taha Daboul
Date : 16/7/2023
*/

#include <iostream>

using namespace std;

template <class T>
void mergeAsc(T arr[], int left, int right,int mid) 
{
    /*
    left = first index in first array, 
    mid last index in first array, 
    right last element in second array
    */
    int i=0, j=0,k=0;
    int n1 = mid-left + 1;//Size for first array
    int n2 = right - mid ;//Size for second array
    int* arrLeft = new int[n1];
    int* arrRight = new int[n2];
    
    for (i = 0; i < n1; i++)
        arrLeft[i] = arr[left + i];
    
    for (j = 0; j < n2; j++)
        arrRight[j] = arr[mid + 1 + j];


    i = j = 0;
    k = left;

    while (i<n1&&j<n2)
    {
        if (arrLeft[i] >= arrRight[j])//Comparing between two array's 
        {
            arr[k] = arrRight[j];
            k++;
            j++;
        }
        else
        {
            arr[k] = arrLeft[i];
            k++;
            i++;
        }
    }
    while (i<n1)//if one of the two array end fill the original one with the second array 
    {
        arr[k] = arrLeft[i];
        k++;
        i++;
    }
    while (j<n2)
    {
        arr[k] = arrRight[j];
        k++;
        j++;
    }
}

template <class T>
void mergeSortAsc(T arr[], int left, int right)
{
    if (left<right)
    {
        int mid = left + (right - left) / 2;//Counting the mid point
        mergeSortAsc(arr, left, mid);//Do it for each side
        mergeSortAsc(arr, mid + 1, right);
        mergeAsc(arr, left, right, mid);//After merging do the sorting 
    }
}


template <class T>
void mergeDsc(T arr[], int left, int right, int mid)
{
    int i = 0, j = 0, k = 0;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int* arrLeft = new int[n1];
    int* arrRight = new int[n2];

    for (i = 0; i < n1; i++)
        arrLeft[i] = arr[left + i];

    for (j = 0; j < n2; j++)
        arrRight[j] = arr[mid + 1 + j];


    i = j = 0;
    k = left;

    while (i < n1 && j < n2)
    {
        if (arrLeft[i] <= arrRight[j])
        {
            arr[k] = arrRight[j];
            k++;
            j++;
        }
        else
        {
            arr[k] = arrLeft[i];
            k++;
            i++;
        }
    }
    while (i < n1)
    {
        arr[k] = arrLeft[i];
        k++;
        i++;
    }
    while (j < n2)
    {
        arr[k] = arrRight[j];
        k++;
        j++;
    }
}

template <class T>
void mergeSortDsc(T arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSortDsc(arr, left, mid);
        mergeSortDsc(arr, mid + 1, right);
        mergeDsc(arr, left, right, mid);
    }
}

template <class T>
void print(T arr[],int length)
{
    cout << "[ ";
    for (size_t i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "] " << endl;
}


int main()
{
    std::cout << "Hello World!\n";
    int arr[7] = { 3,1,2,7,6,4,5 };
    mergeSortAsc(arr, 0, 6);
    print(arr,7);
    mergeSortDsc(arr, 0, 6);
    print(arr, 7);
}
