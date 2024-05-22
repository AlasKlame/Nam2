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

// Hàm convert nội dung file sao cho mỗi dòng có 60 kí tự
int convertFile60CharsperLine(char input[], char output[]) {
    ifstream inFile(input);
    ofstream outFile(output);

    if (!inFile.is_open() || !outFile.is_open()) {
        cout << "Lỗi mở file!" << endl;
        return -1;
    }

    string line, temp;
    int count = 0;
    while (getline(inFile, line)) {
        temp = "";
        for (int i = 0; i < line.length(); i++) {
            temp += line[i];
            count++;
            if (count == 60) {
                outFile << temp << endl;
                temp = "";
                count = 0;
            }
        }
        if (count > 0) {
            outFile << temp << endl;
            count = 0;
        }
    }

    inFile.close();
    outFile.close();
    return 0;
}

// Hàm tính giá trị trung bình số lượng các kí tự trên 1 dòng
int countAverageChar(char input[]) {
    ifstream inFile(input);

    if (!inFile.is_open()) {
        cout << "Lỗi mở file!" << endl;
        return -1;
    }

    string line;
    int totalChars = 0;
    int numLines = 0;
    while (getline(inFile, line)) {
        totalChars += line.length();
        numLines++;
    }

    inFile.close();

    if (numLines == 0) {
        return 0;
    }
    return totalChars / numLines;
}

