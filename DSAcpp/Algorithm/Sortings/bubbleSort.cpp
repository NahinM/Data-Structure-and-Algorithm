#include <iostream>
#include <vector>
using namespace std;

void printArr(const vector<int> &arr){
    for(int i:arr) cout << i << ' ';
    cout << '\n';
}

void bubbleSort(vector<int> &arr){
    bool sorted = false;
    int n = arr.size();
    for(int i=0;i<n && !sorted;i++){
        sorted = true;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]) {
                swap(arr[j],arr[j+1]);
                sorted = false;
            }
        }
    }
}

int main(){
    vector<int> arr = {1,2,3,4,10,9,8,7,6,5};
    bubbleSort(arr);
    printArr(arr);
}