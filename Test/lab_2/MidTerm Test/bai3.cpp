#include<iostream>
#include<cmath>

using namespace std;

bool isPrime(int n){
    if(n < 2){
        return true;
    }
    for(int i = 2; i <= sqrt(n); i++){
        if( n % i == 0){
            return false;
        }
    }

    return true;
}

int sumofN(int n){
    int ten = 0;
    int sum = 0;
    while(n > 0){
        int tmp = n % 10;
        sum += tmp;
        n = n / 10;
        ten *= 10;
    }
    return sum;
}

int main(){
    int n;
    cin >> n;
    int sumo = sumofN(n);
    int sum = 0;
    for(int i = 2; i <= n; i++){
        if(isPrime(i)){
            while(n % i == 0){
                if(i > 10){
                    int a = sumofN(i);
                    sum += a;
                }
                else{
                    sum += i;
                }
                n /= i;
            }
        }
    }

    
    if(sum == sumo){
        cout << "true";
    }
    else{
        cout << "false";
    }

}