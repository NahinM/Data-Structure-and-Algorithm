#include <iostream>
#include <vector>
using namespace std;

void printArr(const vector<int> &arr){
    for(int i:arr) cout << i << ' ';
    cout << '\n';
}

vector<int> copy(const vector<int> & arr,int l, int r){
    vector<int> copyArr((r-l+1));
    for(int i=l;i<=r;i++) copyArr[i-l] = arr[i];
    return copyArr;
}

void marge(const vector<int> &arr1, const vector<int> &arr2, vector<int> &into){
    int i1=0,i2=0,a=0;
    while(a<into.size()){
        while(i1<arr1.size() && (arr1[i1]<arr2[i2] || i2==arr2.size())){
            into[a++] = arr1[i1++];
        }
        while(i2<arr2.size() && (arr2[i2]<arr1[i1] || i1==arr1.size())){
            into[a++] = arr2[i2++];
        }
    }
}

void mergeSort(vector<int> &arr){
    int left = 0, right=arr.size()-1;
    if (left>=right) return;
    
    int mid = (right-left)>>1;

    vector<int> arr1 = copy(arr,left,mid);
    mergeSort(arr1);

    vector<int> arr2 = copy(arr,mid+1,right);
    mergeSort(arr2);

    marge(arr1,arr2,arr);
}

int main(){
    vector<int> arr = {10,9,8,7,6,5,4,3,2,1};
    mergeSort(arr);
    printArr(arr);
}