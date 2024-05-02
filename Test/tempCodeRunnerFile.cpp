#include <iostream>
using namespace std;

// Hàm kiểm tra số lần xuất hiện của mỗi chữ số có lớn hơn k hay không
bool countDigits(int n, int k) {
    cout << "Số lần xuất hiện của mỗi chữ số trong số đã cho:" << endl;
    for (int digit = 0; digit <= 9; digit++) {
        int count = 0;
        int temp = n;
        while (temp > 0) {
            if (temp % 10 == digit) {
                count++;
            }
            temp /= 10;
        }
        if (count > k) {
            return false;
        }
    }
    return true;
}

int createLargestSpecialNumber(int n, int k) {
    int specialNumber = 0;
    for (int digit = 9; digit >= 0; digit--) {
        int temp = n;
        int place = 1;
        int nextPlace = 10;
        while (temp > 0) {
            int currentDigit = temp % 10;
            // Chỉ thêm vào specialNumber những chữ số không vượt quá k lần
            if (currentDigit == digit && k > 0) {
                specialNumber += digit * place;
                place = nextPlace;
                nextPlace *= 10;
                k--;
            }
            temp /= 10;
        }
    }
    return specialNumber;
}

int main() {
    int k, n;

    cout << "Input k: ";
    cin >> k;
    cout << "Input n: ";
    cin >> n;

    if(countDigits(n, k)) {
        cout << "Không cần xóa chữ số nào." << endl;
        cout << "Output: " << n << endl;
    } else {
        int specialNumber = createLargestSpecialNumber(n, k);
        cout << "Output: " << specialNumber << endl;
    }

    return 0;
}
