#include <iostream>
#include "hashTB.h"
using namespace std;


int main(){
    HashTB table;
    table.insert("aaa",101);
    table.insert("bbb",102);
    table.insert("ccc",103);
    table.insert("ddd",104);
    table.insert("eee",105);
    table.print();
    cout << table.value("aaa");br;br;
    table.remove("ddd");
    table.print();
}