#include <iostream>
using namespace std;

#define br cout << '\n'

class Node
{
public:
    int data;
    Node *next = nullptr;
    Node(int d){
        data = d;
    }
};

class llist{
private:
    int length = 0;
    
public:
    Node *head = nullptr;
    Node *tail = nullptr;
    int size();
    void push_back(int d);
    void push_front(int d);
    void sort_push(int d);
    void print();
    void del(int index);
    void remove(int data);
};


int llist::size(){
    return length;
}

void llist::push_front(int d){
    Node *new_node = new Node(d);
    if(head==nullptr) tail = new_node;
    new_node->next= head;
    head = new_node;
}

void llist::push_back(int d){
    Node *new_node = new Node(d);
    length++;
    if(head==nullptr){
        head = new_node;
        tail = head;
        return;
    }
    tail->next = new_node;
    tail = tail->next;
}

void llist::sort_push(int d){
    Node *new_node = new Node(d);
    if(head->data >d){
        new_node->next = head;
        head=new_node;
        return;
    }
    
    for(Node *tem = head; tem->next!=nullptr; tem = tem->next){
        if(tem->next->data > d){
            new_node->next = tem->next;
            tem->next = new_node;
            return;
        }
    }
    tail->next = new_node;
    tail = tail->next;
}

void llist::del(int index){
    Node *tem = head;
    if(index<0 || index>=length) return;
    if(index==0){
        head = head->next;
        length--;
        return;
    }
    for(int i=0; tem->next!=nullptr; i++,tem=tem->next){
        if(i+1==index){
            Node *d = tem->next;
            tem->next = d->next;
            delete d;
            if(tem->next==nullptr) tail = tem;
            return;
        }
    }
}

void llist::remove(int data){
    if(head->data == data){
        Node *d = head;
        head = head -> next;
        if(head==nullptr)tail=nullptr;
        delete d;
        return;
    }
    for(Node *tem=head; tem->next!=nullptr; tem = tem->next){
        if(tem->next->data == data){
            Node *d = tem->next;
            tem->next = d->next;
            if(d->next==nullptr)tail = tem;
            delete d;
            return;
        }
    }
}

void llist::print(){
    for(Node *tem = head; tem!=nullptr; tem = tem->next){
        cout << " -> ";
        cout << tem->data;
    }br;
}
