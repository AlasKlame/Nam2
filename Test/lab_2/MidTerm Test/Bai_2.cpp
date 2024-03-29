#include<iostream>
#include<cmath>


using namespace std;

bool perfectNum(int n){
    int sum = 0;
    for(int i = 1; i < n; i++){
        if(n % i == 0){
            sum += i;
            if(sum == n){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int n;
    cin >> n;
    int min = n;
    for(int i = 1; i < 10000; i++){
        if(perfectNum(i)){
            if(i > min){
                cout << i - n;
                break;
            }
        }
    }
    return 0;
}