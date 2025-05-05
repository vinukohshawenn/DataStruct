#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

// Node structure
struct Node {
    char data;
    Node* next;
};

// Stack class using singly linked list
class Stack {
private:
    Node* top;

public:
    Stack() { top = nullptr; }
    void push(char value);
    char pop();
    char peek();
    bool isEmpty();
    ~Stack();
};

// Push function
void Stack::push(char value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// Pop function
char Stack::pop() {
    if (isEmpty()) {
        cout << "Stack Underflow!\n";
        return '\0';
    }
    char poppedValue = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return poppedValue;
}

char Stack::peek() {
    if (top == nullptr) {
        cout << "Stack is empty! No top element.\n";
        return '\0';
    }
    return top->data;
}



// Destructor to free memory
Stack::~Stack() {
    while (top != nullptr) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

#endif

