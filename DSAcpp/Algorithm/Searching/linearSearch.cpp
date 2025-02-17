#include <iostream>
#include <vector>
using namespace std;

bool linearSearch(vector<int> &arr, int x){
    for(int i:arr) if(i==x) return true;
    return false;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9};
    if(linearSearch(arr,6))
        cout << "YES\n";
    else
        cout << "NO\n";
}