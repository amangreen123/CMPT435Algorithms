//
// Created by aaron on 11/18/2020.
//

#include "BinTree.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <set>
//
// Created by aaron on 11/18/2020.
//

void storeinorderInSet(Node* root, set<string>& s)
{
    if (!root)
        return;

    storeinorderInSet(root->left, s);
    s.insert(root->data);
    storeinorderInSet(root->right, s);
}


void setToBST(set<string>& s, Node* root)
{
    if (!root)
        return;

    setToBST(s, root->left);

    auto it = s.begin();

    root->data = *it;
    s.erase(it);
    setToBST(s, root->right);
}

void binaryTreeToBST(Node* root)
{
    set<string> s;

    storeinorderInSet(root, s);
    setToBST(s, root);
}

Node* newNode(string data)
{
    Node* temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(Node* root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
    //put number comparison
}

