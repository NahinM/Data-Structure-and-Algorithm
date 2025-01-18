#include <iostream>
#include "stack.h"
using namespace std;

#define rept(i,a,b) for(int i=a;i<b;i++)
#define br cout << '\n'

int main(){
    Stack stk;
    rept(i,0,5) stk.push(i);
    while(!stk.empty()) cout << stk.pop() << ' ';br;
}