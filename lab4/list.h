#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int value) : data(value), next(nullptr) {}
};

class List {
private:
    Node* head;
    Node* getHead() { return head; } 

public:
    List() : head(nullptr) {}

    // Insert in ascending order
    void insertAscending(int val) {
        Node* newNode = new Node(val);
        if (!head || head->data >= val) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next && temp->next->data < val) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Merge two lists into a third list in ascending order
    static List mergeLists(List& l1, List& l2) {
        List merged;
        Node* t1 = l1.getHead();
        Node* t2 = l2.getHead();

        while (t1) {
            merged.insertAscending(t1->data);
            t1 = t1->next;
        }
        while (t2) {
            merged.insertAscending(t2->data);
            t2 = t2->next;
        }

        return merged;
    }

    // Display the list
    void display() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

#endif // LIST_H
