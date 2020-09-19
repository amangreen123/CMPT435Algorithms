#pragma once
#include <string>
using namespace std;


class Stack { //constructor
public:

    struct Node {
        Node* head;
        char item;
        Node* tail;
    }*stackPt;


    void Push(char items);
    void Pop(char ch);
};
