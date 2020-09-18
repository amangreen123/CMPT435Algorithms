#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <cstdlib>
using namespace std;


class Queue {

    struct Node {

        Node* head;
        char item;
        Node* tail;
    };

    Node* front = NULL;
    Node* rear = NULL;	//*headNode = NULL,*nextNode = NULL;


public:
    bool empty();
    void dequene();
    void enquene(char x);
};


bool Queue::empty()
{
    Node* headNode = new Node();
    Node* nextNode = new Node();
    if (headNode == NULL && nextNode == NULL) {
        return true;
    }
    else{
        return false;
    }
}


//removes element
void Queue::dequene() {
    Node* headNode = new Node();
    Node* nextNode = new Node();


    if (empty()) {
        if (front == rear)
        {
            free(front);
            front = rear = NULL;
        }
        else
        {
            Node* ptr = front;
            front = front->head;
            free(ptr);
        }
    }
}

//inserts element
void Queue::enquene(char items) {
    Node* headNode = new Node();
    Node* nextNode = new Node();

    headNode->item;
    headNode->tail = nextNode;
    nextNode->head = headNode;
    nextNode->item;

}
