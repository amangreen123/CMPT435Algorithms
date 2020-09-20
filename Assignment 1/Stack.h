#pragma once
#include <string>
using namespace std;


class Stack { //constructor
private:

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
