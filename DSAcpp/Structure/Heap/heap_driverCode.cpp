#include "Heap.h"
#define br cout << '\n';

int main(){
    Heap mxhp;
    mxhp.insert(3);
    mxhp.insert(10);
    mxhp.insert(6);
    mxhp.insert(32);

    while(!mxhp.empty())
    cout << mxhp.top() << ' ';br;

    Heap minhp(false);
    minhp.insert(3);
    minhp.insert(10);
    minhp.insert(6);
    minhp.insert(32);

    while(!minhp.empty())
    cout << minhp.top() << ' ';br;
}