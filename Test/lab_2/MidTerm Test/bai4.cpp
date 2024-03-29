#include<iostream>
#include<cmath>

using namespace std;


int main(){
    int n;
    cin >> n;
    int a = 4* n - 3;
    int b = 2* n - 1;
    for(int i = 0; i < 2*n -1; i++){
        for(int j = 0; j < 4*n -3; j++){
        
            if(i == j){
                for(int k = 0; k < 2*n -1; k++){
                    cout << "*" << " ";
                }
            }
            else{
                cout << "*";
            }

        }
        cout <<endl;
    }
}