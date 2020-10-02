#include<cstdlib>
#include<fstream>
#include<iostream>
#include<string>
#include<vector>
#pragma

using namespace std;

vector<string> words;
int num_comparison = 0; // increment comparsion


int compare_String(string a,string b){
  int i = 0;

    while(true){
        if(a.length() <= i && b.length() <= i )
            return 0;
        if(a.length() <= i ){
            return -1;
        }
        if(b.length() <= i ){
            return 1;
        }
       if(toupper(a[i]) < toupper(b[i]) ){
           return -1;
       }
      else if (toupper(a[i]) >  toupper(b[i])){
          return 1;
      }
      i++;
    }
}
void sSort() {
    int i, j, imin;

    for (i = 0; i < words.size() - 1; i++) {
        imin = i; //index of minium data
        for (j = i + 1; j < words.size(); j++) {
            if (j >= 0 && compare_String(words[imin],words[j]) > 0) {
                imin = j;
            }
            num_comparison++;
        }
        swap(words[i], words[imin]);
    }
    cout<< "Selection sort number of comparisons is " <<num_comparison<<"\n";
}

void InSort(){
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
            num_comparison++;
        }
        words[j+1] = key;
        num_comparison++;
    }
    cout<< "Insertion sort number of comparisons is " <<num_comparison<<"\n";
}

//Msort(){}

int partiton(vector<string>&item, int low,int high){
    string pivot = words[high];
    int i = (low - 1);

    for(int j = low; j < high; j++){
        if(words[j] <= pivot){
            i++;
           swap(words[i],words[j]);
            //string temp = words[low];
           //words[low] = words[i];
          // words[i] = temp;
        }
        num_comparison++;
    }
    swap(words[i + 1], words[high]);
    return i + 1;
}

void Qsort(vector<string>&items,int low, int high){
    if(low < high){
        int sep = partiton(words,low,high);

        Qsort(words,low,sep -  1);
        Qsort(words,sep + 1, high);
    }
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
            //sSort();
            //InSort();
          Qsort(words,0,words.size());
            letterFile.close();
        }

        for (int i = 0; i < words.size()-1; i++) {
            cout<<words[i]<<"\n";
         }

    }
