#include<iostream>
#include<cmath>
#include<stdlib.h>
using namespace std;

void swap(float* a, float* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void minmaxSort(float a[], int n){
    int idmin =0; int idmax = 0;
    for(int i = 0; i < n; i++){
        if(a[idmin] > a[i]){
            idmin = i;

        }
        if(a[idmax] < a[i]){
            idmax = i;
        }
    }
    swap(&a[0],&a[idmin]);
    if(idmax == 0){
        idmax = idmin;
    }
    swap(&a[n-1],&a[idmax]);
    if(n > 3){
        minmaxSort(&a[1],n-2);
    }
       
}



int main(){
    int n;
    cin >> n;
    float a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    minmaxSort(a,n);
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    return 0;
}