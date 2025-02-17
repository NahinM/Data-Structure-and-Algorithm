#include <iostream>
#include <vector>
using namespace std;

#define vi vector<int>

void quickSort(vi &arr, int l, int h){
    if(h-l < 2) return;

    int pivot = h;
    int i = l, j = pivot-1;

    while(i<j){
        if(arr[i] > arr[j]) swap(arr[i], arr[j]);
        while(arr[i] < arr[pivot]) i++;
        while(arr[j] > arr[pivot]) j--;
    } swap(arr[i], arr[pivot]);

    quickSort(arr, 0, i-1);
    quickSort(arr, i+1, h);
}

int main(){
    vi arr = {4,10,11,2,9,14,1,16,6,5,15};
    quickSort(arr, 0, arr.size()-1);
    for(auto i:arr) cout << i << ' '; cout << '\n';
}