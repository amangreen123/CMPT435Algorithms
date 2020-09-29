#include <iostream>
#include<cstdlib>
using namespace std;
#include "/Queue.h"

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
    //QNode* temp = new QNode;
    //temp->item;
    //temp-> queuePt = NULL;
    QNode* qu = new QNode;
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
}



//removes
char Queue::dequeue() {
    if (queueHead != nullptr) {
        QNode* tem = queueHead;
        queueHead = tem -> tail;
        char item = tem -> item;
        delete tem;
        return item;
    }
}
