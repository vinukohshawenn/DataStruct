#include <iostream>
using namespace std;

// Node structure for linked list
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Queue class using linked list
class Queue {
private:
    Node* front;
    Node* rear;
public:
    Queue() : front(nullptr), rear(nullptr) {}
    void enqueue(int value) 
    void dequeue()
    void peek() 
    ~Queue()
};

int main() {
    Queue q;
    int choice, value;
    
    do {
        cout << "\nQueue Operations:\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                cout << "Exited the program." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);
    
    return 0;
}

void Queue::enqueue(int value) {
    Node* newNode = new Node(value);
    if (rear == nullptr) { // If queue is empty
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    cout << "Enqueued: " << value << endl;
}

void Queue::dequeue() {
    if (front == nullptr) {
        cout << "Queue is empty. Cannot dequeue." << endl;
        return;
    }
    Node* temp = front;
    front = front->next;
    if (front == nullptr) rear = nullptr; // If queue is empty after dequeue
    cout << "Dequeued: " << temp->data << endl;
    delete temp;
}

    // Peek operation
void Queue::peek() {
    if (front == nullptr) {
        cout << "Queue is empty." << endl;
    } else {
        cout << "Front element: " << front->data << endl;
    }
}

void Queue::peek() {
    if (front == nullptr) {
        cout << "Queue is empty." << endl;
    } else {
        cout << "Front element: " << front->data << endl;
    }
}

Queue::~Queue() {
    while (front != nullptr) {
        Node* temp = front;
        front = front->next;
        delete temp;
    }
}