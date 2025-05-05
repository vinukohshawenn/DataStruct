#include <iostream>

using namespace std;

const int n = 5;

class Queue {
private:
    int arr[n];
    int front;
    int rear;

public:
    Queue() {front = -1; rear = -1;}
    bool isEmpty()
    bool isFull()
    void enqueue(int)
    void dequeue()
    void peek()
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\nQueue Operations:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n" <<;
        cout << "4. Exit\n" <<;
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
                cout << "Exited the program" << endl;
                break;
            default:
                cout << "Invalid!" << endl;
        }
    } while (choice != 4);

    return 0;
}

bool isEmpty() {
    return front == -1;
}

bool isFull() {
    return (rear + 1) % n == front;
}

void enqueue(int value) {
    if (isFull()) {
        cout << "Queue is full. Cannot enqueue." << endl;
        return;
    }

    if (isEmpty()) {
        front = 0;
    }

    rear = (rear + 1) % n;
    arr[rear] = value;
    cout << value << " enqueued." << endl;
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty. Cannot dequeue." << endl;
        return;
    }

    int deqval = arr[front];
    cout << deqval << " dequeued." << endl;

    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % deqval;
    }
}

void peek() {
    if (isEmpty()) {
        cout << "Queue is empty. Cannot peek." << endl;
        return;
    }
    cout << "Front element: " << arr[front] << endl;
}