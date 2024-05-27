#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Graph {
    int numVertices;
    vector<vector<int>> adjList;

    Graph(int n) {
        numVertices = n;
        adjList.resize(n);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }
};

Graph createUndirectedGraph(const Graph& directedGraph) {
    Graph undirectedGraph(directedGraph.numVertices);

    for (int u = 0; u < directedGraph.numVertices; ++u) {
        for (int v : directedGraph.adjList[u]) {
            undirectedGraph.addEdge(u, v);
            undirectedGraph.addEdge(v, u);
        }
    }

    return undirectedGraph;
}

void printGraph(const Graph& graph) {
    for (int u = 0; u < graph.numVertices; ++u) {
        cout << u << " -> ";
        for (int v : graph.adjList[u]) {
            cout << v << " ";
        }
        cout << endl;
    }
}

int main() {
    Graph directedGraph(5);
    directedGraph.addEdge(0, 1);
    directedGraph.addEdge(0, 2);
    directedGraph.addEdge(1, 2);
    directedGraph.addEdge(2, 3);
    directedGraph.addEdge(3, 4);

    cout << "Đồ thị có hướng:" << endl;
    printGraph(directedGraph);

    Graph undirectedGraph = createUndirectedGraph(directedGraph);

    cout << "Đồ thị vô hướng tương ứng:" << endl;
    printGraph(undirectedGraph);

    return 0;
}