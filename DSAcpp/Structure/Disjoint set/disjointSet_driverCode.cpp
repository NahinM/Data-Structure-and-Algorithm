#include "disjointSet.h"


int main(){
    Disjn_set set(10);

    set.frnd(4,5);
    set.print();
    set.frnd(6,5);
    set.print();
    set.frnd(8,5);
    set.print();
    set.frnd(8,9);
    set.print();

    cout << set.isFrnd(4,5) << '\n';
    cout << set.isFrnd(6,5) << '\n';
    cout << set.isFrnd(8,5) << '\n';
    cout << set.isFrnd(8,9) << '\n';
    set.print();
    
    cout << set.getComponentNum() << '\n';
}