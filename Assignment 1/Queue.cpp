#include <iostream>
#include<cstdlib>
using namespace std;
<<<<<<< HEAD
#include "../Queue.h"

Queue::Queue()// constructor when adding new node
{
    queueHead = NULL;
}




bool Queue::emptyQueue() const {
    return queueHead == NULL;
    //return queChar == 0;
}

//pushes
void Queue::enqueue(char queChar) {
=======
#include "Queue.h"



Queue::Queue()// constructor when adding new node
{
    queuePt = NULL;

}

//pushes
void Queue::enqueue(char charc) {
>>>>>>> f043b6262aa0378e76b2589a546c146fd5b63b77
    //QNode* temp = new QNode;
    //temp->item;
    //temp-> queuePt = NULL;
    QNode* qu = new QNode;
<<<<<<< HEAD
    qu ->item = queChar;
    qu ->tail = NULL;
    if(queueHead == NULL){
        queueHead = qu;
    }else{
        QNode* temp;
        temp = queueHead;
      while(temp ->tail != nullptr){
           temp = temp -> tail ;
      }
      temp -> tail = qu;
    }
=======
    QNode* queuePt = queuePt->tail;
    qu->tail = NULL;
    queuePt->head = qu;
    qu->item = charc;
    qu->tail = NULL;
    queuePt = qu;
>>>>>>> f043b6262aa0378e76b2589a546c146fd5b63b77
}



//removes
char Queue::dequeue() {
<<<<<<< HEAD
    if (queueHead != nullptr) {
        QNode* tem = queueHead;
        queueHead = tem -> tail;
        char item = tem -> item;
        delete tem;
        return item;
=======
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
>>>>>>> f043b6262aa0378e76b2589a546c146fd5b63b77
    }
}
