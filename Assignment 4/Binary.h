//
// Created by aaron on 11/11/2020.
//

#ifndef ASSIGNMENT_4_BINARY_H
#define ASSIGNMENT_4_BINARY_H

#endif //ASSIGNMENT_4_BINARY_H
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

//My binary code just disappeared

struct BST{
    string words;
    BST *left;
    BST *right;
};


class BinaryTree{
public:
    BinaryTree();
    ~BinaryTree();

    void insert(string key);
    BST *search(string key);

private:
    void insert(string key, BST *leaf);
    BST *search(string key, BST *leaf);

    BST* root;
};