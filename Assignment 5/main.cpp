#include <iostream>
#include<cstdlib>
#include<fstream>
#include<iostream>
#include<sstream>
#include<iomanip>
#include<vector>
#include <algorithm>
#include "Graph.h"

using namespace std;


class LinkedObject{

public:
    int id;
    bool processed;
    int distance = -1;
    vector<int> neighbors;
    vector<int> weights;
};
//used pairs one as the const and the other one as the actual path to follow
// The first value pair is cost the second is the actual path
pair<int,vector<int>>* BellmanFord(LinkedObject* graph, int numVertices){
    int start = 0;
    vector<string> vecEdges;
    int* distance = new int[numVertices];
    int* parent = new int[numVertices];
    int infinity = 1000000000;

    for (int i = 0; i < numVertices;i++) {
        distance[i] = infinity;
        parent[i] = -1;
    }
    distance[start] = 0;

    for (int i = 0; i < numVertices; i++) {
        for (int v = 0; v < numVertices; v++) {
            if (distance[v] == -1)
                continue;
            for (int index = 0; index < graph[v].neighbors.size(); index++) {
                int adj = graph[v].neighbors[index];
                int w = graph[v].weights[index];
                if (distance[adj] > distance[v] + w){
                    distance[adj] = distance[v] + w;
                    parent[adj] = v;
                }
            }
        }
    }
    pair<int,vector<int>>* shortest_paths = new pair<int,vector<int>>[numVertices];
    for (int i = 0; i < numVertices; i++){
        shortest_paths[i].first = distance[i];
        int v = i;
        while (v != -1){
            shortest_paths[i].second.push_back(v);
            v = parent[v];
        }
        reverse(shortest_paths[i].second.begin(),shortest_paths[i].second.end());
    }
    return shortest_paths;
}

/*void InSort(){
//i selected element
//j insert element
int i,j;
string key;
for(i = 0; i < words.size(); i++){
key = words[i];
j = i -1;
while(j >= 0 && compare_String(words[j],key) > 0){
words[j+1] = words[j];
--j;
}
words[j+1] = key;
}

}*/


int main() {

    string text;
    ifstream graphFile;
    ifstream spice;
    string knapSack;

    graphFile.open("graphs2.txt", ios::in);
    //    spice.open("spice.txt", ios::in);

    if (!spice) {
        cout << "\n Error opening spice file";
        exit(0);
    }

    if (!graphFile) {
        cout << "\n Error opening graph file";
        exit(0);
    }

    while (graphFile.is_open()) {
        vector<string> vecVertex;
        vector<string> vecEdges;

        while (std::getline(graphFile, text)) {

            if (text == "") {
                break;
            }
            if (text.find("add edge") != std::string::npos) {//"add edge"
                vecEdges.push_back(text);
            }
            if (text.find("add vertex") != std::string::npos) {//"add vertex"
                vecVertex.push_back(text);
            }
        }

        //graph:	 1. as	a	matrix
        int numVertices = vecVertex.size();

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

        /*   1 2 3 4
             1  1
             2 1
             3      1
             4    1*/

        //set the edges
        for (int i = 0; i < vecEdges.size(); i++) {

            string edge = vecEdges[i].substr(9);//example add edge 1 - 2 -> get substring 1 - 2
            stringstream ss(edge);

            int fromVertex = 0;
            int toVertex = 0;
            int w;
            string temp = ""; //such as -

            ss >> fromVertex >> temp >> toVertex >> w;

            fromVertex--, toVertex--;

            matrix[fromVertex][toVertex] = w; //from vertex and to vertex is 0-based
            //matrix[toVertex][fromVertex] = 1; //undirected graph
        }


        //print matrix
        /*
        cout << "Matrix" << endl;
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                cout << setw(2) << matrix[i][j];
            }
            cout << endl;
        }
        */
        //free matrix
        for (int i = 0; i < numVertices; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
        //cout << endl << endl;

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

        /*1 -----> 2
          |        |
          |        |
          |        |
          v        v
          3<-------4

          1-->[(2)->(3)]-->()
          2-->[4]
          3-->[]
          4-->[3]
         */
        for (int i = 0; i < vecEdges.size(); i++) {

            string edge = vecEdges[i].substr(9);//example add edge 1 - 2 -> get substring 1 - 2
            stringstream ss(edge);

            int fromVertex = 0;
            int toVertex = 0;
            int w;
            string temp = ""; //such as -

            ss >> fromVertex >> temp >> toVertex >> w;

            fromVertex--, toVertex--;

            //retrive vertices by indices
            GNode* fromNode = nodeList[fromVertex];
            GNode* toNode = nodeList[toVertex];

            //move to tail node of linked list fromNode
            while (fromNode->next != NULL){
                fromNode = fromNode->next;
            }
            //then add a new node to tail
            fromNode->next = new GNode();
            fromNode->next->weight = w;
            fromNode->next->vertex = toVertex;
            fromNode->next->next = NULL; //fromNode->next points to new node, so fromNode->next->next is point to next node from now node

            //move to tail node of linked list toNode
            //  while (toNode->next != NULL){
            //  toNode = toNode->next;
            // }
            //then add a new node to tail
            // toNode->next = new GNode();
            //toNode->next->vertex = fromVertex;
            //toNode->next->next = NULL; //toNode->next points to new node, so toNode->next->next is point to next node from now node

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
        /*
        cout << "Adjacency List" << endl;
        for (int i = 0; i < numVertices; i++) {

            //current points to the head of linked list at [i]
            GNode* current = nodeList[i];
            cout << "Vertex " << i;

            //iterate based on edges
            current = current->next;
            while (current != NULL){
                cout << " -> Vertex " << current->vertex<<" "<<current->weight;
                current = current->next;
            }
            cout << endl;
        }*/

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

        LinkedObject* linkedObjectGraph = new LinkedObject[numVertices];
        for (int i = 0; i < numVertices; i++) {
            linkedObjectGraph[i].id = i;
        }

        //        cout << "linked Objects graph";


        for (int i = 0; i < vecEdges.size(); i++) {

            string edge = vecEdges[i].substr(9);//example add edge 1 - 2 -> get substring 1 - 2
            stringstream ss(edge);
            int fromVertex = 0;
            int toVertex = 0;
            int w;
            string temp = "";

            ss >> fromVertex >> temp >> toVertex >> w;

            fromVertex--, toVertex--;

            linkedObjectGraph[fromVertex].neighbors.push_back(toVertex);
            linkedObjectGraph[fromVertex].weights.push_back(w);
        }

        pair<int,vector<int>>* shortest_paths = BellmanFord(linkedObjectGraph, numVertices);

        for (int i = 1; i < numVertices; i++){
            cout << "1 --> " << i+1 << " cost is " << setw(2) << shortest_paths[i].first << "; path: 1";
            for (int j = 1; j < shortest_paths[i].second.size(); j++)
                cout << " --> " << shortest_paths[i].second[j] + 1 ;
            cout << "\n";
        }
    }

    spice.close();
    graphFile.close();
    return 0;
}
