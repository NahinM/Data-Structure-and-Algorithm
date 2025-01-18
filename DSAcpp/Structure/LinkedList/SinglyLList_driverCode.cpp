#include <iostream>
#include "singlyllist.h"
using namespace std;

#define rept(i,a,b) for(int i=a; i<b; i++)


int main(){

llist list;
rept(i,1,6)list.push_back(i);

list.printList();
int d;
cin >> d;
list.sort_push(d);
list.printList();
}