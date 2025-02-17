#include <iostream>
#include <vector>
using namespace std;

int ternarySearch(const vector<int> &arr, int a){
    int l=0,h=arr.size(),mid1,mid2;

    // divide the array into three sections
    while(h-l>5){
        mid1 = l+(h-l)/3;
        mid2 = h-(h-l)/3;

        if(a<arr[mid1]) h = mid1; // first part of three section
        else if(arr[mid2]<a) l = mid2; // last part of three section 
        else { // middle part of three section
            l = mid1;
            h = mid2;
        }
    }

    // return the index of the element
    for(int i=l;i<=h;i++) if(arr[i]==a) 
        return i;
    return -1;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    for(int i=0;i<15;i++)
        cout << ternarySearch(arr,i) << '\n';
    return 0;
}
