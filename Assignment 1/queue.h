#pragma once
#include <iostream>
#include <cstdlib>


using namespace std;


class Queue {

private:

    struct QNode {
        char item;
        QNode* tail;
    };
    QNode* queueHead;



public:
    Queue();
    char dequeue();
    void enqueue(const char item);
    bool emptyQueue() const;
};

