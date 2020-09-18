#include <iostream>
#include <cstdlib>


using namespace std;


class Queue {

    typedef struct Node {

        Node* head;
        char item;
        Node* tail;
    }* queuePt;



public:
    Queue();
    void dequene();
    void enquene(char c);
};

Queue::Queue()// constructor when adding new stack
{
    queuePt = NULL;

}

//pushes
void Queue::enquene(char charc) {

    Node* qu = new Node;
    Node* queuePt = queuePt->tail;
    qu->tail = NULL;
    queuePt->head = qu;
    qu->item = charc;
    queuePt = qu;
}


//removes
void Queue::dequene() {
    Node* qut = new Node;

    if (queuePt != nullptr && queuePt->tail != nullptr) {
        Node* tem = queuePt;
        tem = tem->tail;
        tem -> tail = nullptr;
        queuePt -> tail = NULL;
        delete tem;
    }

}



