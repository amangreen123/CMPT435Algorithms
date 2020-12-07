#include "BinTree.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <set>
//
// Created by aaron on 11/18/2020.
//

void BinaryTree::add(string data) {
    if(root == nullptr) {
        root = new Node;
        root->left = nullptr;
        root->right = nullptr;
        root->data = data;
    }
    else {
        add(data, root);
    }
}

void BinaryTree::add(string data, Node *rootNode) {
    if(rootNode->data == data) {
        // duplicate
    }
    else if(rootNode->data > data) {
        if(rootNode->left == nullptr) {
            Node * node = new Node;
            node->left = node->right = nullptr;
            node->data = data;
            rootNode->left = node;
        }
        else {
            add(data, rootNode->left);
        }
    }
    else {
        if(rootNode->right == nullptr) {
            Node * node = new Node;
            node->left = node->right = nullptr;
            node->data = data;
            rootNode->right = node;
        }
        else {
            add(data, rootNode->right);
        }
    }
}

bool BinaryTree::find(string data) {
    comparison = 0;
    return find(data, root);
}


bool BinaryTree::find(string data, Node *rootNode) {
    comparison++;
    if(rootNode == nullptr) {
        return false;
    }
    if(rootNode->data == data) {
        return true;
    }
    else if(rootNode->data > data) {
        return find(data, rootNode->left);

    }
    else {
       return find(data, rootNode->right);
    }
}

int BinaryTree::getComparisons() {
    return comparison;
}
