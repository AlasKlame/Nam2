#include<iostream>
#include<cmath>
using namespace std;


int sumofPow(int n){
   
    if(n == 1){
        return 1;
    }
    return pow(n, 2) + sumofPow(n - 1);
}



float tongPhanSo(int n){
    if(n == 1){
        return 1;
    }
    return 1.0/n + tongPhanSo((n - 1));
}

float tongPhanSo_2(int n){
    if(n == 1){
        return 1;
    }
    return 1.0/n + tongPhanSo((n - 2));
}

int sumOfPow(int x, int n){
    if(n == 0){
        return 0;
    }
    return pow(x, 2*n) + sumOfPow(x, n - 1);
}


int Fibonacci(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main(){
    int n;
    n = 5;
    int x= 4;
    cout << sumofPow(n) << endl;
    cout << tongPhanSo(n) << endl;
    cout << tongPhanSo_2(n) << endl;
    cout << sumOfPow(x, n) << endl;
    cout << Fibonacci(n) << endl;   
    return 0;
}


