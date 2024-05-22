#include<iostream>
#define MAX 100
using namespace std;


void set2dArray(int a[][MAX], int &m, int &n){
    cout << "Nhap so hang: ";
    cin >> m;
    cout << "Nhap so cot: ";
    cin >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Nhap phan tu thu [" << i << "][" << j << "]: ";
            cin >> a[i][j];
        }
    }
}

void print2dArray(int a[][MAX], int m, int n){
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int sumArray(int a[][MAX], int m, int n){
    int sum = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            sum += a[i][j];
        }
    }
    return sum;
}

int sumDiagonal(int a[][MAX], int m, int n){
    int sum = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                sum += a[i][j];
            }
        }
    }
    return sum;
}

int findMin(int a[][MAX], int m, int n){
    int min = a[0][0];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] < min) {
                min = a[i][j];
            }
        }
    }
    return min;
}
bool checkPrime(int n){
    if (n < 2) {
        return false;
    }
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
int countNumberofPrime(int a[][MAX], int m, int n){
    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (checkPrime(a[i][j])) {
                count++;
            }
        }
    }
    return count;
}
int countNumberofUniquePrime(int a[][MAX], int m, int n){
    int count = 0;
    int prime[MAX * MAX];
    int k = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (checkPrime(a[i][j])) {
                prime[k++] = a[i][j];
            }
        }
    }
    for (int i = 0; i < k; i++) {
        int flag = 1;
        for (int j = 0; j < i; j++) {
            if (prime[i] == prime[j]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            count++;
        }
    }
    return count;
}

int countOccurrences(int a[][MAX], int m, int n, int x){
    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == x) {
                count++;
            }
        }
    }
    return count;
}

void deleteItems(int a[][MAX], int &m, int &n, int x) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == x) {
                for (int k = i; k < m - 1; k++) {
                    a[k][j] = a[k + 1][j];
                }
                m--;
                i--;

                for (int k = j; k < n - 1; k++) {
                    a[i][k] = a[i][k + 1];
                }
                n--;
                j--;
            }
        }
    }
}

int main(){
    int a[MAX][MAX], m, n;
    set2dArray(a, m, n);
    print2dArray(a, m, n);
    cout << "Tong cac phan tu trong mang: " << sumArray(a, m, n) << endl;
    cout << "Tong cac phan tu tren duong cheo chinh: " << sumDiagonal(a, m, n) << endl;
    cout << "Phan tu nho nhat trong mang: " << findMin(a, m, n) << endl;
    cout << "So luong so nguyen to trong mang: " << countNumberofPrime(a, m, n) << endl;
    cout << "So luong so nguyen to duy nhat trong mang: " << countNumberofUniquePrime(a, m, n) << endl;
    int x;
    cout << "Nhap so can tim: ";
    cin >> x;
    cout << "So lan xuat hien cua " << x << " trong mang: " << countOccurrences(a, m, n, x) << endl;
    deleteItems(a, m, n, x);
    print2dArray(a, m, n);
    return 0;
}