#include <iostream>
#include <vector>
#include <limits>
#include<algorithm>

using namespace std;

struct Edge {
    int from; 
    int to; 
    int weight;
};


vector<int> bellmanFord(vector<Edge>& edges, int start, int target, int n) {
    vector<int> distances(n, numeric_limits<int>::max()); 
    vector<int> predecessors(n, -1); 
    distances[start] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (const Edge& edge : edges) {
            int u = edge.from;
            int v = edge.to;
            int newDistance = distances[u] + edge.weight;

            if (newDistance < distances[v]) {
                distances[v] = newDistance;
                predecessors[v] = u;
            }
        }
    }

    // Kiểm tra vòng lặp âm
    for (const Edge& edge : edges) {
        int u = edge.from;
        int v = edge.to;
        int newDistance = distances[u] + edge.weight;

        if (newDistance < distances[v]) {
            cout << "Đồ thị có vòng lặp âm\n";
            return {}; 
        }
    }


    vector<int> path;
    int current = target;
    while (current != -1) {
        path.push_back(current);
        current = predecessors[current];
    }
    reverse(path.begin(), path.end());

    return path;
}

int main() {
    int n = 5; 
    vector<Edge> edges = {
        {0, 1, 2},
        {0, 2, 6},
        {1, 3, 8},
        {2, 4, 7},
        {3, 2, -10} 
    };
    int start = 0; 
    int target = 4; 

    vector<int> path = bellmanFord(edges, start, target, n);

    if (!path.empty()) {
        cout << "Đường đi ngắn nhất: ";
        for (int i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i < path.size() - 1) {
                cout << " -> ";
            }
        }
        cout << endl;
    }

    return 0;
}