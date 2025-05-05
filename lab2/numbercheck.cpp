#include <iostream>
#include <cmath>

using namespace std;

void isPalindrome(int* num) {
    int* original = new int(*num);
    int* temp = new int(*num);
    int* sum = new int(0);
    int* rem = new int;

    while (*temp > 0) {
        *rem = (*temp) % 10;
        *sum = (*sum) * 10 + (*rem);
        *temp = (*temp) / 10;
    }

    if (*original == *sum) {
        cout << "Palindrome" << endl;
    } else {
        cout << "Not a Palindrome" << endl;
    }

    delete sum;
    delete temp;
    delete original;
    delete rem;
}

void isArmstrong(int* num) {
    int* original = new int(*num);
    int* temp = new int(*num);
    int* size = new int(0);

    while (*temp > 0) {
        (*size)++;
        *temp = (*temp) / 10;
    }

    *temp = *num;
    int* rem = new int;
    int* sum = new int(0);

    while (*temp > 0) {
        *rem = (*temp) % 10;
        *sum = (*sum) + pow(*rem, *size);  
        *temp = (*temp) / 10;  
    }

    if (*original == *sum) {
        cout << *num << " is an Armstrong Number!" << endl;
    } else {
        cout << *num << " is NOT an Armstrong Number!" << endl;
    }

    delete sum;
    delete rem;
    delete original;
    delete temp;
    delete size;
}

void isPerfect(int* num) {
    int* original = new int(*num);
    int* sum = new int(0);

    for (int i = 1; i < *num; i++) {
        if (*num % i == 0) {
            *sum += i;
        }
    }

    if (*original == *sum) {
        cout << *num << " is a Perfect Number!" << endl;
    } else {
        cout << *num << " is NOT a Perfect Number!" << endl;
    }

    delete sum;
    delete original;
}

int main() {
    while (true) {
        cout << "\nEnter your choice:";
        cout << "\n1. Palindrome\n2. Armstrong Number\n3. Perfect Number\n4. Exit\n";

        int* choice = new int;
        cin >> *choice;

        int* num = new int;     

        switch (*choice) {
            case 1:
                cout << "Enter the number to check: ";
                cin >> *num;
                isPalindrome(num);
                break;

            case 2:
                cout << "Enter the number to check: ";
                cin >> *num;
                isArmstrong(num);
                break;

            case 3:
                cout << "Enter the number to check: ";
                cin >> *num;
                isPerfect(num);
                break;

            case 4:
                cout << "Exiting the program." << endl;
                delete num;
                delete choice;
                return 0;

            default:
                cout << "Invalid Input!" << endl;
        }

        delete num;  // Free memory after each use
        delete choice;
    }

    return 0;
}
