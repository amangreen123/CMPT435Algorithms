#pragma once
#include <string>
using namespace std;


class Stack { //constructor
    int numChar;//number of elements in struct
private:

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

