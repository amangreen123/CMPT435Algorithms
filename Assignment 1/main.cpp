#include <cstdlib>
#include<fstream>
<<<<<<< HEAD
<<<<<<< Updated upstream
=======
#include<iostream>
#include <string>
#include <vector>
#include "Stack.h"
#include "Queue.h"

>>>>>>> f043b6262aa0378e76b2589a546c146fd5b63b77
using namespace std;


bool compareList(Stack& s, Queue& q) {

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

<<<<<<< HEAD
	MagicItems.RemoveNode("d");
	MagicItems.PrintList();
=======
#include<iostream>
#include <string>
#include <vector>
#include "/Queue.h"
#include "/Stack.h"
#pragma

using namespace std;


bool compareList(Stack& s, Queue& q) {
    bool emptyS = s.emptyStack();
    bool emptyQ = q.emptyQueue();
    while (emptyQ != true && emptyS != true) {

      if (s.Pop() == q.dequeue()){
          cout << "is Palindrome \n";
          return true;
      }else{
          cout << "is not Palindrome \n";
          return false;
      }

     }
}
    int main(int argc, char** argv) {

        Stack stack;
        Queue queue;
        ifstream letterFile;
        string text;
        vector<string> words;

        letterFile.open("magicitems.txt", ios::in);

        if (!letterFile) {
            cout << "\n Error opening file";
            exit(0);
        }

        if (letterFile.is_open()) {
            while (std::getline(letterFile, text )) {
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
            while(stack.emptyStack() == false)
                stack.Pop();
            while(queue.emptyQueue() == false)
                queue.dequeue();
        }
       }
>>>>>>> Stashed changes
=======
>>>>>>> f043b6262aa0378e76b2589a546c146fd5b63b77

