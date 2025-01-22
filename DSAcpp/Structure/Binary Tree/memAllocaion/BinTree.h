#include <iostream>
#include <vector>
using namespace std;

class B_Node
{
public:
    int data;
    B_Node *left = nullptr;
    B_Node *right = nullptr;
    B_Node(int d){
        data = d;
    }
};

// 1 indexed tree construction
B_Node* treeContruct(vector<int> &arr, int i=1){
    if(i<0 || i>= arr.size()) return nullptr;
    B_Node *root = new B_Node(arr[i]);
    root->left = treeContruct(arr,2*i);
    root->right = treeContruct(arr,2*i+1);
    return root;
}