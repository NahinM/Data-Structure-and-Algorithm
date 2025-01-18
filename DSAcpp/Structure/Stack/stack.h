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

class Stack
{
private:
    Node *head = nullptr;

public:
    void push(int n);
    int pop();
    int peek();
    bool empty();
};

void Stack::push(int d){
    Node *new_node = new Node(d);
    new_node-> next = head;
    head = new_node;
}

int Stack::peek(){
    return head->data;
}

int Stack::pop(){
    Node *tem = head;
    head = head->next;
    int r = tem->data;
    delete tem;
    return r;
}

bool Stack::empty(){
    return head==nullptr;
}