#include "d_degreeHeap.h"
#define br cout << '\n'

int main(){
    D_degHeap mxHp(3);
    mxHp.insert(55);
    mxHp.insert(25);
    mxHp.insert(43);
    mxHp.insert(92);
    mxHp.insert(20);
    mxHp.insert(88);
    while(!mxHp.empty()) cout << mxHp.top() << ' ';br;

    D_degHeap minHp(3,false);
    minHp.insert(55);
    minHp.insert(25);
    minHp.insert(43);
    minHp.insert(92);
    minHp.insert(20);
    minHp.insert(88);
    while(!minHp.empty()) cout << minHp.top() << ' ';br;
}