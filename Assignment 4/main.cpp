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
#include "BinTree.h"

using namespace std;

vector<string> words;
vector<string> randomWords;
vector<string> graphs;
list<int> verList1;

void insertEdge(list<int> verList1[], int u,int v){
    verList1[u].push_back(v);
    verList1[v].push_back(u);
}

void count_edges(list<int> verList1[],int v){
    int count = 0;
    for(int i = 0; i < v; i++){
        count += verList1[i].size();
    }
    count = count/2;
}


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
    /*ifstream letterFile;
    string text;
    ifstream graphFile;
    BinaryTree BST;
    bool start = false;

    int numbers;


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

    //trying to call one or the other version of insert and search
    // if you put 2 params (ranwords, words), it only wants the version with 1 param
    // if you put 1 param (randwords), it only wants the version with 2 params
    //BST.insert(randomWords);


    graphFile.open("graphs1.txt", ios::in);

    if (!graphFile) {
        cout << "\n Error opening graph file";
        exit(0);
    }

    if (graphFile.is_open()) {
        while (std::getline(graphFile, text)) {

            if(text.find("new graph") != std::string::npos){
                start = true;

                if(text.find("add vertex ")){
                   // consider how we read in a whole line
                   // read in the entire line (ex: add vertex 1)
                   // then parse/split the line to grab the int
                   graphs.push_back(text);
               }
            }

        }

        graphFile.close();
    }
*/
    //int m =0;
   // while( m < graphs.size()){
     //   if(graphs.at(m)[4] == 'v' )
    //        verList1.push_back( graphs.at(m)[9]);
    //}

    Node* root = newNode("scoop");
    root->left = newNode("hhf");
    root->right = newNode("ewegsdg");
    root->right->left = newNode("dsgsgds");
    root->left->left = newNode("sdgfsg");
    root->left->right = newNode("pp");
    root->right->right = newNode("aaaaa");
    binaryTreeToBST(root);
    cout << "Inorder traversal of BST is: " << endl;
    inorder(root);

}