#include<iostream>
#include<cmath>

using namespace std;


int cau_1(int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        if(i % 4 == 0 && i % 5 == 0){
            sum += i;
        }
    }
    return sum;
}

int cau_2(int n){
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += (n / n -1);
    }
    return sum;
}

int cau_3(int n){
    int a = 1;
    for(int i = 1; i <= n; i++){
        a *= i;
    }
    return a;
}

void cau_4a(int n){
    for(int i = 1; i <= n; i++){
        if(n % i == 0){
            cout << i << " ";
        }
    }
}

void cau_4b(int n){
    int count = 0;
    int sum = 0;
    for(int i = 1; i <= n; i++){
        if(n % i == 0){
            sum += i;
            count++;
        }
    }
    cout << "Tong cua uoc so: " << sum;
    cout << "Co " << count << "uoc so!";
}


bool cau_5(int n){
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

int cau_5b(int n){
    int max = 0;
    for(int i = 1; i <= n; i++){
        if(cau_5(i)){
            max = i;
        }
    }
    return max;

}

int bai_6a(int a, int b){
    while(a != b){
        if(a > b){
            if(b == 0) return a;
            a = a % b;
        }
        else{
            if(a == 0) return b;
            b = b % a;
        }
    }
    return a;
}

int bai_6b(int a, int b, int &x, int &y){
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int gcd = bai_6b(b, a % b, x1, y1);

    x = y1; 
    y = x1 - (a / b) * y1;

    return gcd;
}

int bai_6c(int a, int b){
    return abs(a * b)/ bai_6a(a,b);
}

void bai_7(int n){
    int a = 0;
    while(n > 0){
        a = n % 2;
        cout << a;
        n = n/2;
    }
}

int main(){
 
    bai_7(9);
}