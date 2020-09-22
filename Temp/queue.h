#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <cstdlib>
using namespace std;

class Queue
{
    int* arr;
        int MAX;
        int front;
        int rear;
        int count;
public:
        Queue(int size);
            ~Queue();
            void dequene();
            void enquene(int x);
            int size();
            int peek();
            bool empty();
            bool full();

};

Queue::Queue(int size) {
    arr = new int[size];
    MAX = size;
    front = 0;
    rear = -1;
    count = 0;
}

Queue::~Queue() {
    delete[] arr;
}

void Queue::dequene() {
    if (empty()) {
        cout << "Queue is empty";
        exit(EXIT_FAILURE);
    }
    cout << "Removing" << arr[front] << '\n';
    front = (front + 1) % MAX;
    count--;
}

void Queue::enquene(int item)
{
    if (full()) {
        cout << "Stack is Full\n";
        rear = (rear + 1) % MAX;
        arr[rear] = item;
        count++;
    }
}

int Queue::peek() {
    if (empty()) {
        cout << "Queue is empty\n";
        exit(EXIT_FAILURE);
    }
    return arr[front];
}

int Queue::size() {
    return count;
}

bool Queue::empty() {
    return (size() == 0);
}

bool Queue::full() {
    return (size() == MAX);
}

#endif // QUEUE_H
