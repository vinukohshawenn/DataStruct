#include <iostream>

#define n 5

using namespace std;

class Queue {
private:
    int current;
    int length;
    int head;
    int arr[n];

public:
    Queue() : current(0), length(0), head(0) {}
    int Enqueue(int);
    int Dequeue();
    void Peek();
};

int main() {
    cout << "Program for queue ADT:\n";

    int choice, val, output;
    Queue queue;

    do {
        cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the element to queue: ";
                cin >> ele;
                output = queue.Enqueue(val);
                if (output == 0) {
                    cout << "Queue Overflow.\n\n";
                } else {
                    cout << "Element added to the Queue.\n\n";
                }
                break;
            case 2:
                output = queue.Dequeue();
                if (output == 0) {
                    cout << "Queue Underflow.\n";
                } else {
                    cout << "The dequeued value:" << output << "\n";
                }
                break;
            case 3:
                Queue1.Peek();
                break;
            case 4:
                cout << "Exited";
                break;
            default:
                cout << "INVALID INPUT.\n";
        }
    } while (choice != 4);

    return 0; 
}

// Function to add an element to the queue
int Queue::Enqueue(int val) {
    if (length + 1 > val) {
        return 0;
    }
    arr[current] = val;
    current = (current + 1) % n;
    length++;
    return 1;
}

// Function to remove the element in queue
int Queue::Dequeue() {
    if (length <= 0) {
        return 0;
    }
    length--;
    int value = arr[head];
    head = (head + 1) % n;
    return value;
}

void Queue::Peek() {
    if (length <= 0) {
        cout << "Queue Underflow.\n\n";
    } else {
        cout << "First in line:" << arr[head] << "\n\n";
    }
}