#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>


using namespace std;

vector<vector<int>> readMaxtrixList(string fileName){
    vector<vector<int>> matrix;
    ifstream inFile(fileName);
    int n;
    inFile >> n;
    inFile.ignore();
    string line;
    while(getline(inFile, line)){
        vector<int> row;
        stringstream ss(line);
        int tmp;
        while(ss >> tmp){
            row.push_back(tmp);
        }
        matrix.push_back(row);
    }
    inFile.close();
    return matrix;
}

vector<vector<int>> adjacencyListToMatrix(const vector<vector<int>>& adjList, int n) {
    vector<vector<int>> adjMatrix(n, vector<int>(n, 0));  

    for (int u = 0; u < adjList.size(); ++u) {
        for (int v : adjList[u]) {
            adjMatrix[u][v - 1] = 1;  
        }
    }

    return adjMatrix;
}


int main(){
    ifstream inFile("graph2.txt");
    int n;
    inFile >> n;
    vector<vector<int>> graph = readMaxtrixList("graph2.txt");
    for(int i = 0; i < graph.size(); i++){
        for( int j = 0; j < graph[i].size(); j++){
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    vector<vector<int>> graph2 = adjacencyListToMatrix(graph, n);
    for(int i = 0; i < graph2   .size(); i++){
        for( int j = 0; j < graph2[i].size(); j++){
            cout << graph2[i][j] ;
        }
        cout << endl;
    }
    cout << endl;

    


}