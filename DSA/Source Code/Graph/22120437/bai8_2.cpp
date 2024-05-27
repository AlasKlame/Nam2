#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Graph {
    int numVertices;
    vector<vector<int>> adjList;

    Graph(int n) : numVertices(n), adjList(n) {}

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); 
    }
};

vector<pair<int, int>> findSpanningTreeBFS(const Graph& graph, int start) {
    vector<pair<int, int>> spanningTree; 
    vector<bool> visited(graph.numVertices, false);
    vector<int> parent(graph.numVertices, -1); 

    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : graph.adjList[u]) {
        if (!visited[v]) {
            parent[v] = u;
            spanningTree.push_back({u, v});
            visited[v] = true;
            q.push(v);
        }
        }
    }

    return spanningTree;
}

void printSpanningTree(const vector<pair<int, int>>& spanningTree) {
    for (auto edge : spanningTree) {
        cout << edge.first << " - " << edge.second << endl;
    }
}

int main() {
    Graph graph(6);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 5);

    vector<pair<int, int>> spanningTree = findSpanningTreeBFS(graph, 0);
    cout << "Cây khung (BFS):" << endl;
    printSpanningTree(spanningTree);

    return 0;
}