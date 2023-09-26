/*
Done by Mhd Taha Daboul
Date : 8/17/2023
*/


#include <string>
#include <iostream>
#include <queue>
using namespace std;

template <class T>
class stack
{
private:
    //Creating stack using linked list
    struct node
    {
        T element;
        node* next=NULL;
        node* pre=NULL;
    };
    node* top;
    node* head;
    int length;
    //Function for putting stack elements into a queue for reversing using recursion
    void copyToReverse(queue<T>& obj,node* ptr)
    {        
        if (top != NULL)
        {
            obj.push(getTop());
            pop();
            copyToReverse(obj, ptr);
        }
    }
    //Function for put the queue element in a stack using FIFO and then the stack will be reverse using recursion
    void insertToReverse(queue<T>& obj, node* ptr)
    {
        if (!obj.empty())
        {
            push(obj.front());
            obj.pop();
            insertToReverse(obj, ptr);
        }
    }

public:
    stack()
    {
        top = NULL;
        head = NULL;
    }

    bool isEmpty()
    {
        return top == NULL;
    }

    //Adding element in the top of the stack
    void push(T element)
    {
        node* newNode = new node;
        newNode->element = element;
        if (isEmpty())
        {
            head = newNode;
            top = head;
            length++;
        }
        else if (length==1)
        {
            head->next = newNode;
            top = newNode;
            top->pre = head;
            length++;
        }
        else
        {
            newNode->pre = top;
            top = newNode;
            top->next = NULL;
            length++;
        }
        
    }
    //Removing element from the top of stack
    void pop()
    {
        if (isEmpty())
        {
            cout << "The stack is empty you can't pop from it\n";
        }
        node* temp = top;
        top = top->pre;
        length--;
        delete temp;
    }
    //Return the last element
    T getTop()
    {
        return top->element;
    }

    void reverseStack()
    {
        if (isEmpty())
        {
            cout << "You can't reverse empty stack - _ - \n";
        }
        queue<T> ob;
        copyToReverse(ob, top);
        insertToReverse(ob, top);
    }
    
    void removeFromMid()
    {
        if (isEmpty())
        {
            cout << "There is no element in the stack ya azizi\n";
            return;
        }
        stack obj;
        for (size_t i = 0; i < (length / 2)+1; i++)
        {
            obj.push(getTop());
            pop();
        }
        obj.pop();
        while (!obj.isEmpty())
        {
            push(obj.getTop());
            obj.pop();
        }
        
    }

    int getSize()
    {
        return length;
    }
};

int main()
{
    std::cout << "Hello World!\n";
    //Problem 1
    stack<int> ob;
    ob.push(5);
    ob.push(4);
    ob.push(3);
    ob.push(2);
    ob.push(1);
    //Problem 2
    cout <<"The top before reversing: " << ob.getTop() << endl;
    ob.reverseStack();
    cout <<"The top after reversing: " << ob.getTop() << endl;
    //Problem 3
    cout << "The size before removing from mid: " << ob.getSize() << endl;
    ob.removeFromMid();
    cout <<"The size after removing from mid: " << ob.getSize() << endl;
    //Problem 1
    ob.pop();
    cout << "The size after removing element: " << ob.getSize() << endl;
    

  
}
