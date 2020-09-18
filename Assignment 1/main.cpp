#include <cstdlib>
#include "Queue.h"
#include "Stack.h"
#include<fstream>
using namespace std;

int main(int argc, char** argv) {
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
    Stack MagicItems;
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
}


}
