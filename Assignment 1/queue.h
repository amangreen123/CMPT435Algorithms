#pragma once
#include <iostream>
#include <cstdlib>


using namespace std;


class Queue {


private:
    struct QNode {
        QNode* head;
        char item;
        QNode* tail;

    };
    QNode* queuePt;



public:
    Queue();
    char dequeue();
    void enqueue(char i);
    bool emptyQueue();
};


