#include <iostream>
#include<cstdlib>
#include<fstream>
#include<iostream>
#include<sstream>
#include<iomanip>
#include<string>
#include<vector>
#include <algorithm>
#include "Graph.h"
#include "KnapSack.h"
#include "Spice.h"
using namespace std;


class LinkedObject {

public:
    int id;
    bool processed;
    int distance = -1;
    vector<int> neighbors;
    vector<int> weights;
};
//used pairs one as the const and the other one as the actual path to follow
// The first value pair is cost the second is the actual path
pair<int, vector<int>>* BellmanFord(LinkedObject* graph, int numVertices) {
    int start = 0;
    vector<string> vecEdges;
    int* distance = new int[numVertices];
    int* parent = new int[numVertices];
    int infinity = 1000000000;

    for (int i = 0; i < numVertices; i++) {
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
                if (distance[adj] > distance[v] + w) {
                    distance[adj] = distance[v] + w;
                    parent[adj] = v;
                }
            }
        }
    }
    pair<int, vector<int>>* shortest_paths = new pair<int, vector<int>>[numVertices];
    for (int i = 0; i < numVertices; i++) {
        shortest_paths[i].first = distance[i];
        int v = i;
        while (v != -1) {
            shortest_paths[i].second.push_back(v);
            v = parent[v];
        }
        reverse(shortest_paths[i].second.begin(), shortest_paths[i].second.end());
    }
    return shortest_paths;
}

//example: spice name = red;    total_price =  4.0;  qty = 4;
Spice extractSpice(string line){

    string name;
    float value;
    int quantity;
    string temp;

    stringstream ss(line);

    //extract name
    getline(ss, temp, ';');
    name = temp.substr(13);

    //extract value
    getline(ss, temp, ';');
    while (temp[0] == ' ')
    {
        temp = temp.substr(1);
    }
    temp = temp.substr(13);
    stringstream ssCost(temp);
    ssCost >> value;

    //extract quantity
    getline(ss, temp, ';');
    temp = temp.substr(8);
    stringstream ssQuan(temp);
    ssQuan >> quantity;

    return Spice(name, value, quantity);
}

bool compareSpice(Spice s1, Spice s2)
{
    return s1.getValue() > s2.getValue();
}

int main() {

    string text;
    ifstream graphFile;
    ifstream spice;
    string knapText;

    graphFile.open("graphs2.txt", ios::in);
    spice.open("spice.txt", ios::in);

    if (!spice) {
        cout << "\n Error opening spice file";
        exit(0);
    }

    if (!graphFile) {
        cout << "\n Error opening graph file";
        exit(0);
    }

    //read spice file
    vector<Spice> spices;
    vector<int> knapsackCapacities;

    if (spice.is_open()) {

        while (std::getline(spice, knapText)) {

            if (knapText == "") {
                continue;
            }
            if (knapText.find("spice name") != std::string::npos) {
                spices.push_back(extractSpice(knapText));
            }else if (knapText.find("knapsack capacity") != std::string::npos) {
                knapText = knapText.substr(19, knapText.length() - 1);
                knapsackCapacities.push_back(atoi(knapText.c_str()));
            }
        }
    }
    spice.close();
    //end reading the spice file

    //sort vector
    sort(spices.begin(), spices.end(), compareSpice);

    //knapsack
    for (size_t i = 0; i < knapsackCapacities.size(); i++)
    {
        KnapSack knapSack(knapsackCapacities[i], spices);
        float values = knapSack.execute();
        vector<Spice> results = knapSack.getResults();

        cout << "Knapsack of capacity " << knapsackCapacities[i] << " is worth " << values
             << " quatloos";

        if (results.size() > 0)
        {
            cout << " and contains ";
            for (size_t j = 0; j < results.size(); j++) {
                if (j > 0) {
                    cout << ", ";
                }
                cout << results[j].getQuantity() << " scoops of " << results[j].getName();
            }
        }


        cout << endl;
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
        GNode** nodeList = new GNode * [numVertices];
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
            while (fromNode->next != NULL) {
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
            while (current != NULL) {
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

        pair<int, vector<int>>* shortest_paths = BellmanFord(linkedObjectGraph, numVertices);

        for (int i = 1; i < numVertices; i++) {
            cout << "1 --> " << i + 1 << " cost is " << setw(2) << shortest_paths[i].first << "; path: 1";
            for (int j = 1; j < shortest_paths[i].second.size(); j++)
                cout << " --> " << shortest_paths[i].second[j] + 1;
            cout << "\n";
        }
    }


    graphFile.close();



    return 0;
}