#include<iostream>
#include<iomanip>
#include<cmath>
void printHelloWorld(){
    std::cout<<"Hello World!"<<std::endl;
}

void printC(){
    std::cout <<"C Language Basic Syntax Rules"<<std::endl;
    std::cout<<"\t 1. Lowercase letters are significant"<<std::endl;
    std::cout<<"\t 1. main is where program excution begins"<<std::endl;
    std::cout<<"\t 3. Opening and closing braces enclose program statements in a routine"<<std::endl;
    std::cout<<"\t 4. All program statements musut be terminated by a semicolon"<<std::endl;
}

int Minus(){
    return 321 - 123;
}

int minusOfInteger(int a, int b){
    return a - b;
}

int bai_5(int x){
    return x*x*x - 5*x*x + 6;
}

void bai_6(float x){
    float a = 3.14 * x * x;
    float b = 3.14 * 2 * x;
    std::cout <<"dien tich la:" << a<< std::endl;   
    std::cout << "chu vi la:" << b<< std::endl;
}


float bai_7(float m, float n){
    return m/n;
}

float bai_8(float m, float n){
    return n / m;
}

float bai_9(float m){
    return m + m*10/100;
}

void bai_10(int n){
    if(n > 100){
        std::cout << "Nhap lai ma oi" << std::endl;
    }
    else{int a = 0;
    while(n > 0){
        int tmp = n % 10;
        
        a = a * 10 + tmp;
        n /= 10;
    }
    std::cout << a << std::endl;}
}

float bai_12(float a, float b, float c){
    return ((6.67 * 10e-11)* (a * b)) / c* c;

}


int bai_13(int x){
    if(x % 20 == 0){
        return x / 20;
    }
    else{
        return x / 20 + 1;
    }
}

void bai_14(int n){
   
    std::cout << "so tien 10 dong la:" << n / 10;
    n = n % 10;
    std::cout << " so tien 5 dong la:" << n / 5;
    n = n % 5;
    std::cout << "so tien 2 dong la:" << n / 2;
    n = n % 2;
    std::cout << " so tien 1 dong la:" <<n / 1;
}

void bai_15(int a, float b, float c){
    int cost = a * (int) b;
    int n = c - (int) cost;

    std::cout << "so tien 10 dong la:" << n / 10;
    n = n % 10;
    std::cout << " so tien 5 dong la:" << n / 5;
    n = n % 5;
    std::cout << "so tien 2 dong la:" << n / 2;
    n = n % 2;
    std::cout << " so tien 1 dong la:" <<n / 1;
}


void bai_16(int a, int b){
    std::cout << a << std::endl;
    std::cout << "x " << b << std::endl;
    std::cout << "------------" << std::endl;
    while(b > 0){
        int c = b % 10;
        std::cout <<"\t" << c * a << std::endl;
        b = b / 10;
    }
    std::cout << "--------------" << std::endl;
    std::cout << a * b;
}


int main(){
    printHelloWorld();
    printC();
    bai_10(121);
    std::cout << std::endl;
    bai_16(763,589);
    return 0;
}