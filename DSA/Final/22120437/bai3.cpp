#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<vector<int>> graph; 
vector<bool> visited; 

void DFS(int u) {
    visited[u] = true;
    for (int v : graph[u]) {
        if (!visited[v]) {
            DFS(v);
        }
    }
}

int main() {
    ifstream infile("bai3.in");
    ofstream outfile("bai3.out");

    int m, n;
    infile >> m >> n;

    graph.resize(m + 1); 
    visited.assign(m + 1, false); 

    int u, v;
    for (int i = 0; i < n; ++i) {
        infile >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int counter = 0;
    for (int i = 1; i <= m; ++i) {
        if (!visited[i]) {
            counter++;
            DFS(i);
        }
    }

    outfile << counter - 1 << endl;

    infile.close();
    outfile.close();
    return 0;
}