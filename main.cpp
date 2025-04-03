#include "sortedlinkedlist.h"
#include <stdexcept>
#include <iostream>
using namespace std;
Node::Node(int val) {
    data=val;
    next= nullptr;

}
sortedlinkedlist::sortedlinkedlist() {
    head = nullptr;
}

sortedlinkedlist::~sortedlinkedlist() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

void sortedlinkedlist::insert(int value) {
    Node* new_node = new Node(value);
    if (head == nullptr) {
        head = new_node;
        return;
    }
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = new_node;

    Node* sorted = nullptr;
    current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;

        if (sorted == nullptr || sorted->data >= current->data) {
            current->next = sorted;
            sorted = current;
        } else {
            Node* temp = sorted;
            while (temp->next != nullptr && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }

        current = nextNode;
    }


    head = sorted;
}

void sortedlinkedlist::remove(int index) {
    if (head == nullptr || index < 0) {
        return;
    }
    if (index == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    for (int i = 0; i < index - 1; ++i) {
        if (current->next == nullptr) {
            return;
        }
        current = current->next;
    }

    if (current->next == nullptr) {
        return;
    }

    Node* temp = current->next;
    current->next = current->next->next;
    delete temp;
}

int sortedlinkedlist::operator[](int index) {
    if (index < 0) {
        throw out_of_range("Index out of bounds");
    }

    Node* current = head;
    for (int i = 0; i < index; ++i) {
        if (current == nullptr) {
            throw out_of_range("Exception Thrown,Index out of bounds");
        }
        current = current->next;
    }

    if (current == nullptr) {
        throw out_of_range("Exception Thrown,Index out of bounds");
    }
    return current->data;
}

ostream& operator<<(ostream& os, const sortedlinkedlist& list) {
    Node* ptr = list.head;
    os << "[";
    while (ptr != nullptr) {
        os << ptr->data;
        if (ptr->next != nullptr) {
            os << ", ";
        }
        ptr = ptr->next;
    }
    os << "]";
    return os;
}




int main() {
    sortedlinkedlist L;
    L.insert(5);
    L.insert(8);
    L.insert(7);
    L.insert(6);
    L.insert(6);
    cout<<L;
    cout<<endl;
    try {
        cout << L[2];
    }catch(const out_of_range&e)
    {
        cout<< e.what()<<endl;
    }
    cout<<endl;
    try{
        cout<<L[10];
    }
    catch(const out_of_range&e)
    {
        cout<<e.what()<<endl;
    }

    L.remove(0);
    cout<<L<<endl;
    L.remove(100);
    cout<<L;
    cout<<endl;
    L.remove(2);
    cout<<L;
    cout<<endl;
    L.remove(2);
    cout<<L;

    return 0;
}
