#include <iostream>
using namespace std;

class Graph {
private:
    int **adjMatrix;
    int numVertices;

public:
    Graph(int vertices);
    ~Graph();

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
        cout << "4. Display Adjacency Matrix\n";
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


Graph::Graph(int vertices) {
    numVertices = vertices;
    adjMatrix = new int*[numVertices];
    for (int i = 0; i < numVertices; ++i) {
        adjMatrix[i] = new int[numVertices];
        for (int j = 0; j < numVertices; ++j) {
            adjMatrix[i][j] = 0;
        }
    }
}

Graph::~Graph() {
    for (int i = 0; i < numVertices; ++i) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
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
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1;
        cout << "Edge inserted successfully.\n";
    }
}

void Graph::deleteEdge(int src, int dest) {
    if (validVertex(src) && validVertex(dest)) {
        adjMatrix[src][dest] = 0;
        adjMatrix[dest][src] = 0;
        cout << "Edge deleted successfully.\n";
    }
}

void Graph::searchEdge(int src, int dest) {
    if (validVertex(src) && validVertex(dest)) {
        if (adjMatrix[src][dest] == 1)
            cout << "Edge exists between " << src << " and " << dest << ".\n";
        else
            cout << "No edge exists between " << src << " and " << dest << ".\n";
    }
}

void Graph::display() {
    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << "\n";
    }
}
