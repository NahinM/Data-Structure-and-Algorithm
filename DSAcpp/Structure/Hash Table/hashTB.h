#include <iostream>
using namespace std;

#define br cout << '\n'

class kvPair
{
public:
    string key;
    int value;
    kvPair *next = nullptr;
    kvPair(string k, int v){
        key = k;
        value = v;
    }
};

class chain{
private:
    int length = 0;
    
public:
    kvPair *head = nullptr;
    kvPair *tail = nullptr;
    void push(string k, int v);
    void print();
    void remove(string key);
};

void chain::push(string k, int v){
    kvPair *new_kvPair = new kvPair(k,v);
    if(head==nullptr) tail = new_kvPair;
    new_kvPair->next= head;
    head = new_kvPair;
}

void chain::remove(string key){
    if(head->key == key){
        kvPair *d = head;
        head = head -> next;
        if(head==nullptr)tail=nullptr;
        delete d;
        return;
    }
    for(kvPair *tem=head; tem->next!=nullptr; tem = tem->next){
        if(tem->next->key == key){
            kvPair *d = tem->next;
            tem->next = d->next;
            if(d->next==nullptr)tail = tem;
            delete d;
            return;
        }
    }
}

void chain::print(){
    for(kvPair *tem = head; tem!=nullptr; tem = tem->next){
        cout << " -> (" << tem->key << ',' << tem->value << ')';
    }br;
}

class HashTB
{
private:
    chain *table;
    int arr_len = 50;

    int hashfunc(string key){
        int sum = 0;
        for(char c:key) sum+=c;
        return sum%arr_len;
    }

public:
    HashTB(int sz=50){
        table = new chain[sz];
        arr_len = sz;
    }
    void insert(string key,int val);
    void remove(string key);
    int value(string key);
    void readData(kvPair tb[]);
    void print();
};

void HashTB::insert(string key, int val){
    table[hashfunc(key)].push(key,val);
}

void HashTB::remove(string key){
    table[hashfunc(key)].remove(key);
}

int HashTB::value(string key){
    for(kvPair *tem = table[hashfunc(key)].head; tem!=nullptr; tem=tem->next)
        if(tem->key == key) return tem->value;
    return -1;
}

void HashTB::print(){
    for(int i=0;i<arr_len;i++){
        cout << i << " =>> ";
        table[i].print();
    }br;
}