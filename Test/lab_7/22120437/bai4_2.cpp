#include <iostream>

using namespace std;

const int MONTHS = 12;

void getData(int temp[][2]) {
    cout << "Nhập nhiệt độ cao và thấp cho mỗi tháng:\n";
    for (int i = 0; i < MONTHS; i++) {
        cout << "Tháng " << i + 1 << ": ";
        cout << "Nhiệt độ cao: ";
        cin >> temp[i][0];
        cout << "Nhiệt độ thấp: ";
        cin >> temp[i][1];
    }
}

double averageHigh(int temp[][2]) {
    int sumHigh = 0;
    for (int i = 0; i < MONTHS; i++) {
        sumHigh += temp[i][0];
    }
    return (double) sumHigh / MONTHS;
}

double averageLow(int temp[][2]) {
    int sumLow = 0;
    for (int i = 0; i < MONTHS; i++) {
        sumLow += temp[i][1];
    }
    return (double) sumLow / MONTHS;
}

int indexHighTemp(int temp[][2]) {
    int highTempIndex = 0;
    for (int i = 1; i < MONTHS; i++) {
        if (temp[i][0] > temp[highTempIndex][0]) {
            highTempIndex = i;
        }
    }
    return highTempIndex;
}

int indexLowTemp(int temp[][2]) {
    int lowTempIndex = 0;
    for (int i = 1; i < MONTHS; i++) {
        if (temp[i][1] < temp[lowTempIndex][1]) {
            lowTempIndex = i;
        }
    }
    return lowTempIndex;
}

int main() {
    int temp[MONTHS][2]; 

    getData(temp);

    double avgHigh = averageHigh(temp);
    double avgLow = averageLow(temp);
    int highTempMonth = indexHighTemp(temp) + 1;
    int lowTempMonth = indexLowTemp(temp) + 1;

    cout << "\nKết quả:\n";
    cout << "Trung bình nhiệt độ cao: " << avgHigh << endl;
    cout << "Trung bình nhiệt độ thấp: " << avgLow << endl;
    cout << "Nhiệt độ cao nhất trong năm: " << temp[indexHighTemp(temp)][0]
         << " (Tháng " << highTempMonth << ")" << endl;
    cout << "Nhiệt độ thấp nhất trong năm: " << temp[indexLowTemp(temp)][1]
         << " (Tháng " << lowTempMonth << ")" << endl;

    return 0;
}