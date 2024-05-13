
#include<iostream>
#include<cmath>
#define COLSIZE 100

using namespace std;



void inputArray2D(int arr[][COLSIZE], int numRows, int numCols){
    for(int i = 0; i < numRows; i++){
        for(int j = 0; j < numCols; j++){
            arr[i][j] = rand() % 100;
        }
    }
}

void outputArray2D(int arr[][COLSIZE], int numRows, int numCols){
    for(int i = 0; i < numRows; i++){
        for(int j = 0; j < numCols; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

bool isPrime(int num){
    if(num <= 1){
        return false;
    }
    for(int i = 2; i <= sqrt(num); i++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}

int largestPrimeOnBorder(int arr[][COLSIZE], int numRows, int numCols){
    int largestPrime = 0;
    for(int i = 0; i < numRows; i++){
        if(isPrime(arr[i][0])){
            largestPrime = max(largestPrime, arr[i][0]);
        }
        if(isPrime(arr[i][numCols - 1])){
            largestPrime = max(largestPrime, arr[i][numCols - 1]);
        }
    }
    for(int j = 0; j < numCols; j++){
        if(isPrime(arr[0][j])){
            largestPrime = max(largestPrime, arr[0][j]);
        }
        if(isPrime(arr[numRows - 1][j])){
            largestPrime = max(largestPrime, arr[numRows - 1][j]);
        }
    }
    return largestPrime;
}

void printArrayBorther(int arr[][COLSIZE], int numRows, int numCols){
    for(int i = 0; i < numRows; i++){
        cout << arr[i][0] << " ";
    }
    for(int i = 1; i < numCols; i++){
        cout << arr[numRows - 1][i] << " ";
    }
    for(int i = numCols - 2; i >= 0; i--){
        cout << arr[numRows - 1][i] << " ";
    }
    for(int i = numRows - 2; i > 0; i--){
        cout << arr[i][0] << " ";
    }
}

int main(){
    int arr[100][COLSIZE];
    int numRows, numCols;
    cin >> numRows >> numCols ;
    inputArray2D(arr, numRows, numCols);

    outputArray2D(arr, numRows, numCols);
    cout << endl;
    for(int i = 0; i < numRows; i++){
        cout << arr[i][i] << " ";
    }
    cout << endl;
    for(int i = 0; i < numRows; i++){
        cout << arr[i][numCols - i - 1] << " ";
    }
    cout << endl;   
    cout << largestPrimeOnBorder(arr, numRows, numCols);
    cout << endl;
    printArrayBorther(arr, numRows, numCols);

    cout << endl;
    cout << sizeof(double);
    return 0;
}