#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

typedef vector<double> doubleArray;

typedef vector<double> Array;


void matrixAllocation(vector<Array> &a, int n){
    a.resize(n);
    for(int i = 0; i < a.size(); i++){
        a[i].resize(n);
    }
}

vector<Array> input(vector<Array> &a, int n){
    matrixAllocation(a, n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    return a;
}


vector<Array> output(vector<Array> &a, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return a;
}




// 

void matrixInit(vector<doubleArray> &a, int n){
    a.resize(n);
    for(int i = 0; i < a.size(); i++){
        a[i].resize(n);
    }
}

istream& operator >> (istream& inDevice, vector<doubleArray> &a){
    int n; inDevice >> n;
    matrixInit(a, n);
    for(int i = 0; i < a.size();i++){
        for(int j = 0; j < a[i].size(); j++){
            a[i][j] = 0;
            if(inDevice){
                inDevice >> a[i][j];
            }
        }
    }
    return inDevice;
}

ostream& operator << (ostream& outDevice, vector<doubleArray>& a){
    outDevice << a.size() << endl;
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < a[i].size(); j++){
            outDevice << a[i][j] << " "; 
        }
        outDevice << endl;
    }
    return outDevice;
}

int main(){
    vector<Array> A;
    int n;
    cin >> n;
    input(A, n);
    output(A, n);
    cin.get();
    return 0;
}