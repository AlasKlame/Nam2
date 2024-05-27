#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>

using namespace std;

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
int main() {
    vector<vector<int>> graph = readMatrix("graph1.txt");

    for (int i = 0; i < graph.size(); i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    List(graph);


    return 0;
}

