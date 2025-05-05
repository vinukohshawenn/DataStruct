#ifndef ST_H
#define ST_H

#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
};

class Stack {
private:
    Node* top;
public:
    Stack() { top = nullptr; }
    void push(char value);
    char pop();
    bool isEmpty();
    ~Stack();
};

void Stack::push(char value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

char Stack::pop() {
    if (isEmpty()) return '\0';
    char poppedValue = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return poppedValue;
}

bool Stack::isEmpty() {
    return top == nullptr;
}

Stack::~Stack() {
    while (!isEmpty()) pop();
}

#endif
