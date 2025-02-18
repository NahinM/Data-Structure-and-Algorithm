#include <iostream>
#include <vector>
using namespace std;

void print(const vector<int> &arr){
    for(int i:arr) cout << i << ' ';
    cout << '\n';
}

void countSort1(vector<int> &arr){
    int MAX=arr[0], MIN=arr[0], len = arr.size();

    for(int i:arr){
        if(i<MIN) MIN = i;
        if(i>MAX) MAX = i;
    }

    vector<int> count(MAX-MIN+1,0);
    for(int i:arr) count[i-MIN]++;

    int at = 0,i=0;
    while (at<len){
        if(count[i]==0) i++;
        else{
            arr[at++] = i+MIN;
            count[i]--;
        }
    }
    
}

vector<int> countSort2(const vector<int> &arr){
    int MAX=arr[0], MIN=arr[0], len = arr.size();

    for(int i:arr){
        if(i>MAX) MAX=i;
        if(i<MIN) MIN=i;
    }
    
    vector<int> count(MAX-MIN+1,0);
    for(int i:arr) count[i-MIN]++;

    for(int i=1; i<MAX-MIN+1; i++) count[i] += count[i-1];
    
    vector<int> arr2(len);
    for(int i=len-1; i>=0; i--){
        int num = arr[i]-MIN;
        arr2[--count[num]] = num+MIN;
    }
    return arr2;
}

int main(){
    vector <int> arr = {10,16,19,13,17,12,11};
    vector<int> arr2 = countSort2(arr);
    print(arr2);
    countSort1(arr);
    print(arr);
}
