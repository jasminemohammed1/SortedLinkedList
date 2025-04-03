#ifndef SORTEDLINKEDLIST_H
#define SORTEDLINKEDLIST_H
#include<iostream>
using namespace std;
class Node{
public:
     Node* next;
    int data;
    Node(int val);

};
class sortedlinkedlist{
private:
    Node* head;
public:
    sortedlinkedlist();
    void insert(int value);
    void remove(int index);

    int operator[](int index);
    ~sortedlinkedlist();
    friend ostream& operator<<(ostream& os, const sortedlinkedlist& list);

};
#endif









