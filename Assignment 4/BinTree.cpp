#include "BinTree.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <set>
//
// Created by aaron on 11/18/2020.
//
int comparison = 0;


void storeinorderInSet(Node* root, vector<string>& s)
{
    if (!root || s.size() == 0)
        return;

    for (int i = 0; i < s.size(); i++) {
            if (i + 1 < s.size()) {
                storeinorderInSet(root->left, s);
            } else {
                storeinorderInSet(root->right, s);
            }
        }
}


void setToBST(vector<string>& s, Node* root)
{


    if (!root || s.size() == 0)
        return;
for(int i = 0; i < s.size(); i++){
    root->data = s[i];
    auto it = s.begin();
    s.erase(it);
    if(i+1 < s.size()) {
        if (s[i + 1] < root->data) {
            setToBST(s, root->left);

        } else {
            setToBST(s, root->right);
        }

    }

}

}

void binaryTreeToBST(Node* root)
{
    vector<string> s;

    storeinorderInSet(root, s);
    setToBST(s, root);
   // cout << root->data << " " << "\n" ;
}

Node* newNode(string data)
{
    Node* temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(Node* root, Node* leftBound, Node* rightBound)
{
    if (!root)
        return;
    if (root->data > leftBound->data) {
        if (root->data < rightBound->data) {
            cout << root->data << " " << "\n" ;
        }
        else if (root->data > rightBound->data){
            cout << root->data << " " << "\n" ;
           // inorder(rightBound);
        }
    }
    else if (root < leftBound) {
        cout << root->data << " " << "\n" ;
      //  inorder(leftBound);
    }
    else
        cout << root->data << " " << "\n" ;
    //inorder(root->right);
    //put number comparison
}

