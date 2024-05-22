#include <iostream>
#include <string>

using namespace std;

const int ROWS = 13;
const int COLS = 6;

char seats[ROWS][COLS] = {
    {'*', '*', '*', '*', '*', '*'}, 
    {'*', '*', '*', '*', '*', '*'}, 
    {'*', '*', '*', '*', '*', '*'}, 
    {'*', '*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*', '*'}, 
    {'*', '*', '*', '*', '*', '*'}, 
    {'*', '*', '*', '*', '*', '*'}, 
    {'*', '*', '*', '*', '*', '*'}, 
    {'*', '*', '*', '*', '*', '*'}, 
    {'*', '*', '*', '*', '*', '*'}, 
    {'*', '*', '*', '*', '*', '*'}, 
    {'*', '*', '*', '*', '*', '*'}, 
    {'*', '*', '*', '*', '*', '*'}  
};

void displaySeats() {
    cout << "Sơ đồ chỗ ngồi:\n";
    cout << "  A B C D E F\n";
    for (int i = 0; i < ROWS; i++) {
        cout << "Row " << i + 1 << " ";
        for (int j = 0; j < COLS; j++) {
            cout << seats[i][j] << " ";
        }
        cout << endl;
    }
}

bool isValidSeat(int row, char col) {
    if (row < 1 || row > ROWS || (col < 'A' || col > 'F')) {
        return false;
    }
    return true;
}

    void bookSeat() {
        int row;
        char col;
        char classType;

        cout << "Nhập loại vé (hạng nhất(A), hạng thương gia(B) hoặc hạng phổ thông(C)): ";
        cin >> classType;
        cin.ignore();

        cout << "Nhập hàng ghế mong muốn: ";
        cin >> row;
        cout << "Nhập cột ghế mong muốn (A-F): ";
        cin >> col;

        if (!isValidSeat(row, col)) {
            cout << "Chỗ ngồi không hợp lệ. Vui lòng thử lại.\n";
            return;
        }

        if (classType == 'A' && (row == 1 || row == 2)) {
            if (seats[row - 1][col - 'A'] == '*') {
                seats[row - 1][col - 'A'] = 'X';
                cout << "Chỗ ngồi đã được đặt.\n";
            } else {
                cout << "Chỗ ngồi đã có người đặt.\n";
            }
        } else if (classType == 'B' && (row >= 3 && row <= 7)) {
            if (seats[row - 1][col - 'A'] == '*') {
                seats[row - 1][col - 'A'] = 'X';
                cout << "Chỗ ngồi đã được đặt.\n";
            } else {
                cout << "Chỗ ngồi đã có người đặt.\n";
            }
        } else if (classType == 'C' && (row >= 8 && row <= 13)) {
            if (seats[row - 1][col - 'A'] == '*') {
                seats[row - 1][col - 'A'] = 'X';
                cout << "Chỗ ngồi đã được đặt.\n";
            } else {
                cout << "Chỗ ngồi đã có người đặt.\n";
            }
        } else {
            cout << "Loại vé không hợp lệ.\n";
        }
    }

int main() {
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Hiển thị sơ đồ chỗ ngồi\n";
        cout << "2. Đặt chỗ\n";
        cout << "3. Thoát\n";
        cout << "Chọn lựa chọn: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displaySeats();
                break;
            case 2:
                bookSeat();
                break;
            case 3:
                cout << "Kết thúc chương trình.\n";
                break;
            default:
                cout << "Lựa chọn không hợp lệ. Vui lòng thử lại.\n";
        }
    } while (choice != 3);

    return 0;
}