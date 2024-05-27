#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v;
    int weight;
};

bool compareEdges(const Edge &a, const Edge &b) {
    return a.weight < b.weight;
}

struct DisjointSet {
    vector<int> parent;
    vector<int> rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void merge(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu != pv) {
            if (rank[pu] < rank[pv]) {
                parent[pu] = pv;
            } else if (rank[pu] > rank[pv]) {
                parent[pv] = pu;
            } else {
                parent[pu] = pv;
                rank[pv]++;
            }
        }
    }
};

vector<Edge> kruskal(vector<Edge> &edges, int n) {
    vector<Edge> mst;
    sort(edges.begin(), edges.end(), compareEdges);
    DisjointSet ds(n);
    for (auto edge : edges) {
        int u = edge.u;
        int v = edge.v;
        if (ds.find(u) != ds.find(v)) {
            mst.push_back(edge);
            ds.merge(u, v);
        }
    }
    return mst;
}

int main() {
    int n = 5; 
    int m = 7; 
    vector<Edge> edges = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}
    };
    vector<Edge> mst = kruskal(edges, n);
    cout << "Cây khung nhỏ nhất:\n";
    for (auto edge : mst) {
        cout << edge.u << " - " << edge.v << " (Weight: " << edge.weight << ")\n";
    }
    return 0;
}