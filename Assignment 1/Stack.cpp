#include<cstdlib>
#include<iostream>
#include "Stack.h"

using namespace std;

Stack::Stack()// constructor when adding new stack
{
    stackPt = NULL;
}


void Stack::Push(char character) {
    Node* temp;
    temp = new Node;
    temp->item = character;
    if (stackPt == NULL)
    {
        temp->tail = NULL;
    }
    else
    {
        temp->tail = stackPt;
    }
    stackPt = temp;

    //if (stackPt == NULL) {
    //	cout << "Nothing is on the Stack\n";
    //}
    //else
    //{
    //	Node* a = (Node*)(stackPt);
    //	Node* tempNode = (Node*)(stackPt)->tail;
    //	a->head = NULL;
    //	tempNode->head = a;
    //	a->item = character;
    //	a->head = NULL;
        //stackPt = a;
    //}
}

char Stack::Pop() {
    //if (stackPt == NULL)
    //	cout << "underflow";
    //else
//	{
    //	Node* temp = stackPt;
    //	stackPt = stackPt->tail;
    //		delete(temp);
    //}
    Node* n = new Node;
    if(stackPt != nullptr && stackPt->tail != nullptr){
    Node* temp = stackPt;
    stackPt = stackPt-> tail;
    stackPt->head = nullptr;
    delete temp;

}

    bool emptyStack() {

    }


//Node* a = stackPt;
//stackPt = stackPt->tail;
//a->head = NULL;
//stackPt->head = a;
//a->item = charac;
//a = stackPt;
