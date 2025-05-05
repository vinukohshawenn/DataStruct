#include<iostream>
#include<algorithm>
#define n 5
using namespace std;

class List {
private:
    int currentsize = 0;
    int current = 0;
    int ar[n];

public:
    int insertbeg(int);
    int insertend(int);
    int insertpos(int, int);
    void display();
    int search(int);
    int delbeg();
    int delend();
    int delpos(int);
    void rotate(int);
};

int main() {
    List list;
    int choice, value, pos, k;

    cout << "Choices: \n";
    cout << "1. Insert Beginning\n";
    cout << "2. Insert End\n";
    cout << "3. Insert Position\n";
    cout << "4. Delete Beginning\n";
    cout << "5. Delete End\n";
    cout << "6. Delete Position\n";
    cout << "7. Search\n";
    cout << "8. Display\n";
    cout<<"9. Rotate\n";
    cout << "10. Exit\n";

    do {
        cout << "Enter your choice: \n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the number to be inserted: \n";
                cin >> value;
                list.insertbeg(value);
                break;

            case 2:
                cout << "Enter the number to be inserted: \n";
                cin >> value;
                list.insertend(value);
                break;

            case 3:
                cout << "Enter the position: \n";
                cin >> pos;
                cout << "Enter the number to be inserted: \n";
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
                cout << "Enter the position: \n";
                cin >> pos;
                list.delpos(pos);
                break;

            case 7:
                cout << "Enter the element to be searched: \n";
                cin >> value;
                list.search(value);
                break;

            case 8:
                cout << "Displaying Elements: \n";
                list.display();
                break;

            case 9:
                    cout<<"Enter the rotation count:m \n";
                    cin>>k;
                    list.rotate(k);
                    break;
            case 10:
                cout << "Exited the program! \n";
                break;

            default:
                cout << "Invalid!\n";
        }
    } while (choice != 10);

    return 0;
}

// Insert element at the beginning
int List::insertbeg(int value) {
    if (currentsize >= n) {
        cout << "List is full" << endl;
        return -1;
    }
    for (int i = currentsize; i > 0; i--) {
        ar[i] = ar[i - 1];
    }
    ar[0] = value;
    currentsize++;
    current = currentsize - 1;
    return 0;
}

// Insert element at the end
int List::insertend(int value) {
    if (currentsize >= n) {
        cout << "List is full" << endl;
        return -1;
    }
    ar[currentsize] = value;
    currentsize++;
    current = currentsize - 1;
    return 0;
}

// Insert element at a given position
int List::insertpos(int pos, int value) {
    if (currentsize >= n) {
        cout << "List is full!" << endl;
        return -1;
    }
    for (int i = currentsize; i > pos; i--) {
        ar[i] = ar[i - 1];
    }
    ar[pos] = value;
    currentsize++;
    current = currentsize - 1;
    return 0;
}

// Delete element from beginning
int List::delbeg() {
    if (currentsize == 0) {
        cout << "Empty List" << endl;
        return -1;
    }
    int delval = ar[0];
    for (int i = 0; i < currentsize - 1; i++) {
        ar[i] = ar[i + 1];
    }
    currentsize--;
    current = currentsize - 1;
    return delval;
}

// Delete element from end
int List::delend() {
    if (currentsize == 0) {
        cout << "Empty List" << endl;
        return -1;
    }
    currentsize--;
    current = currentsize - 1;
    return ar[current];
}

// Delete element from a given position
int List::delpos(int pos) {
    if (currentsize == 0) {
        cout << "Empty List" << endl;
        return -1;
    }
    int delval = ar[pos];
    for (int i = pos; i < currentsize - 1; i++) {
        ar[i] = ar[i + 1];
    }
    currentsize--;
    current = currentsize - 1;
    return delval;
}

// Display elements
void List::display() {
    if (currentsize == 0) {
        cout << "List is empty!" << endl;
        return;
    }
    for (int i = 0; i < currentsize; i++) {
        cout << ar[i] << " ";
    }
    cout << endl;
}

// Search for an element
int List::search(int value) {
    for (int i = 0; i < currentsize; i++) {
        if (ar[i] == value) {
            cout << "Element found at index: " << i << endl;
            return i;
        }
    }
    cout << "Element not found!" << endl;
    return -1;
}

    void List::rotate(int k) {
        if (currentsize == 0) return;
        k = k % currentsize;
        reverse(ar, ar + currentsize);
        reverse(ar, ar + k);
        reverse(ar + k, ar + currentsize);
    }