#include <iostream>
#include <vector>
using namespace std;

bool isSorted(vector<int> &arr){
    for(int i=0;i<arr.size()-1;i++)
        if(arr[i]>arr[i+1]) return false;
    return true;
}

void findpmSort(vector<int> &arr,vector<bool> &visited,vector<int> &container,int i=0){
    static bool sorted = false;
    if(i==arr.size()){
        if(isSorted(container)) {
            sorted = true;
            for(int k=0;k<arr.size();k++) arr[k] = container[k];
        }
        return;
    }

    for(int j=0;j<arr.size();j++) if(!visited[j]) {
        visited[j]=true;
        container[i] = arr[j];
        if(!sorted) findpmSort(arr,visited,container,i+1); else return;
        visited[j]=false;
    }

}

void permutationSort(vector<int> &arr){
    vector<bool> visited(arr.size(),false);
    vector<int> container(arr.size());
    findpmSort(arr,visited,container);
}

int main(){
    vector<int> arr = {10,5,3,7,2,9,22,24,12};
    // vector<int> arr = {3,1,4};
    permutationSort(arr);
    for(int i:arr) cout << i << ' ';
    cout << '\n';
}