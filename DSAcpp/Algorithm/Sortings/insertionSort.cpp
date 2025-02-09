#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &arr){
    for(int i=1; i<arr.size(); i++){
        int key = arr[i];
        int j=i-1;
        while (j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main(){
    vector<int> arr = {10,9,8,7,6,5,4,3,2,1};
    insertionSort(arr);
    for(int i:arr) cout << i << ' ';
    cout << '\n';

}