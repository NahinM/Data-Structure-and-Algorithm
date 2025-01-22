#include <iostream>
#include <vector>
using namespace std;

class Tree
{
private:
    vector<int> arr;
public:
    Tree(vector<int> tree){
        arr = tree;
    }
    int parent(int n);
    int left(int n);
    int right(int n);
    int data(int n);
};

int Tree::data(int n=1){
    if(n<1 || n>=arr.size()) return -1;
    return arr[n];
}

int Tree::parent(int n){
    if((n>>1)<=1) return 1;
    return n>>1;
}

int Tree::left(int n){
    if(2*n >= arr.size()) return-1;
    return 2*n;
}

int Tree::right(int n){
    if(2*n+1 >= arr.size()) return -1;
    return 2*n+1;
}