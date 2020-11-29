#include<cstdlib>
#include<fstream>
#include<iostream>
#include <sstream>
#include<string>
#include<vector>
#include<ctime>
#include "Queue.h"
#include<math.h>
#include <list>
#include <map>
#include<iomanip>

#include "GraphNode.h"
#include "BinTree.h"


using namespace std;

vector<string> words;
vector<string> randomWords;
int count = 0;


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

/*
class Graph{

    GNode* adjNode(int dest, GNode* head){
        GNode* newNode = new GNode;
        newNode -> vertex = dest;

        newNode -> next = head;

        return newNode;
    }

    int N;

public:
    GNode **head;

    Graph(undirectedG edges[], int n, int N){
        head = new GNode*[N]();
        this -> N = N;
        for(int i = 0; i < N; i++)
            head[i] = nullptr;

        for(unsigned i = 0; i < n; i++){
            string src = edges[i].src;
            string dest = edges[i].dest;

            GNode* newNode = adjNode(dest,head[src]);

            head[src] = newNode;

            newNode = adjNode(src,head[dest]);
            head[dest] = newNode;
        }

    }
    ~Graph(){
        for (int i = 0; i < N; i++)
            delete[] head[i];

        delete[] head;
    }

    void printList(GNode* ptr){
        while (ptr != nullptr)
        {
            cout << " -> " << ptr->vertex << " ";
            ptr = ptr-> next;
        }
        cout << endl;
    }
};
*/


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
    Queue q;
    Node* rightBound;
    Node* leftBound;

    bool start = false;
    int numbers = 0;


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

        //read line by line
        while (std::getline(graphFile, text)) {

            //ignore header line
            std::getline(graphFile, text);

            //start a new graph
            if (text.find("new graph") != std::string::npos) {

                vector<string> vecVertex;
                vector<string> vecEdges;

                while (std::getline(graphFile, text)) {

                    if (text == "") {
                        break;
                    }
                    if (text.find("add edge") != std::string::npos) {//"add edge"
                        vecEdges.push_back(text);
                    }
                    else {
                        vecVertex.push_back(text);
                    }
                }

                //graph:	 1. as	a	matrix
                int numVertices = vecVertex.size() + 1;

                int** matrix = new int* [numVertices];
                for (int i = 0; i < numVertices; i++) {
                    matrix[i] = new int[numVertices];
                }

                //reset matrix
                for (int i = 0; i < numVertices; i++) {
                    for (int j = 0; j < numVertices; j++) {
                        matrix[i][j] = 0;
                    }
                }

                //set the edges
                for (int i = 0; i < vecEdges.size(); i++) {

                    string edge = vecEdges[i].substr(9);//example add edge 1 - 2 -> get substring 1 - 2
                    stringstream ss(edge);

                    int fromVertex = 0;
                    int toVertex = 0;
                    string temp = ""; //such as -

                    ss >> fromVertex >> temp >> toVertex;
                    matrix[fromVertex][toVertex] = 1; //from vertex and to vertex is 0-based
                    matrix[toVertex][fromVertex] = 1; //undirected graph
                }

                //print matrix
                cout << "Matrix" << endl;
                for (int i = 0; i < numVertices; i++) {
                    for (int j = 0; j < numVertices; j++) {
                        cout << setw(2) << matrix[i][j];
                    }
                    cout << endl;
                }

                //free matrix
                for (int i = 0; i < numVertices; i++) {
                    delete[] matrix[i];
                }
                delete[] matrix;
                cout << endl << endl;

                //adjacency List
                GNode** nodeList = new GNode*[numVertices];
                for (int i = 0; i < numVertices; i++) {
                    nodeList[i] = new GNode();
                    nodeList[i]->vertex = i;
                    nodeList[i]->next = NULL;
                }
                /*
                GNode[0] -> NULL
                GNode[1] -> NULL
                GNode[2] -> NULL
                GNode[3] -> NULL
                GNode[4] -> NULL
                GNode[5] -> NULL
                */

                for (int i = 0; i < vecEdges.size(); i++) {

                    string edge = vecEdges[i].substr(9);//example add edge 1 - 2 -> get substring 1 - 2
                    stringstream ss(edge);

                    int fromVertex = 0;
                    int toVertex = 0;
                    string temp = ""; //such as -

                    ss >> fromVertex >> temp >> toVertex;

                    //retrive vertices by indices
                    GNode* fromNode = nodeList[fromVertex];
                    GNode* toNode = nodeList[toVertex];

                    //move to tail node of linked list fromNode
                    while (fromNode->next != NULL){
                        fromNode = fromNode->next;
                    }
                    //then add a new node to tail
                    fromNode->next = new GNode();
                    fromNode->next->vertex = toVertex;
                    fromNode->next->next = NULL; //fromNode->next points to new node, so fromNode->next->next is point to next node from now node

                    //move to tail node of linked list toNode
                    while (toNode->next != NULL){
                        toNode = toNode->next;
                    }
                    //then add a new node to tail
                    toNode->next = new GNode();
                    toNode->next->vertex = fromVertex;
                    toNode->next->next = NULL; //toNode->next points to new node, so toNode->next->next is point to next node from now node

                    /*
                     example: if add edge 1 - 2, the adjacency list is

                     GNode[0] -> NULL
                     GNode[1] -> GNode[2] -> NULL
                     GNode[2] -> GNode[1] -> NULL
                     GNode[3] -> NULL
                     GNode[4] -> NULL
                     GNode[5] -> NULL
                   */
                }

                //print the adjacency List
                cout << "Adjacency List" << endl;
                for (int i = 0; i < numVertices; i++) {

                    //current points to the head of linked list at [i]
                    GNode* current = nodeList[i];
                    cout << "Vertex " << i;

                    //iterate based on edges
                    current = current->next;
                    while (current != NULL){
                        cout << " -> Vertex " << current->vertex;
                        current = current->next;
                    }
                    cout << endl;
                }

                //free resource
                for (int i = 0; i < numVertices; i++) {

                    //current points to the head of linked list at [i]
                    GNode* current = nodeList[i];
                    GNode* temp;

                    //iterate the linked list and delete node
                    while (current != NULL){
                        temp = current;
                        current = current->next;
                        delete temp;
                    }
                }
                delete[] nodeList;
                cout << endl << endl;

            }

        }

    }

    graphFile.close();
}

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