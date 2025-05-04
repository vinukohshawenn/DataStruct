
#include <iostream>
#include "list.h"

using namespace std;

int main() {
    List list1, list2, list3;
    int choice, value;

    do {
        cout << "Choices: \n";
        cout << "1. Insert into List1\n";
        cout << "2. Insert into List2\n";
        cout << "3. Merge List1 & List2 into List3\n";
        cout << "4. Display Lists\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert in List1: ";
                cin >> value;
                list1.insertAscending(value);
                break;
            
            case 2:
                cout << "Enter value to insert in List2: ";
                cin >> value;
                list2.insertAscending(value);
                break;

            case 3:
                list3 = List::mergeLists(list1, list2);
                cout << "Lists merged into List3.\n";
                break;

            case 4:
                cout << "List1: ";
                list1.display();
                cout << "List2: ";
                list2.display();
                cout << "List3 (Merged): ";
                list3.display();
                break;

            case 5:
                cout << "Exited the program. \n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
