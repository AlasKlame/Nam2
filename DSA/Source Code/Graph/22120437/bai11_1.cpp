#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include<algorithm>

using namespace std;

struct Edge {
    int to; 
    int weight; 
};

struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};

vector<int> dijkstra(vector<vector<Edge>>& graph, int start, int target) {
    int n = graph.size(); 
    vector<int> distances(n, numeric_limits<int>::max()); 
    vector<int> predecessors(n, -1); 
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> queue;
    queue.push({start, 0});
    distances[start] = 0;

    while (!queue.empty()) {
        int u = queue.top().first;
        queue.pop();

        if (u == target) {
            break;
        }

        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            int newDistance = distances[u] + edge.weight;

            if (newDistance < distances[v]) {
                distances[v] = newDistance;
                predecessors[v] = u;
                queue.push({v, newDistance});
            }
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
    vector<vector<Edge>> graph(n);
    
    graph[0].push_back({1, 2});
    graph[0].push_back({2, 6});
    graph[1].push_back({0, 2});
    graph[1].push_back({3, 8});
    graph[2].push_back({0, 6});
    graph[2].push_back({4, 7});
    graph[3].push_back({1, 8});
    graph[4].push_back({2, 7});

    int start = 0; 
    int target = 4; 

    vector<int> path = dijkstra(graph, start, target);

    cout << "Đường đi ngắn nhất: ";
    for (int i = 0; i < path.size(); i++) {
        cout << path[i];
        if (i < path.size() - 1) {
            cout << " -> ";
        }
    }
    cout << endl;

    return 0;
}