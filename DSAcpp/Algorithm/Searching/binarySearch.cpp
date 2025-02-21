#include <iostream>
#include <vector>
using namespace std;

bool binSearch(const vector<int> &arr,const int x){
    int lw = 0, hi = arr.size()-1,mid;

    while (lw<=hi)
    {
        mid = (hi+lw)>>1;
        if(arr[mid]==x) return true;
        else if(arr[mid]<x) lw = mid+1;
        else hi = mid-1;
    }
    return false;
}

int main(){
    vector <int> arr(20);
    for(int i=0;i<20;i++) arr[i] = (i+1)*3;

    for(int i=1;i<=40;i++){
        cout << i << "\t: " << (binSearch(arr,i)?"YES\n":"NO\n");
    }
}
