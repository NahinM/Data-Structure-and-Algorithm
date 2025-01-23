#include <iostream>
using namespace std;

class Disjn_set
{
private:
    int *arr = nullptr;
    int size = 0;
    int pathCompression(int a);
    int components = 0;
public:
    Disjn_set(int sz){
        arr = new int[sz];
        for(int i=0;i<sz;i++) arr[i]=i;
        components = size = sz;
    }
    int parent(int a);
    int getSize();
    int getComponentNum();
    void frnd(int a, int b);
    void print();
    bool isFrnd(int a, int b);
};

int Disjn_set::getSize(){
    return size;
}

int Disjn_set::getComponentNum(){
    return components;
}

int Disjn_set::pathCompression(int a){
    if(arr[a] == a) return a;
    arr[a] = pathCompression(arr[a]);
    return arr[a];
}

int Disjn_set::parent(int a){
    if(a<0 || a>=size) return -1;
    if(arr[a] == a) return a;
    return pathCompression(a);
}

void Disjn_set::frnd(int a,int b){
    if(a<0 || a>=size || b<0 || b>=size) return;
    arr[parent(a)] = parent(b);
    components--;
}

void Disjn_set::print(){
    for(int i=0;i<size;i++) 
        cout << i << '(' << arr[i] << ") ";
    cout << '\n';
}

bool Disjn_set::isFrnd(int a, int b){
    return parent(a)==parent(b);
}