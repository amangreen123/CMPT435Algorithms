#pragma once
#include <string>

using namespace std;


class Stack { //constructor
    int numChar;//number of elements in struct
private:
	struct Mitem
	{
		string name;
		char arrname;
		Mitem* lastItem;
	};

<<<<<<< Updated upstream
	Mitem* stackPt;

public:
	void Push(string name,int arrname);
	void Pop();
	void ReadItem(Mitem);
	void PrintStack();

	Stack();
	~Stack();


};
=======
    struct Node {
        Node* head;
        char item;
        Node* tail;
    };
Node* stackPt;

public:
    Stack();
    void Push(const char item);
    void Pop();
    int stackSize() const;
    bool emptyStack() const;
};

>>>>>>> Stashed changes
