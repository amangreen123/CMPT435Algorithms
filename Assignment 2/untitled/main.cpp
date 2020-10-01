#include<cstdlib>
#include<fstream>
#include<iostream>
#include<string>
#include<vector>
#pragma

using namespace std;

vector<string> words;
int num_comparison = 0; // increment comparsion

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}


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
        imin = 1; //index of minium data
        for (j = i + 1; j < words.size(); j++) {
            if (j >= 0 && compare_String(words[i],words[imin]) > 0) {
                imin = j;
            }
            swap(words[j], words[imin]);
            num_comparison++;
        }

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
            //InSort();
            letterFile.close();
        }



        for (int i = 0; i < words.size()-1; i++) {
             cout<<words[i]<<"\n";
         }

    }
