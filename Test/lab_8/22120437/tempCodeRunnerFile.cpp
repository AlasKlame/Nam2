#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
const int MAX_NAMES = 100; 
// Hàm sao chép nội dung input.txt vào output.txt
int copyFile(char input[], char output[]) {
    ifstream inFile(input);
    ofstream outFile(output);

    if (!inFile.is_open() || !outFile.is_open()) {
        cout << "Lỗi mở file!" << endl;
        return -1;
    }

    string line;
    while (getline(inFile, line)) {
        outFile << line << endl;
    }

    inFile.close();
    outFile.close();
    return 0;
}

int convertFile60Charperline(char input[], char output[]) {
    ifstream inFile(input);
    ofstream outFile(output);

    if (!inFile.is_open() || !outFile.is_open()) {
        cout << "Lỗi mở file!" << endl;
        return -1;
    }

    string line;
    int count = 0;
    while (getline(inFile, line)) {
        count++;
        outFile << line;
        if (count % 60 == 0) {
            outFile << endl;
        }
    }

    inFile.close();
    outFile.close();
    return 0;
}


int countAveragChar(char input[]){
    ifstream inFile(input);
    if (!inFile.is_open()) {
        cout << "Lỗi mở file!" << endl;
        return -1;
    }

    string line;
    int count = 0;
    int sum = 0;
    while (getline(inFile, line)) {
        count++;
        sum += line.length();
    }

    inFile.close();
    return sum / count;

}

int printSource(char input[]){
    ifstream inFile(input);
    if (!inFile.is_open()) {
        cout << "Lỗi mở file!" << endl;
        return -1;
    }

    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }

    inFile.close();
    return 0;
}

int deleteLastLine(char input[]){
    ifstream inFile(input);
    ofstream outFile("temp.txt");

    if (!inFile.is_open() || !outFile.is_open()) {
        cout << "Lỗi mở file!" << endl;
        return -1;
    }

    string line;
    vector<string> lines;
    while (getline(inFile, line)) {
        lines.push_back(line);
    }

    for (int i = 0; i < lines.size() - 1; i++) {
        outFile << lines[i] << endl;
    }

    inFile.close();
    outFile.close();
    remove(input);
    rename("temp.txt", input);
    return 0;
}

int deleteEmptyLine(char input[]){
    ifstream inFile(input);
    ofstream outFile("temp.txt");

    if (!inFile.is_open() || !outFile.is_open()) {
        cout << "Lỗi mở file!" << endl;
        return -1;
    }

    string line;
    while (getline(inFile, line)) {
        if (line.length() > 0) {
            outFile << line << endl;
        }
    }

    inFile.close();
    outFile.close();
    remove(input);
    rename("temp.txt", input);
    return 0;
}

int insert7thLine(char input[]){
    ifstream inFile(input);
    ofstream outFile("temp.txt");

    if (!inFile.is_open() || !outFile.is_open()) {
        cout << "Lỗi mở file!" << endl;
        return -1;
    }

    string line;
    int count = 0;
    while (getline(inFile, line)) {
        count++;
        if (count == 7) {
            outFile << "" << endl;
        }
        outFile << line << endl;
    }

    inFile.close();
    outFile.close();
    remove(input);
    rename("temp.txt", input);
    return 0;

}
int insertDoubleSpace(char input[]){
    ifstream inFile(input);
    

    if (!inFile.is_open() ) {
        cout << "Lỗi mở file!" << endl;
        return -1;
    }

    string line;
    while (getline(inFile, line)) {
        cout  << line << endl;
        cout  << "" << endl;
    }

    inFile.close();
    return 0;

}

int delete2FirstChars(char input[]){
    ifstream inFile(input);
    ofstream outFile("temp.txt");

    if (!inFile.is_open() || !outFile.is_open()) {
        cout << "Lỗi mở file!" << endl;
        return -1;
    }

    string line;
    while (getline(inFile, line)) {
        if (line.length() > 2) {
            outFile << line.substr(2) << endl;
        }
    }

    inFile.close();
    outFile.close();
    remove(input);
    rename("temp.txt", input);
    return 0;

}

bool checkPrime(int n){
    if(n < 2){
        return false;
    }
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

int writeListOddNumbers(int n, char output[]){
    ofstream outFile(output);

    if (!outFile.is_open()) {
        cout << "Lỗi mở file!" << endl;
        return -1;
    }

    for (int i = 1; i <= n; i += 2) {
        outFile << i << endl;
    }

    outFile.close();
    return 0;

}
int countPrime(int n, char output[]){
    ofstream outFile(output);

    if (!outFile.is_open()) {
        cout << "Lỗi mở file!" << endl;
        return -1;
    }

    for (int i = 1; i <= n; i += 2) {
        if(checkPrime(i)){
            outFile << i << endl;
        }
    }

    outFile.close();
    return 0;

}

int sumMatrix(char input[]){
    ifstream inFile(input);
    if (!inFile.is_open()) {
        cout << "Lỗi mở file!" << endl;
        return -1;
    }

    int n, m;
    inFile >> n >> m;
    int matrix[100][100];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            inFile >> matrix[i][j];
        }
    }

    inFile.close();
    int sum = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            sum += matrix[i][j];
        }
    }
    return sum;

}

void bubbleSort(int arr[], int n) {
  

  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
      }
    }
  }
}



int min_difference(int arr[], int n) {
    int total_sum = 0;
    for (int i = 0; i < n; i++) {
        total_sum += arr[i];
    }

    int min_diff = 1e9;

    for (int i = 1; i < n; i++) {
        int left_sum = 0;
        for (int j = 0; j < i; j++) {
            left_sum += arr[j];
        }
        int right_sum = total_sum - left_sum;
        int diff = abs(left_sum - right_sum);
        if( diff < min_diff){
            min_diff = diff;
        }
    }

    return min_diff;
}

void resetArray(int arr[], int &n){

    for(int i = 1; i < n ; i++){
        if(arr[i-1] % 2 != 0 && arr[i] % 2 != 0){
            arr[i-1] = arr[i] + arr[i-1];
            for(int j = i; j < n - 1; j++){
                arr[j] = arr[j+1];
            }
            n--;
        }
        
    }
}

int main() {
    int arr[] = {1, 2, 3, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    resetArray(arr, n);
    for(int i = 0; i < n; i++){
        cout << arr[i];
    }

    return 0;
}