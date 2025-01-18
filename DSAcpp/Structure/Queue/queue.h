#include <iostream>

class Node
{
public:
    int data;
    Node *next = nullptr;
    Node(int d){
        data = d;
    }
};

class Queue
{
private:
    Node *head = nullptr;
    Node *tail = nullptr;

public:
    void push(int d);
    int front();
    int peek();
    bool empty();
};

void Queue::push(int d){
    Node *new_node = new Node(d);
    if(head == nullptr){
        head = new_node;
        tail = head;
        return;
    }
    tail->next = new_node;
    tail = tail->next;
}

int Queue::front(){
    if(head==nullptr) return -1;
    int r = head->data;
    Node *tem = head;
    head = head->next;
    if(head==nullptr) tail=nullptr;
    delete tem;
    return r;
}

int Queue::peek(){
    return head->data;
}

bool Queue::empty(){
    return head==nullptr;
}
