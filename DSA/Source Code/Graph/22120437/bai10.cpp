#include <iostream>
#include <vector>
#include<fstream>

using namespace std;
vector<vector<int>> graph;
vector<vector<int>> readMatrix(string fileName){
    vector<vector<int>> matrix;
    ifstream inFile(fileName);
    int n;
    inFile >> n;
    for(int i = 0; i < n; i++){
        vector<int> row;
        int tmp;
        for(int j = 0; j < n; j++){
            inFile >> tmp;
            row.push_back(tmp);
        }
        matrix.push_back(row);
    }
    inFile.close();
    return matrix;
}
vector<bool> visited; // Mảng đánh dấu đỉnh đã được thăm

void dfs(int u, int target) {
    visited[u] = true;
    if (u == target) {
        cout << "Hai đỉnh nằm trên cùng một thành phần liên thông\n";
        return;
    }
   
    for (int v : graph[u]) {
        if (!visited[v]) {
            dfs(v, target);
        }
    }
    cout << "Khong co dinh lien thong";
}

int main() {
    ifstream inFile("graph1.txt");
    int n;
    inFile >> n;
    graph = readMatrix("graph1.txt");
    int start = 1; 
    int target = 9;
    visited.resize(n, false);
    dfs(start, target);
    return 0;
}