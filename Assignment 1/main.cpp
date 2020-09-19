#include <cstdlib>
#include<fstream>
#include<iostream>
#include <string>
#include <vector>
#include "Stack.h"
#include "Queue.h"

using namespace std;

int main(int argc, char** argv) {

    Stack stack;
    Queue queue;
    ifstream letterFile;
    string text;
    vector<string> words;
    int count = 0;

    letterFile.open("magicitems.txt", ios::in);

    if (!letterFile) {
        cout << "\n Error opening file";
        exit(0);
    }

    if (letterFile.is_open()) {
        while (std::getline(letterFile, text, ' ')) {
            words.push_back(text);
            cout << text << "\n";
        }

        letterFile.close();
    }


    for (int i = 0; i < words.size(); i++) {
        for (int j = 0; j < words[i].length(); j++) {
            stack.Push(words[i].at(j));
            queue.enqueue(words[i].at(j));
        }
        compareList(stack, queue);
        //empty function or while loop to empty
    }
    //figure out way to clear list after comaper

}
bool compareList(Stack& s, Queue &q) {

    while (q.emptyQueue() != true && s.emptyStack() != true) {
        char stackChar = s.Pop();
        char queueChar = q.dequeue();

        if (stackChar == queueChar) {
        }
        else {
            return false;
        }
    }
    return true;


}

