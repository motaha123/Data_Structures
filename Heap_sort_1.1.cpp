#include <iostream>
#include <algorithm>

using namespace std;

void heapify(int arr[], int index, int size)
{
    int leftChild = 2 * index +1;//Position of left child for the index
    int rightChild = 2 * index +2;//Position of right child for the index
    int max = index;//Varible to store the biggest number between childern and father
    if (leftChild<size&&arr[leftChild]>arr[max])
    {
        max = leftChild;
    }
    if (rightChild<size&&arr[rightChild]>arr[max])
    {
        max = rightChild;
    }
    if (max!=index)//If the max not = the father
    {
        swap(arr[index], arr[max]);//Make it = Father
        heapify(arr, max, size);//Do the process with childern
    }
}


void buildHeap(int arr[], int size)
{
    int i = size / 2 - 1;//Loop and do heapify function for each level
    while (i>=0)
    {
        heapify(arr, i, size);
        i--;
    }
}



void heapSort(int arr[], int size)
{
    buildHeap(arr, size);
    int i = size - 1;
    while (i>=0)
    {
        swap(arr[0], arr[i]);//Put the last element in the first element  
        heapify(arr, 0, i);
        i--;
    }
}

void print(int arr[], int size)
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
    int arr[5] = { 3,2,3,1,100 };
    heapSort(arr, 5);
    print(arr,5);
}