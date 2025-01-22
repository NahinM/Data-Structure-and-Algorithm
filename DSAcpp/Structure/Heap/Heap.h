#include <iostream>
#include <vector>
using namespace std;

class Heap
{
private:
    vector<int> arr = {-1};
    int maxHp = 1;
public:
    void insert(int n);
    int top();
    void sink(int n);
    bool empty();
    Heap(bool maxHeap = true){
        maxHp = maxHeap?1:-1;
    }
};

bool Heap::empty(){
    return arr.size()==1;
}

void Heap::insert(int n){
    arr.push_back(maxHp*n);
    for(int at = arr.size()-1; (at>>1)>=1 && arr[at] > arr[at>>1]; at>>=1)
        swap(arr[at],arr[at>>1]);
}

void Heap::sink(int n=1){
    int largest = n;
    if(n*2<arr.size() && arr[largest] < arr[n*2]){
        largest = n*2;
    }
    if(n*2+1<arr.size() && arr[largest] < arr[n*2+1]){
        largest = n*2+1;
    }
    if(largest != n){
        swap(arr[n],arr[largest]);
        sink(largest);
    }
}

int Heap::top(){
    int mx = arr[1];
    arr[1] = arr[arr.size()-1];
    arr.pop_back();
    sink();
    return maxHp*mx;
}