#pragma once
#include <iostream>
#include <cstdlib>


using namespace std;


class Queue {

<<<<<<< HEAD
private:

    struct QNode {
        char item;
        QNode* tail;
    };
    QNode* queueHead;
=======

private:
    struct QNode {
        QNode* head;
        char item;
        QNode* tail;

    };
    QNode* queuePt;
>>>>>>> f043b6262aa0378e76b2589a546c146fd5b63b77



public:
    Queue();
    char dequeue();
<<<<<<< HEAD
    void enqueue(const char item);
    bool emptyQueue() const;
};

=======
    void enqueue(char i);
    bool emptyQueue();
};


>>>>>>> f043b6262aa0378e76b2589a546c146fd5b63b77
