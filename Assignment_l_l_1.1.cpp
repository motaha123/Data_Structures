#include <iostream>
using namespace std;

template <class T>
class Node {
private:
    T Info;
    Node *Next;

public:
    Node(T info, Node *n =0)
    {
        Info=info;
        Next=n;
    }

    Node* getNext() {
        return Next;
    }

    void setNext(Node *n) {
        Next = n;
    }

    T getInfo() {
        return Info;
    }

    void setInfo(T info) {
        Info = info;
    }
};

template <class T>
class SLL {
private:
    Node<T> *head, *tail;

public:
    SLL()  { head=0, tail=0;}

    void addtoHead(T value) {
        Node<T> *newNode = new Node<T>(value, head);
        if (head == 0) {
            tail = newNode;
        }
        head = newNode;
    }

    void addtotail(T value) {
        Node<T> *newNode = new Node<T>(value);
        if (tail == 0) {
            head = tail = newNode;
        } else {
            tail->setNext(newNode);
            tail = newNode;
        }
    }

    T removeFromHead() {
        if (head == 0) {
            throw runtime_error("List is empty");
        }
        T value = head->getInfo();
        Node<T> *temp = head;
        head = head->getNext();
        if (head == 0) {
            tail = 0;
        }
        delete temp;
        return value;
    }

    T removeFromTail() {
        if (tail ==0) {
            throw runtime_error("List is empty");
        }
        T value = tail->getInfo();
        if (head == tail) {
            delete tail;
            head = tail = 0;
        } else {
            Node<T> *current = head;
            while (current->getNext() != tail) {
                current = current->getNext();
            }
            delete tail;
            tail = current;
            tail->setNext(0);
        }
        return value;
    }

    T getValueAtHead() {
        if (head == 0) {
            throw runtime_error("List is empty");
        }
        return head->getInfo();
    }

    bool isEmpty() {
        return head == 0;
    }

    void clear() {
        while (! isEmpty()) {
            Node<T> *temp = head;
            head = head->getNext();
            delete temp;
        }
        tail = 0;
    }

    friend ostream& operator<<(ostream& os, const SLL<T>& list) {
        Node<T> *current = list.head;
        while (current != 0) {
            os << current->getInfo() << " ";
            current = current->getNext();
        }
        return os;
    }

void pairwiseSwap() {
    Node<T> *current = head;
    while (current && current->getNext()) {
        T temp = current->getInfo();
        current->setInfo(current->getNext()->getInfo());
        current->getNext()->setInfo(temp);
        current = current->getNext()->getNext();
    }
}

void removeDuplicates() {
    Node<T> *current = head;
    while (current && current->getNext()) {
        if (current->getInfo() == current->getNext()->getInfo()) {
            Node<T> *temp = current->getNext();
            current->setNext(temp->getNext());
            delete temp;
        } else {
            current = current->getNext();
        }
    }
}
};


int main() {
   SLL<int> sll;
    sll.addtoHead(1);
    sll.addtotail(2);
    sll.addtotail(3);
    sll.addtotail(4);

    cout << "List: " << sll << endl;

    sll.removeFromHead();
    sll.removeFromTail();

   cout << "List after removing from head and tail: " << sll << endl;
    sll.addtoHead(1);
    sll.addtotail(4);
    sll.addtotail(5);
    sll.addtotail(6);
    sll.addtotail(NULL);

    cout << " list: " << sll << endl;

    sll.pairwiseSwap();
    cout << "Pairwise swapped list: " << sll << endl;
    SLL<int>sll1;

    sll1.addtotail(2);
    sll1.addtotail(2);
    sll1.addtotail(4);
    sll1.addtotail(5);


    cout << " list: " << sll1 << endl;
    sll1.removeDuplicates();
    cout << "List after removing duplicates: " << sll1<< endl;

    return 0;

}