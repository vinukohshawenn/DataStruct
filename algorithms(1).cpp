#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

const int INF = numeric_limits<int>::max();

class Edge {
public:
    int src, dest, weight;
};

class Graph {
private:
    int V;
    vector<vector<int>> adjMatrix;
    vector<Edge> edges;

public:
    Graph(int vertices);
    void addEdge(int u, int v, int w);
    void display();
    void primMST();
    void kruskalMST();
    void dijkstra(int start);

private:
    int minKey(const vector<int>& key, const vector<bool>& mstSet);
    int findParent(int u, vector<int>& parent);
    void unionSets(int u, int v, vector<int>& parent, vector<int>& rank);
};

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    Graph g(V);
    int choice;

    do {
        cout << "\n--- Graph Algorithms Menu ---\n";
        cout << "1. Add Edge\n";
        cout << "2. Display Graph\n";
        cout << "3. Prim's MST\n";
        cout << "4. Kruskal's MST\n";
        cout << "5. Dijkstra's Algorithm\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        int u, v, w, start;

        switch (choice) {
            case 1:
                cout << "Enter source, destination and weight: ";
                cin >> u >> v >> w;
                g.addEdge(u, v, w);
                break;
            case 2:
                g.display();
                break;
            case 3:
                g.primMST();
                break;
            case 4:
                g.kruskalMST();
                break;
            case 5:
                cout << "Enter starting vertex: ";
                cin >> start;
                g.dijkstra(start);
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 6);

    return 0;
}

// --- Function Definitions ---

Graph::Graph(int vertices) {
    V = vertices;
    adjMatrix.resize(V, vector<int>(V, 0));
}

void Graph::addEdge(int u, int v, int w) {
    if (u >= 0 && u < V && v >= 0 && v < V) {
        adjMatrix[u][v] = w;
        adjMatrix[v][u] = w;
        edges.push_back({u, v, w});
        cout << "Edge added.\n";
    } else {
        cout << "Invalid vertices.\n";
    }
}

void Graph::display() {
    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (adjMatrix[i][j] == 0)
                cout << "∞ ";
            else
                cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int Graph::minKey(const vector<int>& key, const vector<bool>& mstSet) {
    int min = INF, min_index;

    for (int v = 0; v < V; ++v)
        if (!mstSet[v] && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void Graph::primMST() {
    vector<int> key(V, INF), parent(V, -1);
    vector<bool> mstSet(V, false);

    key[0] = 0;

    for (int count = 0; count < V - 1; ++count) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; ++v) {
            if (adjMatrix[u][v] && !mstSet[v] && adjMatrix[u][v] < key[v]) {
                parent[v] = u;
                key[v] = adjMatrix[u][v];
            }
        }
    }

    cout << "Prim's MST:\n";
    for (int i = 1; i < V; ++i)
        cout << parent[i] << " - " << i << " : " << adjMatrix[i][parent[i]] << "\n";
}

int Graph::findParent(int u, vector<int>& parent) {
    if (parent[u] != u)
        parent[u] = findParent(parent[u], parent);
    return parent[u];
}

void Graph::unionSets(int u, int v, vector<int>& parent, vector<int>& rank) {
    int pu = findParent(u, parent);
    int pv = findParent(v, parent);
    if (rank[pu] < rank[pv])
        parent[pu] = pv;
    else if (rank[pu] > rank[pv])
        parent[pv] = pu;
    else {
        parent[pv] = pu;
        rank[pu]++;
    }
}

void Graph::kruskalMST() {
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
    });

    vector<int> parent(V);
    vector<int> rank(V, 0);

    for (int i = 0; i < V; ++i)
        parent[i] = i;

    cout << "Kruskal's MST:\n";
    for (const Edge& edge : edges) {
        int uParent = findParent(edge.src, parent);
        int vParent = findParent(edge.dest, parent);

        if (uParent != vParent) {
            cout << edge.src << " - " << edge.dest << " : " << edge.weight << "\n";
            unionSets(uParent, vParent, parent, rank);
        }
    }
}

void Graph::dijkstra(int start) {
    vector<int> dist(V, INF);
    vector<bool> visited(V, false);
    dist[start] = 0;

    for (int count = 0; count < V - 1; ++count) {
        int u = -1;
        for (int i = 0; i < V; ++i)
            if (!visited[i] && (u == -1 || dist[i] < dist[u]))
                u = i;

        visited[u] = true;

        for (int v = 0; v < V; ++v) {
            if (!visited[v] && adjMatrix[u][v] && dist[u] != INF &&
                dist[u] + adjMatrix[u][v] < dist[v]) {
                dist[v] = dist[u] + adjMatrix[u][v];
            }
        }
    }

    cout << "Dijkstra's Shortest Paths from " << start << ":\n";
    for (int i = 0; i < V; ++i)
        cout << "To " << i << " : " << (dist[i] == INF ? "∞" : to_string(dist[i])) << "\n";
}
