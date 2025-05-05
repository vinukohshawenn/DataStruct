#include <iostream>
using namespace std;

#define n 5  // Stack size

class Stack {
private:
    int top;        // Top index
    char ar[n];     // Character array for stack

public:
    Stack() { top = -1; }  // Initialize top to -1

    void push(char);
    char pop();
    char peek();
    void display();
};

int main() {
    Stack stack;
    char value;
    int choice;

    do {
        cout << "\nChoices: \n";
        cout << "1. Push Operation \n";
        cout << "2. Pop Operation\n";
        cout << "3. Peek Operation\n";
        cout << "4. Display Stack\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the element to insert into the stack: ";
                cin >> value;
                stack.push(value);
                break;

            case 2:
                stack.pop();
                break;

            case 3:
                cout << "Top element: " << stack.peek() << endl;
                break;

            case 4:
                stack.display();
                break;

            case 5:
                cout << "Exited the program.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}

// Corrected push function
void Stack::push(char value) {
    if (top == n - 1) {  // Check overflow
        cout << "Stack Overflow!! Cannot push " << value << endl;
        return;
    }
    ar[++top] = value;  // Increment top and insert
    cout << "Pushed " << value << " into the stack.\n";
}

// Corrected pop function
char Stack::pop() {
    if (top == -1) {  // Check underflow
        cout << "Stack Underflow! Cannot pop.\n";
        return '\0';
    }
    cout << "Popped " << ar[top] << " from the stack.\n";
    return ar[top--];  // Return top element and decrement
}

// Corrected peek function
char Stack::peek() {
    if (top == -1) {
        cout << "Stack is empty! No top element.\n";
        return '\0';
    }
    return ar[top];
}

// Corrected display function
void Stack::display() {
    if (top == -1) {
        cout << "Stack is empty!\n";
        return;
    }
    cout << "Stack elements (Top to Bottom): ";
    for (int i = top; i >= 0; i--)
        cout << ar[i] << " ";
    cout << endl;
}
