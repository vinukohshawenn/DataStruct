#include<iostream>
using namespace std;

// Creating classes for node and doubly linked list.
class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class DL {
private:
    Node* head;
    Node* tail;

public:
    DL() : head(nullptr), tail(nullptr) {}
    void insertbeg(int);
    void insertend(int);
    void insertpos(int, int);
    void delbeg();
    void delend();
    void delpos(int);
    void search(int);
    void display();
};

int main() {
    DL dl;
    int choice, value, pos;
    do {
        cout << "\nChoices: \n";
        cout << "1. Insert at the Beginning of Doubly Linked List\n";
        cout << "2. Insert at the End of the Doubly Linked List\n";
        cout << "3. Insert at a Position in the Doubly Linked List\n";
        cout << "4. Delete at the Beginning of the Doubly Linked List\n";
        cout << "5. Delete at the End of the Doubly Linked List\n";
        cout << "6. Delete at a Position\n";
        cout << "7. Search an element\n";
        cout << "8. Display all the elements\n";
        cout << "9. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter an element to insert at the BEGINNING: ";
            cin >> value;
            dl.insertbeg(value);
            break;
        case 2:
            cout << "Enter the element to insert at the END: ";
            cin >> value;
            dl.insertend(value);
            break;
        case 3:
            cout << "Enter an element: ";
            cin >> value;
            cout << "Enter the position: ";
            cin >> pos;
            dl.insertpos(pos, value);
            break;
        case 4:
            dl.delbeg();
            break;
        case 5:
            dl.delend();
            break;
        case 6:
            cout << "Enter a position: ";
            cin >> pos;
            dl.delpos(pos);
            break;
        case 7:
            cout << "Enter an element to search: ";
            cin >> value;
            dl.search(value);
            break;
        case 8:
            cout << "Displaying all the elements: \n";
            dl.display();
            break;
        case 9:
            cout << "Exited the Program.\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 9);
    return 0;
}

// Function to insert elements at the Beginning.
void DL::insertbeg(int value) {
    Node* newnode = new Node(value);
    if (!head) {
        head = tail = newnode;
    } else {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}

// Function to insert elements at the End.
void DL::insertend(int value) {
    Node* newnode = new Node(value);
    if (!tail) {
        head = tail = newnode;
    } else {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}

// Function to insert elements at a Position.
void DL::insertpos(int pos, int value) {
    if (pos <= 0) {
        cout << "Invalid position!\n";
        return;
    }
    if (pos == 1 || !head) {
        insertbeg(value);
        return;
    }
    Node* newnode = new Node(value);
    Node* temp = head;
    int count = 1;

    while (temp && count < pos - 1) {
        temp = temp->next;
        count++;
    }

    if (!temp) {
        cout << "Position out of range!\n";
        return;
    }

    newnode->next = temp->next;
    newnode->prev = temp;

    if (temp->next) {
        temp->next->prev = newnode;
    } else {
        tail = newnode;
    }

    temp->next = newnode;
}

// Function to delete elements at the Beginning.
void DL::delbeg() {
    if (!head) {
        cout << "List is empty!\n";
        return;
    }
    Node* temp = head;
    head = head->next;

    if (head) {
        head->prev = nullptr;
    } else {
        tail = nullptr;
    }

    delete temp;
}

// Function to delete elements at the End.
void DL::delend() {
    if (!tail) {
        cout << "List is empty!\n";
        return;
    }
    Node* temp = tail;
    tail = tail->prev;

    if (tail) {
        tail->next = nullptr;
    } else {
        head = nullptr;
    }

    delete temp;
}

// Function to delete an element at a specific Position.
void DL::delpos(int pos) {
    if (!head || pos <= 0) {
        cout << "Invalid Position\n";
        return;
    }
    if (pos == 1) {
        delbeg();
        return;
    }
    Node* temp = head;
    int count = 1;

    while (temp && count < pos) {
        temp = temp->next;
        count++;
    }

    if (!temp) {
        cout << "Position out of range\n";
        return;
    }

    if (temp->next) {
        temp->next->prev = temp->prev;
    } else {
        tail = temp->prev;
    }

    if (temp->prev) {
        temp->prev->next = temp->next;
    }

    delete temp;
}

// Function to search for an element.
void DL::search(int value) {
    Node* temp = head;
    int pos = 1;
    while (temp) {
        if (temp->data == value) {
            cout << "Element found at index: " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Element not found.\n";
}

// Function to display all the elements.
void DL::display() {
    if (!head) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;
    cout << "From Head: \n";
    while (temp) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";

    cout << "From Tail:\n";
    temp = tail;
    while (temp) {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    }
    cout << "NULL\n";
}
