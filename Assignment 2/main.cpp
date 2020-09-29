#include<cstdlib>
#include<fstream>
#include<iostream>
#include<string>
#include<vector>
#include "Selection.h"
#pragma

using namespace std;

vector<string> words;

void swap(string *a, string *b){
    string temp = *a;
    *a = *b;
    *b = temp;
}

void sSort() {
    int i, j, imin;//imin index of
    int num_comparison = 0; // incrmeent comparsion
    for (i = 0; i < words.size() - 1; i++) {
        imin = 1;
        for (j = i + 1; j < words.size(); j++) {
            if (toupper(words[j][0]) < toupper(words[imin][0])) {
                imin = j;
            }
            swap(words[i], words[imin]);
            num_comparison++;
        }
    }
    cout<< "Selection sort number of comparisons is " <<num_comparison<<"\n";
}



    int main(int argc, char **argv) {
        ifstream letterFile;
        string text;


        letterFile.open("magicitems.txt", ios::in);

        if (!letterFile) {
            cout << "\n Error opening file";
            exit(0);
        }

        if (letterFile.is_open()) {
            while (std::getline(letterFile, text)) {
                words.push_back(text);
               // cout << text << "\n";
            }

            sSort();

            letterFile.close();
        }



        //InSort(words);

        for (int i = 0; i < words.size()-1; i++) {
             cout<<words[i]<<"\n";
         }

    }
