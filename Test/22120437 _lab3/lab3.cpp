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

void bai_7(int n) {
    int binary[32]; 

    int i = 0;
    while (n > 0) {
        binary[i] = n % 2;
        n = n / 2;
        i++;
    }

    for (int j = i - 1; j >= 0; j--) {
        cout << binary[j];
    }
}
void Bangcuuchuong() {
    for (int i = 1; i <= 9; ++i) {
        cout << "Bang cuu chuong cua " << i << ":" << std::endl;

        for (int j = 1; j <= 10; ++j) {
            std::cout << i << " x " << j << " = " << (i * j) << std::endl;
        }

        cout << endl;
    }
}


void bai_9(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n - i; j++){
            cout << " ";
        }
        for(int j = 1; j <= 2 * i - 1; j++){
            cout << "*";
        }
        cout << endl;
    }
   

}

void bai_10(int minute){
    if(minute < 0){
        cout << "Invalid input!";
    }
    else {
        cout <<"So luong calo sau " << minute << " phut la: " <<  (float)(minute * 3.6) << endl;
    }
   
}

double bai_11(int n, double x, double K) {
    double tongLuong = 0;
    double luongNgay = x; 

    for (int i = 1; i <= n; ++i) {
        cout << "Ngay " << i << ": " << luongNgay << " dong" << std::endl;

        tongLuong += luongNgay;

        luongNgay *= (1 + K / 100);
    }

    return tongLuong;
}

void Bai_12_a() {
    int x, y;
    for (x = 0; x <= 36; ++x) {
        y = 36 - x;
        if (2 * x + 4 * y == 100) {
            std::cout << "So con ga: " << x << std::endl;
            std::cout << "So con cho: " << y << std::endl;
            break;
        }
    }
}
void Bai_12_b() {
    int x, y, z;
    for (x = 0; x <= 100; ++x) {
        for (y = 0; y <= 100 - x; ++y) {
            z = 100 - x - y;
            if (5 * x + 3 * y + 0.5 * z == 300) {
                std::cout << "So con trau dung: " << x << std::endl;
                std::cout << "So con trau nam: " << y << std::endl;
                std::cout << "So con trau gia: " << z << std::endl;
                return;
            }
        }
    }
}

int bai_13(int danSoA, double tangTruongA, int danSoB, double tangTruongB) {
    int nam = 0;

    while (danSoA <= danSoB) {
        danSoA *= (1 + tangTruongA / 100);
        danSoB *= (1 + tangTruongB / 100);
        nam++;
    }

    return nam;
}

int Fibonacci(int n){
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Sum of numbers divisible by 4 and 5: " << cau_1(n) << endl;
    cout << "Sum of numbers from 1 to n: " << cau_2(n) << endl;
    cout << "Factorial of n: " << cau_3(n) << endl;
    cout << "Divisors of n: ";
    cau_4a(n);
    cout << endl;
    cau_4b(n);
    cout << endl;
    cout << "Is n a prime number? " << (cau_5(n) ? "Yes" : "No") << endl;
    cout << "Largest prime number less than or equal to n: " << cau_5b(n) << endl;

    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    cout << "Greatest common divisor of a and b: " << bai_6a(a, b) << endl;
    int x, y;
    cout << "Extended Euclidean algorithm: " << bai_6b(a, b, x, y) << endl;
    cout << "Least common multiple of a and b: " << bai_6c(a, b) << endl;

    cout << "Binary representation of n: ";
    bai_7(n);
    cout << endl;

    cout << "Multiplication table: " << endl;
    Bangcuuchuong();

    cout << "Pattern: " << endl;
    bai_9(n);

    int minute;
    cout << "Enter the number of minutes: ";
    cin >> minute;
    bai_10(minute);

    int n2;
    double x2, K;
    cout << "Enter the number of days: ";
    cin >> n2;
    cout << "Enter the initial salary: ";
    cin >> x2;
    cout << "Enter the percentage increase: ";
    cin >> K;
    cout << "Total salary after n days: " << bai_11(n2, x2, K) << endl;

    cout << "Solution to equation 2x + 4y = 100: " << endl;
    Bai_12_a();

    cout << "Solution to equation 5x + 3y + 0.5z = 300: " << endl;
    Bai_12_b();

    int danSoA, danSoB;
    double tangTruongA, tangTruongB;
    cout << "Enter the population of A: ";
    cin >> danSoA;
    cout << "Enter the growth rate of A (%): ";
    cin >> tangTruongA;
    cout << "Enter the population of B: ";
    cin >> danSoB;
    cout << "Enter the growth rate of B (%): ";
    cin >> tangTruongB;
    cout << "Number of years for A to surpass B: " << bai_13(danSoA, tangTruongA, danSoB, tangTruongB) << endl;

    int fiboN;
    cout << "Enter a number: ";
    cin >> fiboN;
    cout << "Fibonacci number at position " << fiboN << ": " << Fibonacci(fiboN) << endl;

    return 0;
}