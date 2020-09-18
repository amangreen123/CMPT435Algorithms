#include<cstdlib>
#include<iostream>
#include "Stack.h"

using namespace std;

Stack::Stack()// constructor when adding new stack
{
    stackPt = NULL;
}

Stack::~Stack()//deconstructor called when stack object gonnna be destroyed
{
    Node* pt1;//pointer
    Node* pt2;

    pt1 = stackPt;
    while (pt1 != NULL) {
        pt2 = pt1;
        pt1 = pt1->tail;
        pt2->tail = NULL;
        delete pt2;
    }
}

void Stack::Push(char name) {
    Node* n = new Node;

    n->item = name;

    if (stackPt == NULL) {
        stackPt = n;
        stackPt->tail = NULL;
    }
    else {
        n->tail = stackPt;
        stackPt = n;
    }
}

void Stack::ReadItem(Node* pritem) {
    cout << "-------------";
    cout << "name:  " << pritem-> item << endl;
    cout << "-------------";
}

void Stack::Pop() {
    if (stackPt == NULL) {
        cout << "Nothing is on the Stack\n";
    }
    else
    {
        Node* pritem = stackPt;
        ReadItem(pritem);
        stackPt = stackPt-> tail;
        pritem->tail = NULL;
        delete pritem; // deletes top of stack

    }
}
    void Stack::PrintStack() {

        Node* p = stackPt;

        while (p != NULL) {
            ReadItem(p);
            p = p->tail;
            //prints items top to bottom
        }
    }
