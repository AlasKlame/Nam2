#include<iostream>

using namespace std;



void setArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap phan tu thu " << i << ": ";
        cin >> a[i];
    }
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}

int sumArray(int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum;
}

int findMin(int a[], int n) {
    int min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }
    return min;
}

int checkPrime(int n) {
    if (n < 2) {
        return 0;
    }
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int countNumberofPrime(int a[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (checkPrime(a[i])) {
            count++;
        }
    }
    return count;
}


int isAscendingOrder(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            return 0;
        }
    }
    return 1;
}

int countOcurrences(int a[], int n, int x) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            count++;
        }
    }
    return count;
}

void deleteItems(int a[], int &n, int x) {
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            for (int j = i; j < n - 1; j++) {
                a[j] = a[j + 1];
            }
            n--;
            i--;
        }
    }
}

void deleteItemsFromIndex(int a[], int &n, int index, int no_items) {
    for (int i = index; i < n - no_items; i++) {
        a[i] = a[i + no_items];
    }
    n -= no_items;
}

void concatTwoArray(int a[], int &n, int b[], int m) {
    for (int i = 0; i < m; i++) {
        a[n++] = b[i];
    }
}

void concatIntersperseldyTwoArray(int a[], int &n, int b[], int m, int c[]) {
    int i = 0, j = 0, k = 0;
    while (i < n && j < m) {
        c[k++] = a[i++];
        c[k++] = b[j++];
    }
    while (i < n) {
        c[k++] = a[i++];
    }
    while (j < m) {
        c[k++] = b[j++];
    }

}

int main(){
    int a[100], b[100], c[200], n, m;
    cout << "Nhap so phan tu cua mang a: ";
    cin >> n;
    setArray(a, n);
    cout << "Nhap so phan tu cua mang b: ";
    cin >> m;
    setArray(b, m);
    concatIntersperseldyTwoArray(a, n, b, m, c);
    cout << "Mang sau khi ghep xen ke: ";
    printArray(c, n + m);
    return 0;
}