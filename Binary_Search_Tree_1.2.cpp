/*
Done by Mhd Taha Daboul 
Date : 8/14/2023
*/

#include <iostream>
#include <string>
#include <queue>

using namespace std;

template<class T>
class BinarySearch
{
private:
    //Node class
    class node {
    public:
        int element;
        node* right = NULL;
        node* left = NULL;
        node() = default;
    };

	node* root;
    int length;

    //Removing element from tree and doing the right change for saving the tree in bunary search tree shape
    void removeNode(node* ptr)
    {
        node* curr = NULL;
        node* prev = NULL;
        node* temp;

        if (isEmpty())
        {
            cout << "There's no element to delete\n";
            return;
        }
        else if (ptr->right == NULL && ptr->left == NULL)
        {
            delete ptr;
            ptr = nullptr;
            length--;
            return;
        }
        else if (ptr->left == NULL)
        {
            temp = ptr;
            ptr->right;
            length--;
            delete temp;
        }
        else if (ptr->right == NULL)
        {
            temp = ptr;
            ptr->left;
            length--;
            delete temp;
        }
        else
        {
            curr = ptr->left;
            while (curr->right != NULL)
            {
                prev = curr;
                curr = curr->right;
            }
            ptr->element = curr->element;
            if (prev != NULL)
            {
                prev->right = curr->left;
            }
            delete curr;
            curr = nullptr;
            length--;
        }
    }
    //printing using inorder tech
    void inorder(node* temp)
    {
        if (temp != NULL)
        {
            inorder(temp->left);
            cout << temp->element << endl;
            inorder(temp->right);
        }
    }
    //Searching for specific element and return it if we find it return -1 if we didn't find it
    T SearchBSt(node*, const T& element)
    {
        node* current = root;
        if (isEmpty())
        {
            return -1;
        }
        else if (root->element == element)
        {
            return root->element;
        }
        else
        {
            while (current != NULL)
            {
                if (current->element == element)
                {
                    return current->element;
                }
                else if (current->element > element)
                {
                    current = current->left;
                }
                else if (current->element < element)
                {
                    current = current->right;
                }
            }
            return -1;
        }
    }
    //Printing using Breadth first tech using queue
    void breadthFirstTraversal(node* root)
    {
        if (root == NULL) 
        {
            return;
        }

        queue<node*> q;
        q.push(root);

        while (!q.empty())
        {
            node* current = q.front();
            q.pop();

            cout << current->element << endl;

            if (current->left != NULL) {
                q.push(current->left);
            }

            if (current->right != NULL) {
                q.push(current->right);
            }
        }
    }

public:
 

	BinarySearch()
	{
		root = NULL;
	}

	bool isEmpty()
	{
		return root == NULL;
	}
    //Adding element to the tree
    void insert(T element)
    {
        node* curr = root;
        node* prev = NULL;
        node* newNode = new node;
        newNode->element = element;

        while (curr != NULL)
        {
            prev = curr;
            if (curr->element == element)
            {
                cout << "The element is already exist - _ - \n";
                return;
            }
            else if (curr->element > element)
            {
                curr = curr->left;
            }
            else if (curr->element < element)
            {
                curr = curr->right;
            }
        }

        if (prev == NULL)
        {
            root = newNode;
            length++;
        }
        else if (prev->element > element)
        {
            prev->left = newNode;
            length++;
        }
        else
        {
            prev->right = newNode;
            length++;
        }
    }

    void removeElement(T element)
    {
        node* current = NULL;
        node* previous = NULL;
        
        if (isEmpty())
        {
            cout << "There's no element to delete\n";
            return;
        }

        else if (root->element == element)
        {
            removeNode(root);
        }

        else 
        {
            current = root;

            while (current != NULL)
            {
                previous = current;
                if (current->element == element)
                {
                    removeNode(current);
                    return;
                }
                else if (current->element > element)
                {
                    current = current->left;
                }
                else if (current->element < element)
                {
                    current = current->right;
                }
            }

            if (previous->left==NULL)
            {
                cout << "The element not found ya azizi\n";
                return;
            }
            else if(previous->left->element == element)
            {
                removeNode(previous->left);
                return;
            }
            else if(previous->right->element == element)
            {
                removeNode(previous->right);
                return;
            }
        }


    }

    int getSize()
    {
        return length;
    }

    void inorderPrinting()
    {
        inorder(root);
    }
    //Finding the smallest element and return it
    T getMinimumElement()
    {
        node* current = root;
        node* previous = NULL;
        if (isEmpty())
        {
            cout << "The Tree has no element ya azizi" << endl;
            return -1;
        }
        
        else if (length==1)
        {
            return root->element;
        }
        
        else 
        {
            while (current!=NULL)
            {
                previous = current;
                current = current->left;
            }
            return previous->element;
        }
    }

    T SearchNode(const T& element)
    {
        return SearchBSt(root, element);
    }

    void bFTraverse()
    {
       breadthFirstTraversal(root);
    }
    
};



int main()
{
    std::cout << "Hello World!\n";
	BinarySearch<int> ob;
	ob.insert(19);
	ob.insert(24);
    ob.insert(9);
    ob.insert(29);
    ob.insert(11);
    ob.insert(4);
    ob.insert(20);
    cout << "The size after adding element: " << ob.getSize() << endl;
    cout << "Printing element using inorder: " << endl;
    cout << "=============" << endl;
    ob.inorderPrinting();
    cout << "=============" << endl;
    cout <<"The Smallest element is: " << ob.getMinimumElement() << endl;
    cout <<"The element: " << ob.SearchNode(11) <<" has been found" << endl;
    cout << "Printing elements using breadth first : \n";
    cout << "=============" << endl;
    ob.bFTraverse();
    cout << "=============" << endl;
    ob.removeElement(20);
    cout << "The size after we delete an element: " << ob.getSize() << endl;
}


