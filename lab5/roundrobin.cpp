#include "robin.h"
#include <iostream>
using namespace std;

class Node {
public:
    int time;
    Node* next;
    Node(int t) : time(t), next(nullptr) {}
};

class CL {
private:
    Node* tail;
    int quant;

public:
    CL(int q) : tail(nullptr), quant(q) {}
    ~CL();
    void insert(int time);
    void execute();
};

int main() {
    int quant;
    cout << "Enter time quantum: ";
    cin >> quant;

    CL queue(quant);
    int choice, time;

    do {
        cout << "\nMenu: \n";
        cout << "1. Insert Process\n";
        cout << "2. Execute\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter process time: ";
            cin >> time;
            queue.insert(time);
            break;
        case 2:
            queue.execute();
            break;
        case 3:
            cout << "Exited the program.\n";
            return 0;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice!=3);

    return 0;
}

CL::~CL() {
    if (!tail) return;
    Node* temp = tail->next;
    while (temp != tail) {
        Node* next = temp->next;
        delete temp;
        temp = next;
    }
    delete tail;
    tail = nullptr;
}

void CL::insert(int time) {
    Node* newNode = new Node(time);
    if (!tail) {
        newNode->next = newNode;
        tail = newNode;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
}

void CL::execute() {
    if (!tail) {
        cout << "Queue is empty. No processes to execute.\n";
        return;
    }

    Node* front = tail->next;
    front->time -= quant;
    cout << "Process executed. Remaining time: " << front->time << "\n";

    if (front->time <= 0) {
        cout << "Process completed.\n";
        if (front == tail) {
            delete front;
            tail = nullptr;
        } else {
            tail->next = front->next;
            delete front;
        }
    } else {
        tail = front;
    }
}
