#include<iostream>


using namespace std;


bool isPrime(int n){
    if(n == 1){
        return false;
    }
    for(int i = 2; i < n; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

void printIndex(int arrp[], int n, int index) {
    if (index < 0) {
        return;
    }
    if (isPrime(arrp[index])) {
        cout << index << " ";
    }
    printIndex(arrp, n, index - 1);
}

void printIndexWithEven(int arrp[], int n, int index) {
    if (index < 0) {
        return;
    }
    if (arrp[index] % 2 == 0) {
        cout << index << " ";
    }
    printIndexWithEven(arrp, n, index - 1);
}

int countDistinct(int arr[], int n, int index) {
    if (index == n - 1) {
        return 1;
    }
    for (int i = 0; i < index; ++i) {
        if (arr[i] == arr[index]) {
            return countDistinct(arr, n, index + 1);
        }
    }
    return 1 + countDistinct(arr, n, index + 1);
}



int main(){
    int arr[] = {3,1,4,1,4,1,2,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    printIndex(arr, n, n-1);
    cout << endl;
    printIndexWithEven(arr, n, n-1);
    cout << endl;
    cout << countDistinct(arr, n, 0);
    return 0;
}