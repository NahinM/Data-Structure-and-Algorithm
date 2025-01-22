#include "binTree.h"
#define br cout << '\n';

void preOrder(Tree &tree,int r=1){
    if(r==-1) return;
    cout << tree.data(r) << ' ';
    preOrder(tree, tree.left(r));
    preOrder(tree, tree.right(r));
}

void postOrder(Tree &tree,int r=1){
    if(r==-1) return;
    postOrder(tree, tree.left(r));
    postOrder(tree, tree.right(r));
    cout << tree.data(r) << ' ';
}

void inOrder(Tree &tree,int r=1){
    if(r==-1) return;
    inOrder(tree, tree.left(r));
    cout << tree.data(r) << ' ';
    inOrder(tree, tree.right(r));
}

int main(){
    Tree tree({-1,0,1,2,3,4,5,6,7,8,9});
    inOrder(tree);br;
    preOrder(tree);br;
    postOrder(tree);br;
}