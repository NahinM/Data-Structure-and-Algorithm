#include <iostream>
#include <vector>
using namespace std;

#define pii pair<int,int>

pii searchRange(const vector<int> &arr,int a){
    // first find the bigining of the "a,a,...,a" sequence
    int l=0,h=arr.size()-1,mid;
    int head = 0, end = h;
    if(a<arr[l] || arr[h]<a) return {-1,-1};
    while (l<=h)
    {
        mid = (h+l)>>1;
        if(arr[mid]==a){
            head = mid;
            h = mid-1;
        } else if(a < arr[mid]) h = mid-1;
        else l = mid+1;
    }
    
    // second, find the end of the "a,a,...,a" sequence
    l=0; h=arr.size()-1;
    while (l<=h)
    {
        mid = (h+l)>>1;
        if(arr[mid]==a){
            end = mid;
            l = mid+1;
        } else if(a < arr[mid]) h = mid-1;
        else l = mid+1;
    }

    return {head,end};
}

int main(){
    vector<int> arr = {1,1,2,2,3,3,3,3,4,4,6,6,7,8,8};
    int a;
    cin >> a;
    pii result = searchRange(arr,a);
    cout << result.first << "," << result.second << '\n';
}
