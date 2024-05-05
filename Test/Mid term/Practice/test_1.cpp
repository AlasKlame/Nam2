#include<iostream>
#include<iomanip>

using namespace std;


bool isPrime(int n){
    if(n < 2){
        return false;
    }
    for(int i = 2; i <= n/2; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

int countNumm(int n){
    int count = 0;
    while(n > 0){
        count++;
        n /= 10;
    }
    return count;

}

int removeDigitAtPosition(int n, int position) {
    int divisor = 1;
    int result = 0;
    int count = 0;

    while (n > 0) {
        int digit = n % 10;
        if (count != position) {
            result = digit * divisor + result;
            divisor *= 10;
        }
        n /= 10;
        count++;
    }
    return result;
}


int main(){
    int n;
    cin >> n;
    int count = countNumm(n);
    for(int i = 0; i < count; i++){
        cout << removeDigitAtPosition(n, i) << endl;
        
    }
}