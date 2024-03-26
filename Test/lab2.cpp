#include<iostream>
#include<cmath>


using namespace std;




bool checkTime(int hour, int minute, int second){  
    if(hour >= 0 && hour <= 23){
        if(minute >= 0 && minute <= 59){
            if(second >= 0 && second <= 59){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }

}

void print(float math, float physic, float chemical){
    float sum = math + physic + chemical;
    if(sum >= 15 && math > 4 && physic > 4 && chemical > 4 ){
        cout << "Dau";
        if(math > 5 && physic > 5 && chemical > 5){
            cout << "Hoc Deu Cac Mon";
        }
        else{
            cout << "Hoc Chua Deu Cac Mon";
        }
    }
    else{
        cout <<"Thi hong";
    }
}




bool squareNumber(int n)
{
    int x = sqrt(n);
    if(x*x == n){
        return true;
    }
    else{
        return false;
    }
}

bool checkEven(int n){
    if(n % 2 == 0){
        return true;
    }
    else{
        return false;
    }
}

bool leapYear(int year){
    if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)){
        return true;
    }
    else{
        return false;
    }

}

void numToLetter(int n){
    switch (n){
        case 1:
            cout << "One";
            break;
        case 2:
            cout << "Two";
            break;
        case 3:
            cout << "Three";
            break;
        case 4:
            cout << "Four";
            break;
        case 5:
            cout << "Five";
            break;
        case 6:
            cout << "Six";
            break;
        case 7:
            cout <<"Seven";
            break;
        case 8:
            cout <<"Eight";
            break;
        case 9:
            cout <<"Nine";
            break;
    default: 
        cout << "null";
        break;
    }
}

void sort(int a, int b,int c){
    int max = 0;
    int min = 0;
    int medium = 0;
    if(a > b){
        if(a > c){
            max = a;
            if(c > b){
                min = b;
                medium = c;
            }
            else{
                min = c;
                medium = b;
            }
        }
        else{
            max = c;
            medium = a;
            min = b;
        }

    }
    else{
        if(b > c){
            max = b;
        }
        else{
            max = c;
            medium = b;
            min = a;
        }
    }
    cout << max << " " << min << endl;
    cout << min << " " << medium << " " << max;
    
}


bool check()

int main(){
    int n;
    sort(9, 10, 20);
}