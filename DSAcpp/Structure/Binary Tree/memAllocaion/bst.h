#include <iostream>
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

class BST
{
public:
    B_Node* root = nullptr;
    void insert(int d);
};

void BST::insert(int d){
    if(root == nullptr) {
        root = new B_Node(d);
        return;
    }

    B_Node *tem = root;
    while(tem != nullptr){
        if(tem->data==d) return;
        if(tem->data >d) {
            if(tem->left==nullptr){
                tem->left = new B_Node(d);
                return;
            }
            tem = tem->left;

        }else {
            if(tem->right==nullptr){
                tem->right = new B_Node(d);
                return;
            }
            tem = tem->right;
        }
    }
}