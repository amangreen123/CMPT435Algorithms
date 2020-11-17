//
// Created by aaron on 11/11/2020.
//

#include "Binary.h"


BinaryTree::BinaryTree() {
   root = NULL;
}


void BinaryTree::insert(string key , BST *leaf) {
    if(key < leaf -> words){
       if(leaf -> left != NULL)
           insert(key, leaf -> left);
       else{
           leaf -> left = new BST;
           leaf -> left -> words = key;
           leaf -> left -> left = NULL;
           leaf -> left -> right = NULL;
       }
    }
    else if (key >= leaf -> words){
        if(leaf -> right != NULL)
            insert(key, leaf -> right);
        else{
            leaf -> right = new BST;
            leaf -> right -> words = key;
            leaf -> right -> left = NULL;
            leaf -> right -> right = NULL;
        }
    }

}

BST *BinaryTree::search(string key, BST *leaf) {
    if(leaf != NULL){
        if(key == leaf -> words)
            return leaf;
        if(key == leaf -> words)
            return search(key, leaf -> left);
        else
            return search(key, leaf -> right);
    }
    else return NULL;
}

void BinaryTree::insert(string key) {
    if(root!=NULL)
        insert(key,root);
    else{
        root = new BST;
        root ->words = key;
        root ->left = NULL;
        root ->right = NULL;
    }
}

BST *BinaryTree::search(string key) {
    return search(key, root);
}


