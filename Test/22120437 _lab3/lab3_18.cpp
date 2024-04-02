#include <iostream>

// Hàm tính dãy số ak và trả về giá trị k
int TinhDaySo(int x) {
    int k = 0;
    std::cout << "Dãy số là: " << x;
    while (x != 1) {
        if (x % 2 == 0) {
            x = x / 2;
        } else {
            x = 3 * x + 1;
        }
        std::cout << ", " << x;
        k++;
    }
    std::cout << std::endl;
    return k;
}

int main() {
    int x;
    std::cout << "Nhập giá trị cho x: ";
    std::cin >> x;

    int k = TinhDaySo(x);
    std::cout << "k = " << k << std::endl;

    return 0;
}
