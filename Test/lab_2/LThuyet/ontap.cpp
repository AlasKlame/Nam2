#include<iostream>


bool isAcend(int n){
    int tmp = n % 10;
    n = n / 10;
    while(n > 0){
        if(n % 10 > tmp){
            return false;
        }
        tmp = n % 10;
        n = n / 10;
    }
    return true;
}


int main(){
    int n;
    cin >> n;
    if
}