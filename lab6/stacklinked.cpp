#include <iostream>
using namespace std;

// Node structure for stack
struct Node {
    char data;
    Node* next;
};

// Stack class
class Stack {
private:
    Node* top; 

public:
    Stack() { top = nullptr; } 

    void push(char value);
    char pop();
    char peek();
    void display();
    ~Stack(); // Destructor to free memory
};

int main() {
    Stack stack;
    char value;
    int choice;

    do {
        cout << "\nChoices:\n";
        cout << "1. Push Operation\n";
        cout << "2. Pop Operation\n";
        cout << "3. Peek Operation\n";
        cout << "4. Display Stack\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the character to insert into the stack: ";
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
                cout << "Invalid.\n";
        }
    } while (choice != 5);

    return 0;
}

// Function to push an element onto the stack
void Stack::push(char value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    cout << "Pushed '" << value << "' onto the stack.\n";
}

// Function to pop an element from the stack
char Stack::pop() {
    if (top == nullptr) {
        cout << "Stack Underflow! Cannot pop from an empty stack.\n";
        return '\0';
    }
    char poppedValue = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    cout << "Popped '" << poppedValue << "' from the stack.\n";
    return poppedValue;
}

// Function to get the top element of the stack
char Stack::peek() {
    if (top == nullptr) {
        cout << "Stack is empty! No top element.\n";
        return '\0';
    }
    return top->data;
}

// Function to display the stack elements
void Stack::display() {
    if (top == nullptr) {
        cout << "Stack is empty!\n";
        return;
    }
    cout << "Stack elements (Top to Bottom): ";
    Node* temp = top;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Destructor to free memory
Stack::~Stack() {
    while (top != nullptr) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}
