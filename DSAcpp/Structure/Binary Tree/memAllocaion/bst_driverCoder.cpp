#include <iostream>
#include <vector>
#include "bst.h"

void inOrder(B_Node *root){
    if(root == nullptr) return;
    inOrder(root->left);
    cout << root->data << ' ';
    inOrder(root->right);
}

int main(){
    vector<int> tree = {8,4,9,2,5,1,6,3,7};
    BST bst;
    for(int i:tree) bst.insert(i);
    inOrder(bst.root);
}