#include<iostream>
#include<cmath>

using namespace std;


bool isPrime(int n){
    if(n < 2){
        return true;
    }
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            return false;
        }
    }  
    return true; 
}

float average(int a, int b){
    float sum = 0;
    int count  = 0;
    for(int i = a;i <= b;i++){
        if(isPrime(i)) {
            if(i < 10  || (i / 10) % 2 != 0){
                sum += i;
                count++;
            }
        }
    }
    return (float)sum /  (float)count;
}

int main(){
    int a, b;
    cin >> a >> b;
    float result = average(a, b);
    cout <<  result << endl;
    return 0;

    
}