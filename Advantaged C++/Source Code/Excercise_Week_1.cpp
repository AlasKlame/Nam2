#include<iostream>

using namespace std;


void inputArray2D(int **&arr, int n, int m){
    arr = new int*[n];
    for(int i = 0; i < n; i++){
        arr[i] = new int[m];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){  
            cin >> arr[i][j];    
        }
    }
}

void outputArray2D(int **arr, int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){     
            cout << arr[i][j] <<" ";      
        }
            cout <<  endl;
    }
}





int main(){
    int n,m;
    cout << "Nhap n: " << endl;
    cin >> n >> m;
    int **arr ;
    // for(int i = 0; i < n; i++){
    //     arr[i] = new int[n];
    // }
    // cout << "Moi thay nhap vao ma tran:";
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){  
    //         cin >> arr[i][j];    
    //     }
    // }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){     
    //         cout << arr[i][j] <<" ";      
    //     }
    //         cout <<  endl;
    // }

    inputArray2D(arr, n, m);
    outputArray2D(arr, n, m);

    for(int i = 0; i < n; i++){
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
    
}
