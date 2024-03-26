#include<iostream>

using namespace std;

void inputArray(int* &a, int &n){
    a = new int[n];
    if( 3 <= n <= 20){
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
    }
}

void printArray(int* a, int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}

int findMax(int* a, int n){
    int *max = &a[0];
    for(int i = 1; i < n; i++){
        if(a[i] > *max){
            max = &a[i];
        }
    }
    return *max;
}

int* copyArr(int* a, int n){
    int *b = new int[n];
    for(int i = 0; i < n; i++){
        b[i] = a[i];
    }
    return b;
}

int* generateEvensArray(int* arr, int n, int* count){
    int *arr_1 = new int[n];
    *count = 0; // Khởi tạo biến count
    for(int i = 0; i < n; i++){
        if(arr[i] % 2 == 0){
            arr_1[*count] = arr[i];
            (*count)++; // Tăng giá trị của biến count
        }
    }
    
    return arr_1;
}

int* countEvens(int* a, int n, int* evens){
    return generateEvensArray(a, n, evens);
}



int* findLargestSumSubarray(int* arr, int n, int &largestSum, int &subarrayLength) {
    largestSum = arr[0];
    int currentSum = arr[0];
    int start = 0;
    int end = 0; 

    for (int i = 1; i < n; ++i) {
        if (arr[i] > currentSum + arr[i]) {
            currentSum = arr[i];
            start = i;
        } else {
            currentSum += arr[i];
        }

        if (currentSum > largestSum) {
            largestSum = currentSum;
            end = i;
            subarrayLength = end - start + 1;
        }
    }

    int* subArray = new int[subarrayLength];
    for (int i = start; i <= end; ++i) {
        subArray[i - start] = arr[i];
    }

    return subArray;
}


int *findLongestAscendingSubarray(int *a, int n, int &subarrayLength){
    int *subArray = new int[n];
    int max = 1;
    int count = 1;
    int start = 0;
    for(int i = 1; i < n; i++){
        if(a[i] > a[i - 1]){
            count++;
        } else {
            if(count > max){
                max = count;
                subarrayLength = max;
                start = i - max;
            }
            count = 1;
        }
    }
    if(count > max){
        max = count;
        subarrayLength = max;
        start = n - max;
    }
    for(int i = start; i < start + max; i++){
        subArray[i - start] = a[i];
    }
    return subArray;

}

void swapArray(int *a, int *b, int na, int nb){
    int *temp = new int[na];
    for(int i = 0; i < na; i++){
        temp[i] = a[i];
    }
    delete[] a;
    a = new int[nb];
    for(int i = 0; i < nb; i++){
        a[i] = b[i];
    }
    delete[] b;
    b = new int[na];
    for(int i = 0; i < na; i++){
        b[i] = temp[i];
    }
    delete[] temp;

}

int *concatenaneTwoArray(int* a, int* b, int na, int nb){
    int *c = new int[na + nb];
    for(int i = 0; i < na; i++){
        c[i] = a[i];
    }
    for(int i = 0; i < nb; i++){
        c[i + na] = b[i];
    }
    return c;
}

int *mergeTwoArray(int *a, int *b, int na, int nb){
    int *c = new int[na+ nb];
    for(int i = 0; i < na; i++){
        c[i] = a[i];
    
    }
    for(int j = 0; j < nb; j++){
        c[j + na] = b[j];
    }
    for(int i = 0; i < na + nb; i++){
        for(int j = i + 1; j < na + nb; j++){
            if(c[i] > c[j]){
                int temp = c[i];
                c[i] = c[j];
                c[j] = temp;    
            }
        }
    }
    return c;
}

int main(){
    int n;
    cout << "Nhap n:";
    cin >> n;
    int *a;
    cout << "Nhap mang a: ";
    inputArray(a, n);
    printArray(a, n);
    cout << endl;
    cout <<"Phan tu lon nhat: ";
    cout << findMax(a, n) << endl;
    cout << "Mang b sau khi copy tu a: ";
    int *b = copyArr(a, n);
    printArray(b, n);
    cout << endl;
    int count;
    
    cout << endl;
    cout << "Mang so chan: ";
    int *d = countEvens(a, n, &count);
    printArray(d, count);
    cout << endl;
    int largestSum;
    int subarrayLength;
    cout << "Mang con co tong lon nhat: ";
    int *e = findLargestSumSubarray(a, n, largestSum, subarrayLength);
    printArray(e, subarrayLength);
    cout << endl;
    int subarrayLength_1;
    cout << "Mang con tang dan dai nhat: ";
    int *f = findLongestAscendingSubarray(a, n, subarrayLength_1);
    printArray(f, subarrayLength_1);
    cout << endl;
    int m;
    cout << "Nhap m: ";
    cin >> m;
    int *g;
    cout << "Nhap mang g: ";
    inputArray(g, m);
    swapArray(a, g, n, m);
    cout << "Mang a sau khi swap voi mang g : ";
    printArray(a, m);
    cout << endl;
    int *h = concatenaneTwoArray(a, g, n, m);
    cout << "Mang sau khi noi 2 mang a va g: ";
    printArray(h, n + m);
    cout << endl;
    int *i = mergeTwoArray(a, g, n, m);
    cout << "Mang sau khi merge 2 mang a va g: ";
    printArray(i, n + m);
    cout << endl;

    delete[] a;
    delete[] b;
    delete[] d;
    delete[] e;
    delete[] f;
    delete[] g;
    delete[] h;
    delete[] i;
    return 0;
}