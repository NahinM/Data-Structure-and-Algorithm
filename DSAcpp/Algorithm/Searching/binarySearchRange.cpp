#include <iostream>
#include <vector>
using namespace std;

#define pii pair<int,int>

pii searchRange(const vector<int> &arr,int a){
    // first find the bigining of the "a,a,...,a" sequence
    int l=0,h=arr.size()-1,mid;
    while (h-l>5)
    {
        mid = (h+l)>>1;
        if(a <= arr[mid]) h = mid; else l = mid;
    }
    int head=l;
    while (head<=h && arr[head]!=a) head++;

    // second, find the end of the "a,a,...,a" sequence
    l=0; h=arr.size()-1;
    while (h-l>5)
    {
        mid = (h+l)>>1;
        if(a >= arr[mid]) l = mid; else h = mid;
    }
    int end=h;
    while(end>=l && arr[end]!=a)end--;
    return {head,end};
}

int main(){
    vector<int> arr = {1,1,2,2,3,3,3,3,4,4,6,6,7,8,8};
    int a;
    cin >> a;
    pii result = searchRange(arr,a);
    cout << result.first << "," << result.second << '\n';
}