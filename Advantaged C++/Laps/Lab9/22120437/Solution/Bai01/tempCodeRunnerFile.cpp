#include<iostream>
#include<cmath>
using namespace std;


int sumofPow(int n){
   
    if(n == 1){
        return 1;
    }
    return pow(n, 2) + sumofPow(n - 1);
}

int sumofPow_2(int n){
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += pow(i, 2);
    }
    return sum;
}

float tongPhanSo(int n){
    if(n == 1){
        return 1;
    }
    return 1.0/n + tongPhanSo(1.0/(n - 1));
}


int main(){
    int n;
    n = 5;
    cout << sumofPow(n) << endl;
    cout << tongPhanSo(n) << endl;
    return 0;
}


