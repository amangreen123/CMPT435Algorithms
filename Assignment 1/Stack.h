#pragma once
#include <string>
using namespace std;


class Stack { //constructor
    int numChar;//number of elements in struct
private:

<<<<<<< HEAD
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
=======
    struct Node {
        Node* head;
        char item;
        Node* tail;
    };

public:
    Node *stackPt;
    
    Stack();
    void Push(char items);
    char Pop();
    bool emptyStack();
};
>>>>>>> f043b6262aa0378e76b2589a546c146fd5b63b77
