#include<iostream>

using namespace std;



int countNum(int n){
    if(n == 0) return 0;
    return 1 + countNum(n / 10);
}

int sumOfEven(int n) {
    if (n <= 0) {
        return 0;
    }
    
    int lastDigit = n % 10;
    int sum = (lastDigit % 2 == 0) ? lastDigit : 0;
    return sum + sumOfEven(n / 10);
}

int firstDigit(int n) {
    if (n <= 0) {
        return 0;
    }
    int lastDigit = n % 10;
    if(n / 10 == 0) return lastDigit;
    return firstDigit(n / 10);
}


int main(){
    int n = 123123;
    cout << countNum(n);
    cout << endl;
    cout << sumOfEven(n);
    cout << endl;
    cout << firstDigit(n);
    return 0;
}