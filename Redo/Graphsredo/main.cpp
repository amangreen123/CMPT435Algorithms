#include <iostream>
#include<cstdlib>
#include<fstream>
#include<iostream>
#include <sstream>
#include<string>
#include<vector>


using namespace std;

int main(int argc, char** argv) {

    ifstream letterFile;
    string text;
    ifstream graphFile;

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
                    } else {
                        vecVertex.push_back(text);
                    }
                }
            }
        }
    }
}