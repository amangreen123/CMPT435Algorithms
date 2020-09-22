#include<cstdlib>
#include<iostream>
<<<<<<< Updated upstream

#include "Stack.h"

=======
#include "../Stack.h"
#include<cstddef>
#pragma
>>>>>>> Stashed changes
using namespace std;

Stack::Stack()// constructor when ading new stack 
{
<<<<<<< Updated upstream
	stackPt = NULL;
}

Stack::~Stack()//deconstructor called when stack object gonnna be destroyed 
{
	Mitem* pt1;
	Mitem* pt2;

	pt1 = stackPt;
	while (pt1 != NULL) {
		pt2 = pt1;
		pt1 = pt1->lastItem;
		pt2->lastItem = NULL;
		delete pt2;
	}
}

void Stack::Push(string name, int arrname) {
	Mitem* n = new Mitem;

	n->name = name;
	n->arrname = arrname;

	if (stackPt == NULL) {
		stackPt = n;
		stackPt->lastItem = NULL;
	}
	else {
		n->lastItem = stackPt;
		stackPt = n;
	}
}
=======
    stackPt = NULL;// not pointing to anything at all
}

int Stack::stackSize()const {
 return numChar;
}

bool Stack::emptyStack() const {
    if(stackPt == NULL)
    {
        return numChar == 0;
    }
    else
    {
     return  numChar;
    }

    //return numChar ==  0;
}

void Stack::Push(char item) {
    Node* n = new Node;
    n -> item = item;
    if(stackPt == NULL){
        stackPt = n;
        stackPt ->tail = NULL;
    }
    else{
        n ->tail = stackPt;
        stackPt = n;
    }
    // 2 sample
   // Node* temp = new Node();
   // temp->item = character;
   // if (stackPt == NULL)
   // {
   //     temp->tail = NULL;
   // }
   // else
   // {
       // temp->tail = stackPt;
    //}
    //stackPt = temp;

    //1 samples
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

void Stack::Pop() {
    if(stackPt == NULL){
        //nothing on the stack
    }
    else{
        Node* p = stackPt;
        stackPt = stackPt ->tail;
        p ->tail = NULL;
        delete p;
    }


    //if (stackPt == NULL)
    //	cout << "underflow";
    //else
//	{
    //	Node* temp = stackPt;
    //	stackPt = stackPt->tail;
    //		delete(temp);
    //}
   // Node* temp;
   // Node* n = new Node;
    //if (stackPt != nullptr && stackPt->tail != nullptr) {
   //     temp = stackPt;
     //   stackPt = stackPt->tail;
     //   stackPt->head = nullptr;
   // }
}

//Node* a = stackPt;
//stackPt = stackPt->tail;
//a->head = NULL;
//stackPt->head = a;
//a->item = charac;
//a = stackPt;
>>>>>>> Stashed changes
