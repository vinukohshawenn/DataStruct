#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

class Graph {
private:
    int numVertices;
    vector<list<int>> adjList;

public:
    Graph(int vertices);
    void insertEdge(int src, int dest);
    void deleteEdge(int src, int dest);
    void searchEdge(int src, int dest);
    void display();
private:
    bool validVertex(int v);
};

int main() {
    int vertices;
    cout << "Enter number of vertices in the graph: ";
    cin >> vertices;

    Graph g(vertices);
    int choice, src, dest;

    do {
        cout << "\n--- Graph Menu ---\n";
        cout << "1. Insert Edge\n";
        cout << "2. Delete Edge\n";
        cout << "3. Search Edge\n";
        cout << "4. Display Adjacency List\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter source and destination to insert: ";
            cin >> src >> dest;
            g.insertEdge(src, dest);
            break;
        case 2:
            cout << "Enter source and destination to delete: ";
            cin >> src >> dest;
            g.deleteEdge(src, dest);
            break;
        case 3:
            cout << "Enter source and destination to search: ";
            cin >> src >> dest;
            g.searchEdge(src, dest);
            break;
        case 4:
            g.display();
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please enter between 1 and 5.\n";
        }
    } while (choice != 5);

    return 0;
}

// --- Function Definitions ---

Graph::Graph(int vertices) {
    numVertices = vertices;
    adjList.resize(vertices);
}

bool Graph::validVertex(int v) {
    if (v >= 0 && v < numVertices) {
        return true;
    } else {
        cout << "Error: Vertex out of bounds. Must be between 0 and " << numVertices - 1 << ".\n";
        return false;
    }
}

void Graph::insertEdge(int src, int dest) {
    if (validVertex(src) && validVertex(dest)) {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src); // Undirected
        cout << "Edge inserted successfully.\n";
    }
}

void Graph::deleteEdge(int src, int dest) {
    if (validVertex(src) && validVertex(dest)) {
        adjList[src].remove(dest);
        adjList[dest].remove(src);
        cout << "Edge deleted successfully.\n";
    }
}

void Graph::searchEdge(int src, int dest) {
    if (validVertex(src) && validVertex(dest)) {
        auto it = find(adjList[src].begin(), adjList[src].end(), dest);
        if (it != adjList[src].end())
            cout << "Edge exists between " << src << " and " << dest << ".\n";
        else
            cout << "No edge exists between " << src << " and " << dest << ".\n";
    }
}

void Graph::display() {
    cout << "Adjacency List:\n";
    for (int i = 0; i < numVertices; ++i) {
        cout << i << " -> ";
        for (int neighbor : adjList[i]) {
            cout << neighbor << " ";
        }
        cout << "\n";
    }
}
