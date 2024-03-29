#include<iostream>
#include<cmath>

using namespace std;


void printNoelTree(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n - i; j++){
            cout <<" ";
        }
        for(int j = 1; j <= 2 * i - 1; j++){
            if(j != 1 && j != 2 * i - 1){
                cout << " ";
            }
            else{
                cout << "*";
            }
        }
        cout << endl;
    
    }
}

int main(){
    int n;
    cin >> n;
    printNoelTree(n);
    return 0;
}