#include <iostream>
#include <cmath>
using namespace std;

int checkLuckyTicket(int ticket) {
    // Đếm số chữ số của số vé
    int num_digits = (int)log10(ticket) + 1;

    // Kiểm tra xem số lượng chữ số của số vé có chẵn không
    if (num_digits % 2 != 0) {
        return 0; // Nếu không phải số có số chẵn chữ số, trả về 0
    }

    // Tính tổng của nửa đầu và nửa sau của số vé
    int first_half_sum = 0, second_half_sum = 0;
    int half_digits = num_digits / 2;
    for (int i = 0; i < num_digits; ++i) {
        int digit = ticket % 10; // Lấy chữ số cuối cùng
        ticket /= 10; // Loại bỏ chữ số cuối cùng
        if (i < half_digits) {
            first_half_sum += digit;
        } else {
            second_half_sum += digit;
        }
    }

    // So sánh tổng của nửa đầu và nửa sau
    if (first_half_sum == second_half_sum) {
        return 1; // Nếu tổng hai nửa bằng nhau, trả về 1
    } else {
        return 0; // Ngược lại, trả về 0
    }
}

int main() {
    int ticket;
    cout << "Nhap so ve: ";
    cin >> ticket;

    if (checkLuckyTicket(ticket)) {
        cout << "La ve may man" << endl;
    } else {
        cout << "Khong phai la ve may man" << endl;
    }

    return 0;
}
