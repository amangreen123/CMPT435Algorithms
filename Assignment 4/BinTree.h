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

void storeinorderInSet(Node* root, set<string>& s);
void setToBST(set<string>& s, Node* root);
void binaryTreeToBST(Node* root);
void inorder(Node* root);
Node* newNode(string data);

