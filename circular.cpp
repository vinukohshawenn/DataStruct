//Program to implement List ADT operationsn using Circular Linked List. 
#include <iostream>
using namespace std;
//Creating classes for node and circular linked list.
class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class CL {
private:
    Node* tail;

public:
    CL() : tail(nullptr) {}
    ~CL();
    void insertbeg(int);
    void insertend(int);
    void insertpos(int, int);
    void delbeg();
    void delend();
    void delpos(int);
    int search(int);  // Changed return type from void to int
    void display();
};

int main() {
    CL cl;
    int choice, value, pos;

    do {
        cout << "\nChoices:\n";
        cout << "1. Insert Beginning\n";
        cout << "2. Insert End\n";
        cout << "3. Insert Position\n";
        cout << "4. Delete Beginning\n";
        cout << "5. Delete End\n";
        cout << "6. Delete Position\n";
        cout << "7. Search\n";
        cout << "8. Display\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the value: ";
            cin >> value;
            cl.insertbeg(value);
            break;
        case 2:
            cout << "Enter the value: ";
            cin >> value;
            cl.insertend(value);
            break;
        case 3:
            cout << "Enter the value: ";
            cin >> value;
            cout << "Enter the index: ";
            cin >> pos;
            cl.insertpos(value, pos);  // Fixed parameter order
            break;
        case 4:
            cl.delbeg();
            break;
        case 5:
            cl.delend();
            break;
        case 6:
            cout << "Enter the index: ";
            cin >> pos;
            cl.delpos(pos);
            break;
        case 7:
            cout << "Enter the element to search: ";
            cin >> value;
            cl.search(value);
            break;
        case 8:
            cl.display();
            break;
        case 9:
            cout << "Exited the program.\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 9);

    return 0;
}
//Function to implement a Circular Linked list
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
//Function to add elements at the Beginning of the linked list.
void CL::insertbeg(int value) {
    Node* newNode = new Node(value);
    if (!tail) {
        newNode->next = newNode;
        tail = newNode;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
    }
}
//Function to add elements at the end of the linked list.
void CL::insertend(int value) {
    Node* newNode = new Node(value);
    if (!tail) {
        newNode->next = newNode;
        tail = newNode;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
}
//Function to add elements at a random position of a linked list.
void CL::insertpos(int value, int position) {
    if (position < 0) return;
    if (position == 0) {
        insertbeg(value);
        return;
    }

    Node* newNode = new Node(value);
    Node* temp = tail->next;
    int currentPos = 0;
    while (currentPos < position - 1) {
        temp = temp->next;
        currentPos++;
        if (temp == tail->next) {
            delete newNode;
            return;
        }
    }
    newNode->next = temp->next;
    temp->next = newNode;
    if (temp == tail) tail = newNode;
}
//Function to delete an element at the beginnning of the linked list.
void CL::delbeg() {
    if (!tail) return;
    Node* head = tail->next;
    if (head == tail) {
        delete tail;
        tail = nullptr;
    } else {
        tail->next = head->next;
        delete head;
    }
}
//Function to delete elements at the end of the linked list.
void CL::delend() {
    if (!tail) return;
    Node* head = tail->next;
    if (head == tail) {
        delete tail;
        tail = nullptr;
    } else {
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        temp->next = head;
        delete tail;
        tail = temp;
    }
}
//Function to delete elements at a given random position.
void CL::delpos(int pos) {
    if (!tail || pos < 0) return;
    if (pos == 0) {
        delbeg();
        return;
    }

    Node* temp = tail->next;
    Node* prev = nullptr;
    int currentPos = 0;
    while (currentPos < pos) {
        prev = temp;
        temp = temp->next;
        currentPos++;
        if (temp == tail->next) return;
    }
    prev->next = temp->next;
    if (temp == tail) tail = prev;
    delete temp;
}
//Function to search an element.
int CL::search(int value) {
    if (!tail) {
        cout << "List is empty. Cannot search.\n";
        return -1;
    }
    Node* temp = tail->next;
    int pos = 0;
    do {
        if (temp->data == value) {
            cout << "Element " << value << " found at index: " << pos << endl;
            return pos;
        }
        temp = temp->next;
        pos++;
    } while (temp != tail->next);
    
    cout << "Element " << value << " not found\n";
    return -1;
}
//Function to display all the elements.
void CL::display() {
    if (!tail) {
        cout << "List is empty. Cannot display elements.\n";
        return;
    }
    Node* temp = tail->next;
    cout << "The elements in the list are: ";
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != tail->next);
    cout << "(circular)\n";
}
