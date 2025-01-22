#include <iostream>
#include "BinTree.h"
#define br cout << '\n'


void preOrder(B_Node *root){
    if(root == nullptr) return;
    cout << root->data << ' ';
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(B_Node *root){
    if(root == nullptr) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << ' ';
}

void inOrder(B_Node *root){
    if(root == nullptr) return;
    inOrder(root->left);
    cout << root->data << ' ';
    inOrder(root->right);
}

int main(){
    vector<int> tree = {0,1,2,3,4,5,6,7,8,9};
    B_Node *root = treeContruct(tree);
    preOrder(root);br;
    postOrder(root);br;
    inOrder(root);br;
}