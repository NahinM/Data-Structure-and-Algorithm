#include <iostream>
#include "queue.h"
using namespace std;

#define rept(i,a,b) for(int i=a;i<b;i++)
#define br cout << '\n'

int main(){
    Queue q;
    rept(i,0,5) q.push(i);
    while(!q.empty()) cout << q.front() << ' ';br;
}