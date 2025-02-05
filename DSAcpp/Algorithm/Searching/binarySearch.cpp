#include <iostream>
#include <vector>
using namespace std;

bool binSearch(const vector<int> &arr,const int x){
    int lw = 0, hi = arr.size()-1;
    int mid = (hi-lw)>>1;

    while (hi-lw<=5)
    {
        if(arr[mid] == x) return true;
        if(x>arr[mid]) lw=mid; else hi = mid;
        mid = (hi-lw)>>1;
    }

    for(int i=lw;i<=hi;i++){
        if(arr[i]==x) return true;
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