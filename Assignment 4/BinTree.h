//
// Created by aaron on 11/18/2020.
//

#ifndef BINARY_CPP_BINTREE_H
#define BINARY_CPP_BINTREE_H

#endif //BINARY_CPP_BINTREE_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <set>

using namespace std;

struct Node {
    string data;
    struct Node *left, *right;
};

class BinaryTree {
public:
    void add(string data);
    bool find(string data);
    int getComparisons();

private:
    struct Node *root = nullptr;
    int comparison;
    void add(string data, Node *);
    bool find(string data, Node *);
};