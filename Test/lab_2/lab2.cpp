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

int checkMonth(int month, int year){
    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
        return 31;
    }
    else if(month == 4 || month == 6 || month == 9 || month == 11){
        return 30;
    }
    else if(leapYear(year)){
        return 29;
    }
    else{
        return 28;
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


bool checkTriangle(int a, int b, int c){
    if(a * a + b * b >= c * c){
        return true;
    }
    else if( a * a + c * c >= b* b){
        return true;
    }
    else if(b * b + c * c >= a * a){
        return true;
    }
    else{
        return false;
    }
}

void isTriangle(int a, int b, int c){
    if(checkTriangle(a, b, c)){
        if(a == b && b == c){
            cout << "Tam giac deu";
        }
        else if(a == b || b == c || a == c){
            cout << "Tam giac can";
        }
        else if(a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a){
            cout << "Tam giac vuong";
        }
        else{
            cout << "Tam giac thuong";
        }
    }
}

float TaxiMoney(int km){
    if(km <= 1){
        return 15;
    }
    else if(km <= 5){
        return 15 + (km - 1) * 13.5;
    }
    else if(km <= 120){
        return 15 + 4 * 13.5 + (km - 5) * 11;
    }
    else{
        return (15 + 4 * 13.5 + 115 * 11 + (km - 120)) * 90 / 100;
    }
}

float ElectricMoney(int kWh){
    if(kWh <= 100){
        return kWh * 1000;
    }
    else if(kWh <= 150){
        return 100 * 1000 + (kWh - 100) * 1200;
    }
    else if(kWh <= 200){
        return 100 * 1000 + 50 * 1200 + (kWh - 150) * 2000;
    }
    else{
        return 100 * 1000 + 50 * 1200 + 50 * 1500 + (kWh - 200) * 2500;
    }
}

float penaltyFee(int km){
    float x = km - 60;
    if(5 < x <= 10){
        return 0.7;
    }
    else if(10 < x <= 20){
        return 2.5;
    }
    else if(20 < x <= 35){
        return 5.5;
    }
    else if(x > 35){
        return 7.5;
    }
}

void printAlphabet(int x){
    if( x <= 9){
        cout << x;
    }
    else{
        char c = 'A' + x - 10;
        cout << c;
    }
}
bool laTamGiacVuong(int a, int b, int c) {
    if (a > b)
        swap(a, b);
    if (b > c)
        swap(b, c);
    return (c * c == a * a + b * b);
}

float Quadratic_equation_2(float a, float b, float c){
    float delta = b * b - 4 * a * c;
    if(delta < 0){
        return 0;
    }
    else if(delta == 0){
        return -b / (2 * a);
    }
    else{
        float x1 = (-b + sqrt(delta)) / (2 * a);
        float x2 = (-b - sqrt(delta)) / (2 * a);
        return x1;
    }
}

int EmulatorCaculator(int a, int b, char c){
    switch (c){
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        case '%':
            return a % b;
    }
}

int main(){
    int choice;
    do {
        cout << "Menu:" << endl;
        cout << "1. Check Time" << endl;
        cout << "2. Print Grades" << endl;
        cout << "3. Check Square Number" << endl;
        cout << "4. Check Even Number" << endl;
        cout << "5. Check Leap Year" << endl;
        cout << "6. Check Month" << endl;
        cout << "7. Convert Number to Letter" << endl;
        cout << "8. Sort Numbers" << endl;
        cout << "9. Check Triangle" << endl;
        cout << "10. Check Triangle Type" << endl;
        cout << "11. Calculate Taxi Money" << endl;
        cout << "12. Calculate Electric Money" << endl;
        cout << "13. Calculate Penalty Fee" << endl;
        cout << "14. Print Alphabet" << endl;
        cout << "15. Check Right Triangle" << endl;
        cout << "16. Solve Quadratic Equation" << endl;
        cout << "17. Emulator Calculator" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int hour, minute, second;
                cout << "Enter hour: ";
                cin >> hour;
                cout << "Enter minute: ";
                cin >> minute;
                cout << "Enter second: ";
                cin >> second;
                if (checkTime(hour, minute, second)) {
                    cout << "Valid time" << endl;
                } else {
                    cout << "Invalid time" << endl;
                }
                break;
            }
            case 2: {
                float math, physic, chemical;
                cout << "Enter math grade: ";
                cin >> math;
                cout << "Enter physic grade: ";
                cin >> physic;
                cout << "Enter chemical grade: ";
                cin >> chemical;
                print(math, physic, chemical);
                break;
            }
            case 3: {
                int n;
                cout << "Enter a number: ";
                cin >> n;
                if (squareNumber(n)) {
                    cout << "Square number" << endl;
                } else {
                    cout << "Not a square number" << endl;
                }
                break;
            }
            case 4: {
                int n;
                cout << "Enter a number: ";
                cin >> n;
                if (checkEven(n)) {
                    cout << "Even number" << endl;
                } else {
                    cout << "Odd number" << endl;
                }
                break;
            }
            case 5: {
                int year;
                cout << "Enter a year: ";
                cin >> year;
                if (leapYear(year)) {
                    cout << "Leap year" << endl;
                } else {
                    cout << "Not a leap year" << endl;
                }
                break;
            }
            case 6: {
                int month, year;
                cout << "Enter month: ";
                cin >> month;
                cout << "Enter year: ";
                cin >> year;
                int days = checkMonth(month, year);
                cout << "Number of days in month " << month << " is " << days << endl;
                break;
            }
            case 7: {
                int n;
                cout << "Enter a number: ";
                cin >> n;
                numToLetter(n);
                cout << endl;
                break;
            }
            case 8: {
                int a, b, c;
                cout << "Enter three numbers: ";
                cin >> a >> b >> c;
                sort(a, b, c);
                break;
            }
            case 9: {
                int a, b, c;
                cout << "Enter three sides of a triangle: ";
                cin >> a >> b >> c;
                if (checkTriangle(a, b, c)) {
                    cout << "Valid triangle" << endl;
                } else {
                    cout << "Invalid triangle" << endl;
                }
                break;
            }
            case 10: {
                int a, b, c;
                cout << "Enter three sides of a triangle: ";
                cin >> a >> b >> c;
                isTriangle(a, b, c);
                cout << endl;
                break;
            }
            case 11: {
                int km;
                cout << "Enter distance in kilometers: ";
                cin >> km;
                float money = TaxiMoney(km);
                cout << "Taxi money: " << money << endl;
                break;
            }
            case 12: {
                int kWh;
                cout << "Enter electricity consumption in kWh: ";
                cin >> kWh;
                float money = ElectricMoney(kWh);
                cout << "Electricity money: " << money << endl;
                break;
            }
            case 13: {
                int km;
                cout << "Enter distance in kilometers: ";
                cin >> km;
                float fee = penaltyFee(km);
                cout << "Penalty fee: " << fee << endl;
                break;
            }
            case 14: {
                int x;
                cout << "Enter a number: ";
                cin >> x;
                printAlphabet(x);
                cout << endl;
                break;
            }
            case 15: {
                int a, b, c;
                cout << "Enter three sides of a triangle: ";
                cin >> a >> b >> c;
                if (laTamGiacVuong(a, b, c)) {
                    cout << "Right triangle" << endl;
                } else {
                    cout << "Not a right triangle" << endl;
                }
                break;
            }
            case 16: {
                float a, b, c;
                cout << "Enter coefficients of quadratic equation: ";
                cin >> a >> b >> c;
                float x = Quadratic_equation_2(a, b, c);
                if (x == 0) {
                    cout << "No real roots" << endl;
                } else if (x == -1) {
                    cout << "Infinite roots" << endl;
                } else {
                    cout << "Root: " << x << endl;
                }
                break;
            }
            case 17: {
                int a, b;
                char op;
                cout << "Enter two numbers and an operator: ";
                cin >> a >> b >> op;
                int result = EmulatorCaculator(a, b, op);
                cout << "Result: " << result << endl;
                break;
            }
            case 0: {
                cout << "Exiting..." << endl;
                break;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    } while (choice != 0);

    return 0;
}