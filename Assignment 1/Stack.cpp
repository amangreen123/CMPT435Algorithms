#include<cstdlib>
#include<iostream>
#include "/Stack.h"
#include<cstddef>
#pragma
using namespace std;

Stack::Stack()// constructor when adding new stack
{
    stackPt = NULL;// not pointing to anything at all
}


bool Stack::emptyStack() const {
     return  stackPt == NULL;
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

}

char Stack::Pop() {
    if (stackPt == NULL) {
        //nothing on the stack
    } else {
        Node *p = stackPt;
        stackPt = stackPt->tail;
        p->tail = NULL;
        char item = p->item;
        delete p;
        return item;
    }

}
