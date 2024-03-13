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
    // thêm ma trận được đánh dấu vào ma trận child
    for(int i = 0; i < w_sub; i++){
        for(int j = 0; j < h_sub; j++){
            child[i][j]  = a[m + i][n + j];
        }
    }  
    return child; 

}

int main(){
    
    int m, n, w_sub, h_sub;
    cout << "Enter the size of the matrix: ";
    cin >> m;
    cin >> n;
    cin >> w_sub;
    cin >> h_sub;
    
    int **array = gererateArray2D(m, n);
    cout << "Generated matrix:" << endl;
    printArray2D(array, m, n);
    
    int **arr_2 = findLargestSubmatrix(array, m ,n, w_sub, h_sub);
    cout << "Largest Submatrix:" << endl;
    printArray2D(arr_2, w_sub, h_sub);
    
    deleteArray(arr_2, w_sub,h_sub);

    return 0;
}
