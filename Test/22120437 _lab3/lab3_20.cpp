#include <iostream>

int main() {
    int n;
    std::cout << "Nhập vào một số nguyên dương: ";
    std::cin >> n;

    // Xuất số ngược lại
    int soNguoc = 0;
    int temp = n;
    while (temp != 0) {
        int digit = temp % 10;
        soNguoc = soNguoc * 10 + digit;
        temp /= 10;
    }
    std::cout << "Số ngược lại của " << n << " là: " << soNguoc << std::endl;

    // Đếm số lượng chữ số lẻ và chẵn
    int demChan = 0, demLe = 0;
    temp = n;
    while (temp != 0) {
        int digit = temp % 10;
        if (digit % 2 == 0) {
            demChan++;
        } else {
            demLe++;
        }
        temp /= 10;
    }
    std::cout << "Số lượng chữ số chẵn: " << demChan << std::endl;
    std::cout << "Số lượng chữ số lẻ: " << demLe << std::endl;

    return 0;
}
