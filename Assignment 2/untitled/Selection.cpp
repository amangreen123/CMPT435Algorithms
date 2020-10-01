//
// Created by aaron on 9/28/2020.
//
#include "Selection.h"
#include<string>
#include<iostream>
#include<vector>

void swap(string *a, string *b){
    string temp = *a;
    *a = *b;
    *b = temp;
}

void sSort(){
    int i,j,imin;//imin index of
    int num_comparison = 0; // incrmeent comparsion
    if(array[j] < array[imin]){
        imin = j;

    }



}

int i, j, imin;
for(i = 0; i<size-1; i++) {
imin = i;   //get index of minimum data
for(j = i+1; j<size; j++)
if(array[j] < array[imin]){
imin = j;
}
num_comparison++;
//placing in correct position
swap(words[i], words[imin]);
}

