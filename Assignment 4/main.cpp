#include<cstdlib>
#include<fstream>
#include<iostream>
#include <sstream>
#include<string>
#include<vector>
#include<ctime>
#include<math.h>
#include <list>
#include <map>

#include "Binary.h"
#include "GraphNode.h"
#include "BinTree.h"


using namespace std;

vector<string> words;
vector<string> randomWords;
vector<string> graphs;
list<string> verList1;

int parse(char x){

    switch(toascii(x)){
        case 48:
            return 0;
            break;
        case 49:
            return 1;
            break;
        case 50:
            return 2;
            break;
        case 51:
            return 3;
            break;
        case 52:
            return 4;
            break;
        case 53:
            return 5;
            break;
        case 54:
            return 6;
            break;
        case 55:
            return 7;
            break;
        case 56:
            return 8;
            break;
        case 57:
            return 9;
            break;
        default:
            return -1;
            break;

    }
}

void insertEdge(vector<string> graphs, string v1, string v2){

    int x1 = parse(v1[12]);
    int x2 = parse(v2[12]);
    graphs.push_back(v1);
    graphs.push_back(v2);
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

 /*void child (string word){
    Node *root = newNode(word);

    inorder(root);

     root->left = newNode(word);
     root->right = newNode(word);
     root->right->left = newNode(word);
     root->left->left = newNode(word);
     root->left->right = newNode(word);
     root->right->right = newNode(word);

    binaryTreeToBST(root);


}
 */

int main(int argc, char** argv) {
    ifstream letterFile;
    string text;
    ifstream graphFile;
    Node* rightBound;
    Node* leftBound;

    bool start = false;
    int numbers = 0;
    GNode* g =  new GNode();

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

        while (std::getline(letterFile, text))
            words.push_back(text);
    randomWord();
        for (int i = 1; i < 4; i++){
            Node* root = newNode(randomWords[i]);
            leftBound = newNode(randomWords[i-1]);
            rightBound = newNode(randomWords[i+1]);
          //  binaryTreeToBST(root);
            inorder(root, leftBound, rightBound);
        }

    }



    letterFile.close();

    //randomWord();
    //  printFile();

    cout << "Inorder traversal of BST is: " << endl;

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
           /* std::stoi(text);
          char  gr =  text.at(text.size() - 1);
         string number{gr};
            text = numbers;*/

            if(text.find("new graph") != std::string::npos){
                vector<string>graph;
                int count = 0;
                for(; text.find("add vertex"); count++);
                int arr[7][7];
                for(int i = 0; i< 7 ;i++){
                    for(int j = 0; j<7; j++){
                        arr[i][j] = 0;
                    }
                }
                count  = 0;
                if(text.find("add edge")){
                    int i = parse(text[10]) - 1;
                    int j = parse(text[14]) - 1;
                    arr[i][j] = 1;
                    arr[j][i] = 1;
                    g->dest = i;
                    g->next->dest = j;
                    g->dest = j;
                    g->next->dest = i;
                    cout << g;
                }
                //add_edge(adj_list, parse(text[10]), parse(text[14]));
                //if(arr[1][2] == 1)
                    //connected or no edge
                    //else
                        //not connected or no edge
                insertEdge(graphs,"add vertex 1","add vertex 2");

            }

        }

        graphFile.close();
    }

    //int m =0;
   // while( m < graphs.size()){
     //   if(graphs.at(m)[4] == 'v' )
    //        verList1.push_back( graphs.at(m)[9]);
    //}

    /*Node* root = newNode("scoop");
    root->left = newNode("hhf");
    root->right = newNode("ewegsdg");
    root->right->left = newNode("dsgsgds");
    root->left->left = newNode("sdgfsg");
    root->left->right = newNode("pp");
    root->right->right = newNode("aaaaa");
    binaryTreeToBST(root);
    cout << "Inorder traversal of BST is: " << endl;
    inorder(root);*/

}