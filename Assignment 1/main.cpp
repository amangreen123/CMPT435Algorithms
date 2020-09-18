include <cstdlib>
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
        for (int j = 0; j < words[i].length();j++) {
            stack.Push(words[i].at(j));
            queue.enquene(words[i].at(j));
        }
    }
}

bool compareList(Stack *s, Queue *q) {

    while (q != nullptr && s != nullptr) {
        if (s-> p == q->c) {
            q.dequene();
            s.Pop();
        }
        else {
            return false;
        }
    }
    return true;


}
