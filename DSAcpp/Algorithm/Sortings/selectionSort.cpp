#include <iostream>
using namespace std;

void selectionSort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++)
            if(arr[i]>arr[j]) swap(arr[i],arr[j]);
    }
}

int main(){
    int arr[] = {10,9,8,7,6,5,4,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr,n);
    for(int i=0;i<n;i++) cout << arr[i] << ' ';
    cout << '\n';
}