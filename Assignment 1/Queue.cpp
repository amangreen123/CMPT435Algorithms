#include <iostream>
#include<cstdlib>
using namespace std;
#include "Queue.h"



Queue::Queue()// constructor when adding new node
{
    queuePt = NULL;

}

//pushes
void Queue::enqueue(char charc) {
    //QNode* temp = new QNode;
    //temp->item;
    //temp-> queuePt = NULL;
    QNode* qu = new QNode;
    QNode* queuePt = queuePt->tail;
    qu->tail = NULL;
    queuePt->head = qu;
    qu->item = charc;
    qu->tail = NULL;
    queuePt = qu;
}



//removes
char Queue::dequeue() {
    QNode* qut = new QNode;

    if (queuePt != nullptr && queuePt->tail != nullptr) {
        QNode* tem = queuePt;
        tem = tem->tail;
        tem->tail = nullptr;
        queuePt->tail = NULL;
        delete tem;
    }
    return;
}

bool Queue::emptyQueue() {
    if (queuePt == NULL) {
        return queuePt = new QNode;
    }
}
