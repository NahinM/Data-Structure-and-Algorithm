#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100;

void countSort(vector<int> &arr){
    vector<bool> mark(MAX,false);
    for(int i:arr) mark[i] = true;
    int at = 0;
    for(int i=0; i<MAX && at<arr.size(); i++)
        if(mark[i]) arr[at++] = i;
}

int main(){
    vector <int> arr = {8,7,6,5,4,1,2,3};
    countSort(arr);
    for(int i:arr) cout << i << ' ';
    cout << '\n';
}