// Hàm in code của chính nó ra màn hình
int printSource(char input[]) {
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

// Hàm xóa đi dòng cuối cùng
int deleteLastLine(char input[]) {
    ifstream inFile(input);
    ofstream outFile("temp.txt"); 

    if (!inFile.is_open() || !outFile.is_open()) {
        cout << "Lỗi mở file!" << endl;
        return -1;
    }

    string line;
    while (getline(inFile, line)) {
        outFile << line << endl;
    }
    outFile.close();

    inFile.close();
    inFile.open("temp.txt");
    outFile.close();
    outFile.open(input);
    int count = 0;
    int numLines = 0; 
    while (getline(inFile, line)) {
        numLines++; 
        if (count < numLines - 1) {
            outFile << line << endl;
        }
        count++;
    }

    inFile.close();
    outFile.close();

    remove("temp.txt");
    return 0;
}

// Hàm xóa đi các dòng trống (dòng chỉ có kí tự \n)
int deleteEmptyLines(char input[]) {
    ifstream inFile(input);
    ofstream outFile("temp.txt"); 

    if (!inFile.is_open() || !outFile.is_open()) {
        cout << "Lỗi mở file!" << endl;
        return -1;
    }

    string line;
    while (getline(inFile, line)) {
        if (!line.empty()) {
            outFile << line << endl;
        }
    }
    outFile.close();

    inFile.close();
    inFile.open("temp.txt");
    outFile.close();
    outFile.open(input);
    while (getline(inFile, line)) {
        outFile << line << endl;
    }

    inFile.close();
    outFile.close();

    // Xóa file temp
    remove("temp.txt");
    return 0;
}

// Hàm chèn một dòng trống sau dòng thứ 7
int insert7thLine(char input[]) {
    ifstream inFile(input);
    ofstream outFile("temp.txt"); 

    if (!inFile.is_open() || !outFile.is_open()) {
        cout << "Lỗi mở file!" << endl;
        return -1;
    }

    string line;
    int count = 0;
    while (getline(inFile, line)) {
        outFile << line << endl;
        count++;
        if (count == 7) {
            outFile << endl;
        }
    }
    outFile.close();

    inFile.close();
    inFile.open("temp.txt");
    outFile.close();
    outFile.open(input);
    while (getline(inFile, line)) {
        outFile << line << endl;
    }

    inFile.close();
    outFile.close();

  
    remove("temp.txt");
    return 0;
}

// Hàm chèn giữa các dòng một dòng trống (double-spaced)
int insertDoubleSpaced(char input[]) {
    ifstream inFile(input);
    ofstream outFile("temp.txt"); 

    if (!inFile.is_open() || !outFile.is_open()) {
        cout << "Lỗi mở file!" << endl;
        return -1;
    }

    string line;
    while (getline(inFile, line)) {
        outFile << line << endl;
        outFile << endl;
    }
    outFile.close();

    // Đọc file temp và ghi lại vào input
    inFile.close();
    inFile.open("temp.txt");
    outFile.close();
    outFile.open(input);
    while (getline(inFile, line)) {
        outFile << line << endl;
    }

    inFile.close();
    outFile.close();

    // Xóa file temp
    remove("temp.txt");
    return 0;
}

// Hàm chèn dòng thứ 2 vào các dòng có số thứ tự chia hết cho 2
int insert2thLine(char input[]) {
    ifstream inFile(input);
    ofstream outFile("temp.txt"); 

    if (!inFile.is_open() || !outFile.is_open()) {
        cout << "Lỗi mở file!" << endl;
        return -1;
    }

    string line;
    int count = 0;
    while (getline(inFile, line)) {
        outFile << line << endl;
        count++;
        if (count % 2 == 0) {
            outFile << "Dòng thứ 2" << endl; 
        }
    }
    outFile.close();

    // Đọc file temp và ghi lại vào input
    inFile.close();
    inFile.open("temp.txt");
    outFile.close();
    outFile.open(input);
    while (getline(inFile, line)) {
        outFile << line << endl;
    }

    inFile.close();
    outFile.close();

    // Xóa file temp
    remove("temp.txt");
    return 0;
}

// Hàm xóa 2 kí tự đầu tiên của mỗi dòng
int delete2FirstChars(char input[]) {
    ifstream inFile(input);
    ofstream outFile("temp.txt"); 

    if (!inFile.is_open() || !outFile.is_open()) {
        cout << "Lỗi mở file!" << endl;
        return -1;
    }

    string line;
    while (getline(inFile, line)) {
        if (line.length() >= 2) {
            outFile << line.substr(2) << endl;
        } else {
            outFile << line << endl; 
        }
    }
    outFile.close();

    // Đọc file temp và ghi lại vào input
    inFile.close();
    inFile.open("temp.txt");
    outFile.close();
    outFile.open(input);
    while (getline(inFile, line)) {
        outFile << line << endl;
    }

    inFile.close();
    outFile.close();

    // Xóa file temp
    remove("temp.txt");
    return 0;
}

int sumDigits(int num){
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;

}

// Hàm ghi các số lẻ < n có tổng các chữ số chia hết cho 2 vào file
int writeListOddNumbers(int n, char output[]) {
    ofstream outFile(output);

    if (!outFile.is_open()) {
        cout << "Lỗi mở file!" << endl;
        return -1;
    }

    for (int i = 1; i < n; i += 2) {
        if (sumDigits(i) % 2 == 0) {
            outFile << i << " ";
        }
    }
    outFile.close();
    return 0;
}


// Hàm kiểm tra số nguyên tố
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// Hàm đọc file output ở câu trên, và trả về số lượng số nguyên tố danh sách các số lẻ nói trên
int countPrimes(char input[]) {
    ifstream inFile(input);

    if (!inFile.is_open()) {
        cout << "Lỗi mở file!" << endl;
        return -1;
    }

    int num, countPrimes = 0;
    while (inFile >> num) {
        if (isPrime(num)) {
            countPrimes++;
        }
    }

    inFile.close();
    return countPrimes;
}

int sumMatrix(char input[]) {
    ifstream inFile(input);

    if (!inFile.is_open()) {
        cout << "Lỗi mở file!" << endl;
        return -1;
    }

    int m, n;
    inFile >> m >> n; 

    int matrix[100][100]; 
    int sum = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            inFile >> matrix[i][j];
            sum += matrix[i][j];
        }
    }

    inFile.close();
    return sum;
}

void sortListName(char input[]) {
    ifstream inFile(input);

    if (!inFile.is_open()) {
        cout << "Lỗi mở file!" << endl;
        return;
    }

    int numNames;
    inFile >> numNames; 
    vector<string> names;
    string name;
    while (inFile >> name) {
        names.push_back(name);
    }

    sort(names.begin(), names.end());

    cout << "Danh sách tên thí sinh sau khi sắp xếp là: ";
    for (int i = 0; i < names.size(); i++) {
        cout << names[i] << " ";
    }
    cout << endl;

    inFile.close();
}
void sortListNameNoNums(char input[]) {
    ifstream inFile(input);

    if (!inFile.is_open()) {
        cout << "Lỗi mở file!" << endl;
        return;
    }

    string names[MAX_NAMES];
    int count = 0;
    string name;
    while (getline(inFile, name)) {
        names[count] = name;
        count++;
    }

    sort(names, names + count); 

    cout << "Danh sách tên thí sinh sau khi sắp xếp là: ";
    for (int i = 0; i < count; i++) {
        cout << names[i] << " ";
    }
    cout << endl;

    inFile.close();
}

