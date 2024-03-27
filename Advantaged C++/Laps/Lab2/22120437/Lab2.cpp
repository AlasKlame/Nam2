#include<iostream>

using namespace std;


void generateRandomMatrix(int **&a, int &m, int &n){
    a = new int*[m];
    for(int i = 0; i < m; i++){
        a[i] = new int[n];
        for(int j = 0; j < n; j++){
            a[i][j] = rand() % 100;
        }
    }
}

void printMatrix(int **a, int m, int n){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void deleteMatrix(int **a, int m, int n){
    for(int i = 0; i < m; i++){
        delete[] a[i];
    }
    delete[] a;
}

void swapRows(int **a, int firstRow, int secondRow){
    for(int i = 0; i < 3; i++){
        int temp = a[firstRow][i];
        a[firstRow][i] = a[secondRow][i];
        a[secondRow][i] = temp;
    }
}

void swapColumn(int **a, int firstCol, int secondCol){
    for(int i = 0; i < 3; i++){
        int temp = a[i][firstCol];
        a[i][firstCol] = a[i][secondCol];
        a[i][secondCol] = temp;
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

int **concatenateMatricesByRow(int **a, int **b, int m, int n){
    int **c = new int*[m * 2];
    for(int i = 0; i < m; i++){
        c[i] = new int[n];
        for(int j = 0; j < n; j++){
            c[i][j] = a[i][j];
        }
    }
    cout << endl;
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
        cout << endl;
        for(int j = n; j < n * 2; j++){
            c[i][j] = b[i][j - n];
        }
    }
    return c;
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
    cout << "Enter the number of rows: ";
    cin >> m;
    cout << "Enter the number of columns: ";
    cin >> n;

    int **matrix;
    generateRandomMatrix(matrix, m, n);

    cout << "Generated Matrix:" << endl;
    printMatrix(matrix, m, n);

    int **transposedMatrix = transposeMatrix(matrix, m, n);
    cout << "Transposed Matrix:" << endl;
    printMatrix(transposedMatrix, n, m);

    int **concatenatedMatrixRow = concatenateMatricesByRow(matrix, transposedMatrix, m, n);
    cout << "Concatenated Matrix by Row:" << endl;
    printMatrix(concatenatedMatrixRow, m * 2, n);

    int **concatenatedMatrixCol = concatenateMatricesByCol(matrix, transposedMatrix, m, n);
    cout << "Concatenated Matrix by Column:" << endl;
    printMatrix(concatenatedMatrixCol, m, n * 2);

    int p;
    cout << "Enter the number of columns for the second matrix: ";
    cin >> p;

    int **secondMatrix;
    generateRandomMatrix(secondMatrix, n, p);

    cout << "Second Matrix:" << endl;
    printMatrix(secondMatrix, n, p);

    int **productMatrix = matrixMultiplication(matrix, secondMatrix, m, n, p);
    cout << "Product Matrix:" << endl;
    printMatrix(productMatrix, m, p);

    int w_sub, h_sub;
    cout << "Enter the width of the submatrix: ";
    cin >> w_sub;
    cout << "Enter the height of the submatrix: ";
    cin >> h_sub;

    int **submatrix = findLargestSubmatrix(matrix, m, n, w_sub, h_sub);
    cout << "Largest Submatrix:" << endl;
    printMatrix(submatrix, w_sub, h_sub);

    deleteMatrix(matrix, m, n);
    deleteMatrix(transposedMatrix, n, m);
    deleteMatrix(concatenatedMatrixRow, m * 2, n);
    deleteMatrix(concatenatedMatrixCol, m, n * 2);
    deleteMatrix(secondMatrix, n, p);
    deleteMatrix(productMatrix, m, p);
    deleteMatrix(submatrix, w_sub, h_sub);

    return 0;
}
