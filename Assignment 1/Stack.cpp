#include<cstdlib>
#include<iostream>
#include "Stack.h"

using namespace std;

Stack::Stack()// constructor when adding new stack
{
    stackPt = NULL;
}


void Stack::Push(char push) {
    if (stackPt == NULL) {
        cout << "Nothing is on the Stack\n";
    }
    else
    {
        Node* a = stackPt;
        Node* tempNode = stackPt->tail;
        a->head = NULL;
        tempNode->head = a;
        a->item = push;
        stackPt = a;
    }
}

void Stack::Pop(char chr) {
    //Node* n = new Node;
    if(stackPt != nullptr && stackPt->tail != nullptr){
    Node* temp = stackPt;
    stackPt = stackPt-> tail;
    stackPt->head = nullptr;
    delete temp;
    }
}

