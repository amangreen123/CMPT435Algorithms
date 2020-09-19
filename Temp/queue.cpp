#include <cstdlib>
#include "queue.h"
#include<iostream>
using namespace std;

int main(int argc, char** argv) {
    Queue q(5);
        q.enquene(1);
        q.enquene(2);
        q.enquene(3);
        cout << "Queue size is" << q.size() << endl;
        q.dequene();
        q.dequene();
        q.dequene();

        if (q.empty())
            cout << "Queue is Empty\n";
        else
            cout << "Queue is not Empty\n";

        return 0;
}

