#ifndef ROBIN_H
#define ROBIN_H

#include <iostream>
using namespace std;

class Node {
    int time;
    Node* next;
    friend class CL; // Allow CircularQueue to access private members
};

class CircularQueue {
    Node* tail;
    int quantum;

public:
    CircularQueue(int q) {
        quantum = q;
        tail = NULL;
    }

    int insertProcess(int);
    void execute();
};

#endif