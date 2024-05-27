#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>


using namespace std;


vector<vector<int>> readMaxtrix(string fileName){
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

void List(const vector<vector<int>> &matrix){
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++){
            int index = j;
            if(matrix[i][j] == 1){
                cout << index << " ";
            }
        }
        cout << endl;
    }
}

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


//Kiem tra do thi vo huong

bool isUndirected(const vector<vector<int>> &matrix){
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++){
            if(matrix[i][j] == matrix[j][i]){
                return true;
            }
        }
    }
    return false;
}

//Dem dinh , canh cua do thi
int VertexForUndirected(const vector<vector<int>> matrix){
    int count = 0;
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++){
            if(matrix[i][j] == 1){
                count++;
            }
        }
    }
    return count / 2;
}

int countEdges(const vector<vector<int>> matrix){
    int vertex = VertexForUndirected(matrix);
    return vertex * (vertex - 1) / 2; 
}

//Ham tinh bac cua do thi vo huong
vector<int> calculateDegrees(const vector<vector<int>>& adjList) {
    vector<int> degrees(adjList.size(), 0);
    for (int u = 0; u < adjList.size(); ++u) {
        degrees[u] = adjList[u].size(); 
    }
    return degrees;
}

// Ham tinh dinh vao - ra cua do thi co huong
pair<vector<int>, vector<int>> calculateInOutDegrees(const vector<vector<int>>& adjList) {
    int n = adjList.size();
    vector<int> inDegrees(n, 0);
    vector<int> outDegrees(n, 0);

    for (int u = 0; u < n; ++u) {
        for (int v : adjList[u]) {
            outDegrees[u]++;
            inDegrees[v - 1]++;
        }
    }

    return {inDegrees, outDegrees};
}

// Ham kiem tra danh sach dinh treo/La
vector<int> findLeafNodes(vector<vector<int>>& adjacencyMatrix) {
  int n = adjacencyMatrix.size();
  vector<int> leafNodes;

  for (int i = 0; i < n; i++) {
    int outgoingDegree = 0;
    for (int j = 0; j < n; j++) {
      if (adjacencyMatrix[i][j] == 1) { 
        outgoingDegree++;
      }
    }
    if (outgoingDegree == 1) {
      leafNodes.push_back(i);
    }
  }

  return leafNodes;
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

    vector<int> leaf =  findLeafNodes(graph2);
    for(int i = 0; i < leaf.size(); i++){
        cout << leaf[i] << " ";
    }


}