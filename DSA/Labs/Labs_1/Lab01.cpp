#include<iostream>
#include<cmath>

using namespace std;

void inputArray(int* &arr, int n){
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
}

void deallocateArray(int *&arr){
    delete[] arr;
}

int* generateArray(int n){
    int* arr = new int[n];
    for(int i = 0; i < n; i++){
        arr[i] = rand() % (30-10+1); 
    }
    return arr;
}

void printArray(int* arr, int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

}

int findmin(int* arr, int n){
    int min = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }
    return min;
} 

int findmaxAbsolutely(int* arr, int n){
    int max = abs(arr[0]);
    for(int i = 1; i < n; i++){
        if(abs(arr[i]) > max){
            max = abs(arr[i]);
        }
    }
    return max;
}

bool asending(int* arr, int n){
    for(int i = 0; i < n - 1; i++){
        if(arr[i] > arr[i + 1]){
            return false;
        }
    }
    return true;
}

int sumofArray(int *arr, int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
    return sum;
}

bool isPrime(int n){
    if( n < 2){
        return false;
    }
    for(int i = 2;i < n; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

int countPrime(int *arr, int n){
    int count = 0;
    for(int i = 0; i < n; i++){
        if(isPrime(arr[i])){
            count++;
        }
    }
    return count;
}
bool isSquareNumbers(int n){
    for(int i = 1; i <= n; i++){
        if(i*i == n){
            return true;
        }
    }
    return false;
}

int countSquareNumbers(int* arr, int n){
    int count = 0;
    for(int i = 0; i < n; i++){
        if(isSquareNumbers(arr[i])){
            count++;
        }
    }
    return count;
}

void reverseArray(int *&a, int *b, int n){
    for(int i = 0; i < n; i++){
        b[i] = a[n-i-1];
    }
}

int** transposeMatrix(int** &a, int n, int m){
    int** result = new int*[m]; 
    for(int i = 0; i < m; i++){
        result[i] = new int[n]; 
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            result[j][i] = a[i][j]; 
        }
    }  

    return result; 
}

int **gererateArray2D(int m, int n){
    int **arr = new int*[m];
    for(int i = 0; i < m; i++){
        arr[i] = new int[n];
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            arr[i][j] = rand() % (30-10+1);
        }
    }
    return arr;
}

void printArray2D(int** arr, int m, int n){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n;j++){
            cout << arr[i][j] << " ";
        }  
        cout << endl;
    }
}

void deleteArray(int** arr, int m, int n ){
    for(int i = 0; i < m; i++){
        delete[] arr[i];    
    }
    delete[] arr;
}


void swapMatrixColumns(int** &a, int n, int i, int j) {
    for (int row = 0; row < n; ++row) {
        int temp = a[row][i];
        a[row][i] = a[row][j];
        a[row][j] = temp;
    }
}

void swapMatrixRows(int **&a, int n, int i, int j){
    for(int col = 0; col < n; col++){
        int tmp = a[col][i];
        a[col][i] = a[col][j];
        a[col][j] = tmp;
    }
}

int** matrixMultiplication(int** a, int** b, int m, int n,int p){
    int** c = new int*[m];
    for(int i = 0; i < m; i++){
        c[i] = new int[p];
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < p; j++){
            c[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

int** findLargestSubmatrix(int** a, int w, int h, int& w_sub, int& h_sub){
    int** child = new int*[w_sub];
    for(int i = 0; i < w_sub; i++){
        child[i] = new int[h_sub];
    }
    int max = 0;
    int m = 0, n = 0;
    
    for(int i = 0; i <= w - w_sub; i++){
        for(int j = 0; j <= h - h_sub; j++){
            int sum = 0;
            for(int k = 0; k < w_sub; k++){
                for(int s = 0; s < h_sub; s++){
                    sum += a[i + k][j + s];
                }
            }
            if(sum > max){
                max = sum;
                m = i;
                n = j;
            }
        }
    }
    for(int i = 0; i < w_sub; i++){
        for(int j = 0; j < h_sub; j++){
            child[i][j]  = a[m + i][n + j];
        }
    }  
    return child; 

}

int linearSearch(int* a, int n, int key){
    for(int i = 0; i < n; i++){
        if(a[i] == key){
            return i;
        }
    }
    return -1;

}

int sentineLinearSearch(int* a, int n, int key){
    int last = a[n - 1];
    a[n - 1] = key;
    int i = 0;
    while(a[i] != key){
        i++;
    }
    a[n - 1] = last;
    if(i < n - 1 || a[n - 1] == key){
        return i;
    }
    return -1;
}

int binarySearch(int* a, int n, int key){
    int left = 0;
    int right = n - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(a[mid] == key){
            return mid;
        }
        else if(a[mid] < key){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return -1;
}

// Recursive 
int sumOfSquares(int n){
    if(n == 1){
        return 1;
    }
    return sumOfSquares(n - 1) + n * n;
    
    
}

int GCD(int a, int b){
    if(b == 0){
        return a;
    }
    return GCD(b, a % b);
}

bool isPalindrome(int* a, int left, int right){
    if(left >= right){
        return true;
    }
    if(a[left] != a[right]){
        return false;
    }
    return isPalindrome(a, left + 1, right - 1);

}

int sumOfDigits(int n){
    if(n == 0){
        return 0;
    }
    return n % 10 + sumOfDigits(n / 10);
}

int fibonacci(int n){
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}


int combination(int n, int k){
    if(k == 0 || k == n){
        return 1;
    }
    return combination(n - 1, k - 1) + combination(n - 1, k);
}

int recursiveBinarySearch(int* a, int left, int right, int key){
    if(left > right){
        return -1;
    }
    int mid = (left + right) / 2;
    if(a[mid] == key){
        return mid;
    }
    else if(a[mid] < key){
        return recursiveBinarySearch(a, mid + 1, right, key);
    }
    else{
        return recursiveBinarySearch(a, left, mid - 1, key);
    }

}

int main(){
    return 0;
}