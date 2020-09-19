#include<cstdlib>
#include<iostream>

#include "Stack.h"

using namespace std;

Stack::Stack()// constructor when ading new stack 
{
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