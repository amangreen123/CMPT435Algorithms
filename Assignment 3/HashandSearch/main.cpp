#include<cstdlib>
#include<fstream>
#include<iostream>
#include<string>
#include<vector>
#include <set>

#pragma

using namespace std;

vector<string> words;
int num_comparison = 0;

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

void Merge(vector<string>&mitems, int p,int q,int r){
    int n1 = q - p + 1;
    int n2 = r - q;

    vector<string> leftVector;
    vector<string> rightVector;

    leftVector.resize(n1 + 1);
    rightVector.resize(n2 + 1);

    for(int i = 0; i < n1; i++){
        leftVector.at(i) = mitems.at(p + i);
        //try just p + i if it doesnt work
    }
    for(int j = 0; j < n2; j++){
        rightVector.at(j) = mitems.at(q+j+1);
        //q + 1 + j
    }
    int i,j,k;
    i = 0;
    j = 0;
    k = p;

    while(i < n1 && j < n2){
        if(compare_String(leftVector.at(i),rightVector.at(j)) < 0) {
            words[k] = leftVector.at(i);
            i++;
        }else{
            words[k] = rightVector.at(j);
            j++;
        }
        k++;
        num_comparison++;
    }

    while(i < n1){
        words[k] = leftVector[i];
        i++;
        k++;
    }
    while(j < n2){
        words[k] = rightVector[j];
        j++;
        k++;
    }
}

void Msort(vector<string>&mitems, int leftVect, int rightVect){
    if(leftVect < rightVect){
        int m = leftVect + (rightVect - leftVect) / 2;
        Msort(words,leftVect,m);
        Msort(words,m + 1, rightVect);
        Merge(words,leftVect,m,rightVect);
    }
}

string randomWord(){
    std::set<string> indexes;
//https://stackoverflow.com/questions/13772475/how-to-get-random-and-unique-values-from-a-vector
    while(indexes.size() < min(42,words.size())){ // uses a loop to put random string into a set and stops when it reaches 42
        int randomIndex = rand() % words.size();
        if(indexes.find(randomIndex) == indexes.end()){
            words.push_back(words[randomIndex]);
            indexes.insert(randomIndex);
        }
    }
}
int linearSearch(vector<string> words, string key){
    for(int i = 0; i < words.size(); i++){
       if(words[i] == key ){
            return i;
        }
   }
   return -1;
}

bool binarySearch(vector<string> words, string item) {
    if (words.size() == 0) {
        return false;
    } else {
        int mid = words.size() / 2;
        if (words[mid] == item) {
            return true;
        } else {
            if (item < words[mid]) {
                vector<string> left(words.begin(), words.begin() + mid);
                return binarySearch(left, item);
            } else {
                vector<string> right(words.begin() + mid + 1, words.end());
                return binarySearch(right, item);
            }
        }
    }
}



void openFile(){
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
        letterFile.close();
    }
}

void printFile(){
    for (int i = 0; i < words.size()-1; i++) {
        cout<<words[i]<<"\n";
    }
}

int main()
{
    openFile();
    Msort(words, 0, words.size() - 1);
    printFile();
    words.clear();

    // create a random list variable
    // run a loop through the random list, push items selected into random list
    // maybe do a sort again just to be sure it's sorted
    // run your search functions
}
