#include<cstdlib>
#include<iostream>
#include "List.h"

using namespace std;


List::List() {
	head = NULL;//private pointer
	curr = NULL;
	temp = NULL;
}

void List::AddNode(std::string addItem) {
	Pointer n = new Node; //points to new node
	n->nextItem = NULL;
	n->items = addItem;

	if (head != NULL) {
		curr = head;\
			while (curr->nextItem != NULL) {
				curr = curr->nextItem;
			}
		curr->nextItem = n;
	}
	else
	{
		head = n;
	}
}