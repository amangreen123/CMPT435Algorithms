#pragma once
#include <string>

class List {

private:
	
	typedef struct Node {
		std::string items;
		Node* nextItem;

	}* Pointer;
	 
	Pointer head;
	Pointer curr;
	Pointer temp;

public:
	List();
	void AddNode(std:: string addItem);
	void DeleteNode(std::string delData);
	void PrintList();

};
