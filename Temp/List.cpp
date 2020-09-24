#include<cstdlib>
#include<iostream>
#include "List.h"

using namespace std;


List::List() {
	head = NULL;//private pointer
	curr = NULL;//current poniter
	temp = NULL;// temporary poniter
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

void List::RemoveNode(std::string delItem) {
	Pointer delPt = NULL;
	temp = head;
	curr = head;
	while (curr != NULL && curr->items != delItem) {
		temp = curr;
		curr = curr->nextItem;
	}
	if (curr == NULL) {
		cout << delItem << "not in the list\n";
		delete delPt; //helps save memory
	}
	else {
		delPt = curr;
		curr = curr->nextItem;
		temp->nextItem = curr;
		if (delPt == head) {
			head = head->nextItem;
			temp = NULL;

		}
		delete delPt;
		cout << delItem << "was deleted\n";
	}
}

void List::PrintList() {
	curr = head;
	while (curr != NULL) {
		cout << curr->items << endl;
		curr = curr->nextItem;
	}
}
	
