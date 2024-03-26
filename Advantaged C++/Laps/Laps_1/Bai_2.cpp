#include<iostream>
using namespace std;

void generateRandomMatrix(int **&arr, int &m, int &n){
    arr = new int*[m];
    for(int i = 0; i < m; i++){
        arr[i] = new int[n];
        for(int j = 0; j < n; j++){
            arr[i][j] = rand() % 100;
        }
    }
}

void printMatrix(int **arr, int m, int n){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int **caculateProductMatrix(int *a,int *b, int na, int nb){
    int **c = new int*[na];
    for(int i = 0; i < na; i++){
        c[i] = new int[nb];
        for(int j = 0; j < nb; j++){
            c[i][j] = a[i] * b[j];
        }
    }
    return c;

}

int **concatenateMatricesByRow(int **a, int **b, int m, int n){
    int **c = new int*[m * 2];
    for(int i = 0; i < m; i++){
        c[i] = new int[n];
        for(int j = 0; j < n; j++){
            c[i][j] = a[i][j];
        }
    }
    for(int i = m; i < m * 2; i++){
        c[i] = new int[n];
        for(int j = 0; j < n; j++){
            c[i][j] = b[i - m][j];
        }
    }
    return c;
}

int **concatenateMatricesByCol(int **a, int **b, int m, int n){
    int **c = new int*[m];
    for(int i = 0; i < m; i++){
        c[i] = new int[n * 2];
        for(int j = 0; j < n; j++){
            c[i][j] = a[i][j];
        }
        for(int j = n; j < n * 2; j++){
            c[i][j] = b[i][j - n];
        }
    }
    return c;
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

int main(){
    int m, n;
    int choice;
    
    cout << "Enter the number of rows: ";
    cin >> m;
    cout << "Enter the number of columns: ";
    cin >> n;
    
    int **matrix;
    generateRandomMatrix(matrix, m, n);
    
    do {
        cout << "Menu:" << endl;
        cout << "1. Print the matrix" << endl;
        cout << "2. Calculate the product matrix" << endl;
        cout << "3. Concatenate matrices by row" << endl;
        cout << "4. Concatenate matrices by column" << endl;
        cout << "5. Swap matrix columns" << endl;
        cout << "6. Swap matrix rows" << endl;
        cout << "7. Transpose matrix" << endl;
        cout << "8. Matrix multiplication" << endl;
        cout << "9. Find largest submatrix" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Matrix:" << endl;
                printMatrix(matrix, m, n);
                break;
            case 2:
                int na, nb;
                cout << "Enter the number of elements in array a: ";
                cin >> na;
                cout << "Enter the number of elements in array b: ";
                cin >> nb;
                int *a = new int[na];
                int *b = new int[nb];
                cout << "Enter the elements of array a: ";
                for (int i = 0; i < na; i++) {
                    cin >> a[i];
                }
                cout << "Enter the elements of array b: ";
                for (int i = 0; i < nb; i++) {
                    cin >> b[i];
                }
                int **productMatrix = caculateProductMatrix(a, b, na, nb);
                cout << "Product Matrix:" << endl;
                printMatrix(productMatrix, na, nb);
                deleteArray(productMatrix, na, nb);
                delete[] a;
                delete[] b;
                break;
            case 3:
                int **matrix2;
                int m2, n2;
                cout << "Enter the number of rows for the second matrix: ";
                cin >> m2;
                cout << "Enter the number of columns for the second matrix: ";
                cin >> n2;
                generateRandomMatrix(matrix2, m2, n2);
                int **concatenatedMatrixByRow = concatenateMatricesByRow(matrix, matrix2, m, n);
                cout << "Concatenated Matrix by Row:" << endl;
                printMatrix(concatenatedMatrixByRow, m + m2, n);
                deleteArray(concatenatedMatrixByRow, m + m2, n);
                deleteArray(matrix2, m2, n2);
                break;
            case 4:
                int **matrix3;
                int m3, n3;
                cout << "Enter the number of rows for the second matrix: ";
                cin >> m3;
                cout << "Enter the number of columns for the second matrix: ";
                cin >> n3;
                generateRandomMatrix(matrix3, m3, n3);
                int **concatenatedMatrixByCol = concatenateMatricesByCol(matrix, matrix3, m, n);
                cout << "Concatenated Matrix by Column:" << endl;
                printMatrix(concatenatedMatrixByCol, m, n + n3);
                deleteArray(concatenatedMatrixByCol, m, n + n3);
                deleteArray(matrix3, m3, n3);
                break;
            case 5:
                int col1, col2;
                cout << "Enter the column index of the first column to swap: ";
                cin >> col1;
                cout << "Enter the column index of the second column to swap: ";
                cin >> col2;
                swapMatrixColumns(matrix, n, col1, col2);
                cout << "Matrix after swapping columns:" << endl;
                printMatrix(matrix, m, n);
                break;
            case 6:
                int row1, row2;
                cout << "Enter the row index of the first row to swap: ";
                cin >> row1;
                cout << "Enter the row index of the second row to swap: ";
                cin >> row2;
                swapMatrixRows(matrix, n, row1, row2);
                cout << "Matrix after swapping rows:" << endl;
                printMatrix(matrix, m, n);
                break;
            case 7:
                int **transposedMatrix = transposeMatrix(matrix, m, n);
                cout << "Transposed Matrix:" << endl;
                printMatrix(transposedMatrix, n, m);
                deleteArray(transposedMatrix, n, m);
                break;
            case 8:
                int m2, n2, p;
                cout << "Enter the number of rows for the second matrix: ";
                cin >> m2;
                cout << "Enter the number of columns for the second matrix: ";
                cin >> n2;
                cout << "Enter the number of columns for the resulting matrix: ";
                cin >> p;
                int **matrix2;
                generateRandomMatrix(matrix2, m2, n2);
                int **multipliedMatrix = matrixMultiplication(matrix, matrix2, m, n, p);
                cout << "Multiplied Matrix:" << endl;
                printMatrix(multipliedMatrix, m, p);
                deleteArray(multipliedMatrix, m, p);
                deleteArray(matrix2, m2, n2);
                break;
            case 9:
                int w_sub, h_sub;
                cout << "Enter the width of the submatrix: ";
                cin >> w_sub;
                cout << "Enter the height of the submatrix: ";
                cin >> h_sub;
                int **submatrix = findLargestSubmatrix(matrix, m, n, w_sub, h_sub);
                cout << "Largest Submatrix:" << endl;
                printMatrix(submatrix, w_sub, h_sub);
                deleteArray(submatrix, w_sub, h_sub);
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
        
    } while (choice != 0);
    
    deleteArray(matrix, m, n);
    
    return 0;
}