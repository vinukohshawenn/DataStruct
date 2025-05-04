#include <iostream>
#include <cctype>   // For isdigit()
#include <cstring>  // For string functions
#include "Stack.h"  // Include the Stack ADT

using namespace std;

string infixExpression;
string postfixExpression;

// Function prototypes
int precedence(char op);
bool isOperator(char ch);
string infixToPostfix(string infix);
int evaluatePostfix(string postfix);

int main() {
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Get Infix Expression\n";
        cout << "2. Convert Infix to Postfix\n";
        cout << "3. Evaluate Postfix Expression\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter infix expression: ";
                cin >> infixExpression;
                break;
            case 2:
                postfixExpression = infixToPostfix(infixExpression);
                cout << "Postfix Expression: " << postfixExpression << endl;
                break;
            case 3:
                cout << "Evaluation Result: " << evaluatePostfix(postfixExpression) << endl;
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}

// Function to check precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;  // Right-to-left associativity
    return 0;
}

// Function to check if character is an operator
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Function to convert infix to postfix
string infixToPostfix(string infix) {
    Stack s;
    string postfix = "";
    
    for (char ch : infix) {
        if (isalnum(ch)) {  
            postfix += ch;  
        } else if (ch == '(') {  
            s.push(ch);
        } else if (ch == ')') {  
            while (!s.isEmpty() && s.peek() != '(') {
                postfix += s.pop();
            }
            s.pop();  
        } else if (isOperator(ch)) {  
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(ch)) {
                postfix += s.pop();
            }
            s.push(ch);
        }
    }
    
    while (!s.isEmpty()) {
        postfix += s.pop();
    }
    
    return postfix;
}

// Function to evaluate a postfix expression
int evaluatePostfix(string postfix) {
    Stack s;
    
    for (char ch : postfix) {
        if (isdigit(ch)) {
            s.push(ch - '0');
        } else {
            int operand2 = s.pop();
            int operand1 = s.pop();
            
            switch (ch) {
                case '+': s.push(operand1 + operand2); break;
                case '-': s.push(operand1 - operand2); break;
                case '*': s.push(operand1 * operand2); break;
                case '/': s.push(operand1 / operand2); break;
            }
        }
    }
    
    return s.pop();
}
