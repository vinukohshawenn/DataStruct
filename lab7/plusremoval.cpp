#include <iostream>
#include <stack>
using namespace std;

// Function to process the input string
string processString(const string& input) {
    stack<char> s;
    
    for (char ch : input) {
        if (ch == '+') {
            if (!s.empty()) {
                s.pop(); 
            }
        } else {
            s.push(ch); 
        }
    }
    
    // Construct the final string from the stack
    string result;
    while (!s.empty()) {
        result = s.top() + result;
        s.pop();
    }
    
    return result;
}

int main() {
    string input;
    cout << "Enter a string with '+': ";
    cin >> input;
    
    string output = processString(input);
    cout << "Processed string: " << output << endl;
    
    return 0;
}
