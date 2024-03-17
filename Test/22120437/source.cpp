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
void bai_11(int seconds){  
    if(seconds > 3600 * 24){
        std::cout << "Nhap lai ma oi" << std::endl;
    }
    else{
        int hour = seconds / 3600;
        seconds = seconds % 3600;
        int minute = seconds / 60;
        seconds = seconds % 60;
        std::cout << hour << ":" << minute << ":" << seconds << std::endl;

    }
    

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
   
    std::cout << "so tien 10 dong la: " << n / 10 << std::endl;
    n = n % 10;
    std::cout << "so tien 5 dong la :" << n / 5  << std::endl;
    n = n % 5;
    std::cout << "so tien 2 dong la :" << n / 2 << std::endl;
    n = n % 2;
    std::cout << "so tien 1 dong la :" <<n / 1 << std::endl;
}

void bai_15(int a, float b, float c){
    int cost = a * (int) b;
    int n = c - (int) cost;

    std::cout << "so tien 10 dong la: " << n / 10 << std::endl;
    n = n % 10;
    std::cout << "so tien 5 dong la: " << n / 5 << std::endl;
    n = n % 5;
    std::cout << "so tien 2 dong la: " << n / 2 << std::endl;
    n = n % 2;
    std::cout << "so tien 1 dong la: " <<n / 1 << std::endl;
}


void bai_16(int a, int b){
    std::cout << a << std::endl;
    std::cout << "x" << b << std::endl;
    std::cout << "------------" << std::endl;
    int d = b;
    char e = '+';
    while(d > 0){
        int c = d % 10;
        std::cout <<e << c * a << std::endl;
        d = d / 10;
    }
    std::cout << "--------------" << std::endl;
    std::cout << a * b;
}


int bai_17(float weight, float height){
    return weight / (height * height);
}

int bai_18(int arr[], int n){
   
    int sumOfTime = 0;
    for(int i = 0; i < n; i++){
        sumOfTime += arr[i];
    }
    return sumOfTime;
}

int main(){
    int choice;
    do {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Print Hello World" << std::endl;
        std::cout << "2. Print C Language Basic Syntax Rules" << std::endl;
        std::cout << "3. Calculate Minus" << std::endl;
        std::cout << "4. Calculate Minus of Two Integers" << std::endl;
        std::cout << "5. Calculate bai_5" << std::endl;
        std::cout << "6. Calculate bai_6" << std::endl;
        std::cout << "7. Calculate bai_7" << std::endl;
        std::cout << "8. Calculate bai_8" << std::endl;
        std::cout << "9. Calculate bai_9" << std::endl;
        std::cout << "10. Calculate bai_10" << std::endl;
        std::cout << "11. Calculate bai_11" << std::endl;
        std::cout << "12. Calculate bai_12" << std::endl;
        std::cout << "13. Calculate bai_13" << std::endl;
        std::cout << "14. Calculate bai_14" << std::endl;
        std::cout << "15. Calculate bai_15" << std::endl;
        std::cout << "16. Calculate bai_16" << std::endl;
        std::cout << "17. Calculate bai_17" << std::endl;
        std::cout << "18. Calculate bai_18" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        int a, b, x, y, m, n, p, q, r, num, d, e, f, num2, money, a2;
        float b2, c2, weight, height;
        int a3, b3, size;

        switch (choice) {
            case 1:
                printHelloWorld();
                break;
            case 2:
                printC();
                break;
            case 3:
                std::cout << "Minus: " << Minus() << std::endl;
                break;
            case 4:
                std::cout << "Enter two integers: ";
                std::cin >> a >> b;
                std::cout << "Minus of two integers: " << minusOfInteger(a, b) << std::endl;
                break;
            case 5:
                std::cout << "Enter an integer: ";
                std::cin >> x;
                std::cout << "bai_5: " << bai_5(x) << std::endl;
                break;
            case 6:
                std::cout << "Enter a float number: ";
                std::cin >> y;
                bai_6(y);
                break;
            case 7:
                std::cout << "Enter two float numbers: ";
                std::cin >> m >> n;
                std::cout << "bai_7: " << bai_7(m, n) << std::endl;
                break;
            case 8:
                std::cout << "Enter two float numbers: ";
                std::cin >> p >> q;
                std::cout << "bai_8: " << bai_8(p, q) << std::endl;
                break;
            case 9:
                std::cout << "Enter a float number: ";
                std::cin >> r;
                std::cout << "bai_9: " << bai_9(r) << std::endl;
                break;
            case 10:
                std::cout << "Enter an integer: ";
                std::cin >> num;
                bai_10(num);
                break;
            case 11:
                std::cout << "Enter seconds: ";
                std::cin >> num;
                bai_11(num);
    
                break;
            case 12:
                std::cout << "Enter three float numbers: ";
                std::cin >> d >> e >> f;
                std::cout << "bai_12: " << bai_12(d, e, f) << std::endl;
                break;
            case 13:
                std::cout << "Enter an integer: ";
                std::cin >> num2;
                std::cout << "bai_13: " << bai_13(num2) << std::endl;
                break;
            case 14:
                std::cout << "Enter an integer: ";
                std::cin >> money;
                bai_14(money);
                break;
            case 15:
                std::cout << "Enter an integer and two float numbers: ";
                std::cin >> a2 >> b2 >> c2;
                bai_15(a2, b2, c2);
                break;
            case 16:
                std::cout << "Enter two integers: ";
                std::cin >> a3 >> b3;
                bai_16(a3, b3);
                break;
            case 17:
                std::cout << "Enter weight and height: ";
                std::cin >> weight >> height;
                std::cout << "bai_17: " << bai_17(weight, height) << std::endl;
                break;
            case 18:
                std::cout << "Enter the size of the array: ";
                std::cin >> size;
                int arr[1000];
                std::cout << "Enter " << size << " integers: ";
                for (int i = 0; i < size; i++) {
                    std::cin >> arr[i];
                }
                std::cout << "bai_18: " << bai_18(arr, size) << std::endl;
                break;
            case 0:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    } while (choice != 0);

    return 0;
}