//Program to build singly linked list undergoing several operations

#include<iostream>
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

public:
    List() : head(nullptr) {}
    void insertbeg(int);
    void insertend(int);
    void insertpos(int, int);
    void delbeg();
    void delend();
    void delpos(int);
    void search(int);
    void display();
    void disrev();
    void revlink();
};

int main() {
    List list;
    int choice, value, pos;
    do {
        cout << "\nEnter your choice: \n";
        cout << "1. Insert Beginning\n";
        cout << "2. Insert End\n";
        cout << "3. Insert at a Position\n";
        cout << "4. Delete Beginning\n";
        cout << "5. Delete End\n";
        cout << "6. Delete at a Position\n";
        cout << "7. Search an Element\n";
        cout << "8. Display Elements\n";
        cout << "9. Display Reverse\n";
        cout << "10. Reverse Linked List\n";
        cout << "11. Exit the program\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter an element to Insert at BEGINNING: ";
                cin >> value;
                list.insertbeg(value);
                break;

            case 2:
                cout << "Enter an element to Insert at END: ";
                cin >> value;
                list.insertend(value);
                break;

            case 3:
                cout << "Enter a position: ";
                cin >> pos;
                cout << "Enter an element to insert at that Position: ";
                cin >> value;
                list.insertpos(pos, value);
                break;

            case 4:
                list.delbeg();
                break;

            case 5:
                list.delend();
                break;

            case 6:
                cout << "Enter a position: ";
                cin >> pos;
                list.delpos(pos);
                break;

            case 7:
                cout << "Enter an element to be searched: ";
                cin >> value;
                list.search(value);
                break;

            case 8:
                cout << "Displaying all elements: ";
                list.display();
                break;

            case 9:
                cout << "Displaying elements in reverse: ";
                list.disrev();
                break;

            case 10:
                cout << "Reversing the linked list... ";
                list.revlink();
                break;

            case 11:
                cout << "Exited the program!\n";
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 11);

    return 0;
}
//Function to insert elements at the beginning of the linked list
void List::insertbeg(int value) {
    Node* newnode = new Node(value);
    newnode->next = head;
    head = newnode;
}

//Function to insert elements at the ending of the Linked list
void List::insertend(int value) {
    Node* newnode = new Node(value);
    if (!head) {
        head = newnode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newnode;
}

//Function to insert elements at a random position in the Linked List
void List::insertpos(int pos, int value) {
    if (pos == 1) {
        insertbeg(value);
        return;
    }
    Node* temp = head;
    for (int i = 1; temp && i < pos - 1; i++) temp = temp->next;
    if (!temp) {
        cout << "Position out of bounds\n";
        return;
    }
    Node* newnode = new Node(value);
    newnode->next = temp->next;
    temp->next = newnode;
}

//Function to delete elements at the beginning of the Linked list
void List::delbeg() {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

//Function to delete elements at the ending of the Linked list
void List::delend() {
    if (!head) return;
    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next) temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
}

//Function to delete elements at a random position of the Linked list
void List::delpos(int pos) {
    if (!head) return;
    if (pos == 1) {
        delbeg();
        return;
    }
    Node* temp = head;
    for (int i = 1; temp->next && i < pos - 1; i++) temp = temp->next;
    if (!temp->next) {
        cout << "Position out of bounds\n";
        return;
    }
    Node* delnode = temp->next;
    temp->next = temp->next->next;
    delete delnode;
}

//Function to search an element in a linked list.
void List::search(int value) {
    Node* temp = head;
    int pos = 1;
    while (temp) {
        if (temp->data == value) {
            cout << "Element found at position: " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Element not found!\n";
}

//Function to display all the elements in a linked list.
void List::display() {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

//Function to display all elements in linked list reversed.
void List::disrev() {
    revlink();
    display();
    revlink();
}
//Function to reverse the linked list.
void List::revlink() {
    Node* prev = nullptr, *current = head, *next = nullptr;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
