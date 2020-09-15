#pragma once
#include <string>

class List {

private:
	
	typedef struct Node {
		std::string items;
		Node* nextItem;

	}* Pointer;
	 
	Pointer head;
	Pointer curr;//current pointer
	Pointer temp;//temporary pointer

public:
	List();
	void AddNode(std:: string addItem);
	void RemoveNode(std::string delData);
	void PrintList();

};
