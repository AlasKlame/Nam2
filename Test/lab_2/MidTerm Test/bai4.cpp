#include <iostream>

using namespace std;

const int MAX_SIZE = 100; 

void printPattern(int n) {
    int size = n * 4 - 3;
    char arr[MAX_SIZE][MAX_SIZE];

    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            arr[i][j] = ' ';
        }
    }
 
    for (int layer = 0; layer < n; ++layer) {
        int upperLeft = layer * 2; 
        int lowerRight = size - layer * 2 - 1; 
        for (int i = upperLeft; i <= lowerRight; ++i) {
            arr[upperLeft][i] = arr[lowerRight][i] = '*';
            arr[i][upperLeft] = arr[i][lowerRight] = '*';
        }
    }
 
    for (int y = 0; y < size; y++) {
        if (y % 2 == 0) { // Chỉ in các dòng chẵn
            for (int x = 0; x < size; x++) {
                cout << arr[y][x];
            }
            cout << endl; 
        }
    }
}

int main() {
    int n;
    cout << "Input: n = ";
    cin >> n;
    if(n * 4 - 3 > MAX_SIZE) {
        cout << "Error: n is too large for the maximum size." << endl;
    } else {
        printPattern(n);
    }
    return 0;
}
