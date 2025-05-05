#include <iostream>
#include "st.h"

using namespace std;

bool isBalancedUsingStack(const string& expr) {
    Stack s;
    
    for (char ch : expr) {
        if (ch == '(') {
            s.push(ch);
        } else if (ch == ')') {
            if (s.isEmpty()) return false;
            s.pop();
        }
    }
    
    return s.isEmpty();
}

int main() {
    int choice;
    string expression;
    
    do {
        cout << "\nMenu:\n";
        cout << "1. Check Balance\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter the expression: ";
                cin >> expression;
                if (isBalancedUsingStack(expression)) {
                    cout << "Balanced!\n";
                } else {
                    cout << "Not Balanced!\n";
                }
                break;
            case 2:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice, try again.\n";
        }
    } while (choice != 2);
    
    return 0;
}
