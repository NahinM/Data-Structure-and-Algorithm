#include <iostream>
#include <vector>
using namespace std;

class D_degHeap
{
private:
    vector<int> arr;
    int degree = 2;
    int mxHp = 1;
    int parent(int i);
    int child(int p,int i);
public:
    D_degHeap(int d,bool maxHeap);
    void insert(int d);
    void sink(int i);
    int top();
    bool empty();
};

D_degHeap::D_degHeap(int d=2,bool maxHeap = true){
    degree = d;
    mxHp = maxHeap?1:-1;
}

int D_degHeap::parent(int i){
    if(i==0 || i%degree<degree) return 0;
    return (i-(i%degree))/degree;
}

int D_degHeap::child(int p,int i){
    if(p*degree+i >= arr.size()) return -1;
    return p*degree+i;
}

void D_degHeap::insert(int d){
    arr.push_back(d*mxHp);
    // value will swim up
    for(int at = arr.size()-1; at>0 && arr[at]>arr[parent(at)]; at = parent(at))
        swap(arr[at],arr[parent(at)]);
}

void D_degHeap::sink(int i=0){
    int largest = i;

    for(int nth=1;nth<=degree;nth++){
        int nthChild = child(i,nth);
        if(nthChild!=-1 && arr[nthChild]>arr[largest])
            largest = nthChild;
    }

    if(largest != i){
        swap(arr[largest],arr[i]);
        sink(largest);
    }
}

int D_degHeap::top(){
    int tem = arr[0];
    arr[0]=arr[arr.size()-1];
    arr.pop_back();
    sink();
    return tem*mxHp;
}

bool D_degHeap::empty(){
    return arr.size()==0;
}