#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    void heapifyUp(int index);
    void heapifyDown(int index);
    void heapifyDownFromVector(vector<int>& h, int index);

public:
    void insert(int value);
    void deleteMax();
    void display() const;
    void search(int value) const;
    void sortHeap();
};

int main() {
    MaxHeap pq;
    int choice, value;

    do {
        cout << "\n--- Priority Queue (Max Heap) Menu ---\n";
        cout << "1. Insert\n2. Delete (Max)\n3. Display\n4. Search\n5. Sort (Heap Sort)\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                pq.insert(value);
                break;
            case 2:
                pq.deleteMax();
                break;
            case 3:
                pq.display();
                break;
            case 4:
                cout << "Enter value to search: ";
                cin >> value;
                pq.search(value);
                break;
            case 5:
                pq.sortHeap();
                break;
            case 6:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}

void MaxHeap::heapifyUp(int index) {
    if (index && heap[(index - 1) / 2] < heap[index]) {
        swap(heap[index], heap[(index - 1) / 2]);
        heapifyUp((index - 1) / 2);
    }
}

void MaxHeap::heapifyDown(int index) {
    int size = heap.size();
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] > heap[largest])
        largest = left;

    if (right < size && heap[right] > heap[largest])
        largest = right;

    if (largest != index) {
        swap(heap[index], heap[largest]);
        heapifyDown(largest);
    }
}

void MaxHeap::insert(int value) {
    heap.push_back(value);
    heapifyUp(heap.size() - 1);
    cout << "Inserted " << value << " into the Priority Queue.\n";
}

void MaxHeap::deleteMax() {
    if (heap.empty()) {
        cout << "Priority Queue is empty!\n";
        return;
    }

    cout << "Deleted: " << heap[0] << endl;
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);
}

void MaxHeap::display() const {
    if (heap.empty()) {
        cout << "Priority Queue is empty!\n";
        return;
    }

    cout << "Priority Queue elements: ";
    for (int val : heap)
        cout << val << " ";
    cout << endl;
}

void MaxHeap::search(int value) const {
    auto it = find(heap.begin(), heap.end(), value);
    if (it != heap.end())
        cout << value << " found at index " << distance(heap.begin(), it) << endl;
    else
        cout << value << " not found in the Priority Queue.\n";
}

void MaxHeap::sortHeap() {
    if (heap.empty()) {
        cout << "Priority Queue is empty!\n";
        return;
    }

    vector<int> tempHeap = heap;
    vector<int> sorted;

    while (!tempHeap.empty()) {
        sorted.push_back(tempHeap[0]);
        tempHeap[0] = tempHeap.back();
        tempHeap.pop_back();
        heapifyDownFromVector(tempHeap, 0);
    }

    cout << "Sorted elements (Descending): ";
    for (int val : sorted)
        cout << val << " ";
    cout << endl;
}

void MaxHeap::heapifyDownFromVector(vector<int>& h, int index) {
    int size = h.size();
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && h[left] > h[largest])
        largest = left;

    if (right < size && h[right] > h[largest])
        largest = right;

    if (largest != index) {
        swap(h[index], h[largest]);
        heapifyDownFromVector(h, largest);
    }
}
