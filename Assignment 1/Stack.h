#pragma once
#include <string>
using namespace std;


class Stack { //constructor
private:

    struct Node {
        Node* head;
        char item;
        Node* tail;
    }*stackPt;




public:
    void Push(char items);
    void Pop();
    void ReadItem(Node* readitem);
    void PrintStack();

    Stack();
    ~Stack();

};
