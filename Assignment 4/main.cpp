#include<cstdlib>
#include<fstream>
#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include<math.h>
#include <list>
#include "Binary.h"
#include "GraphNode.h"

using namespace std;

vector<string> words;
vector<string> randomWords;





void randomWord(){
    srand(time(0));
    for(int i = 0; i < 42; i++){
        randomWords.push_back(words.at(rand() % 665));
    }
}
void printFile() {
    for (int i = 0; i < randomWords.size() - 1; i++) {
        cout << randomWords[i] << "\n";
    }
}

int main(int argc, char** argv) {
    ifstream letterFile;
    string text;
    ifstream graphFile;
    BinaryTree BT;
    int numbers;


    vector<string> graphs;
    list<int> verList1;
    list<int> verList2;
    list<int> verList3;
    list<int> verList4;
    list<int> verList5;


    letterFile.open("magicitems.txt", ios::in);

    if (!letterFile) {
        cout << "\n Error opening letter file";
        exit(0);
    }

    if (letterFile.is_open()) {
        while (std::getline(letterFile, text)) {
            words.push_back(text);
            cout << text << "\n";

        }

        letterFile.close();
    }
    randomWord();


    //BT.insert(randomWords);
    //BT.search(randomWords);


    graphFile.open("graphs1.txt", ios::in);

    if (!graphFile) {
        cout << "\n Error opening graph file";
        exit(0);
    }

    if (graphFile.is_open()) {
        while (std::getline(graphFile, text)) {
            graphs.push_back(text);
            //cout << text << "\n";
        }

        graphFile.close();
    }





    //int m =0;
   // while( m < graphs.size()){
     //   if(graphs.at(m)[4] == 'v' )
    //        verList1.push_back( graphs.at(m)[9]);
    //}


}