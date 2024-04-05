#include<iostream>

using namespace std;


void print(int n) {
    int size = 4 * n - 3;
    int starSpace = 0;
    int chieu = 1;
    for(int i = 0; i < 2 * n - 1; i++){
        for(int j = 0; j < starSpace; j++){
            cout << "* ";
        }
        for(int j = 0; j < size; j++){
            cout << "*";
        }
        for(int j = 0; j < starSpace; j++){
            cout << " *";
        }
        if(size == 1){
            chieu = (-1)*chieu;
        }
        size -= chieu*4;
        starSpace += chieu*1;
        cout << endl;
    }
}
int main(){
    int n;
    cin >> n;
    print(n);
    return 0;
}