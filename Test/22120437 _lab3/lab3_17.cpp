#include <iostream>
#include <unistd.h> 

int main() {
    int phut, giay;

    std::cout << "Nhap vao so phut: ";
    std::cin >> phut;
    std::cout << "Nhap vao so giay: ";
    std::cin >> giay;

    if (phut < 0 || giay < 0 || giay >= 60) {
        std::cout << "Gia tri nhap vao khong hop le." << std::endl;
        return 0;
    }

    int tongGiay = phut * 60 + giay;

    while (tongGiay >= 0) {
        int phutHienTai = tongGiay / 60;
        int giayHienTai = tongGiay % 60;
        printf("%02d:%02d", phutHienTai, giayHienTai);
        if (tongGiay == 5) {
            std::cout << " Tich tac";
        }
        if (tongGiay == 0) {
            std::cout << " Reng reng reng";
        }
        std::cout << std::endl;
        sleep(1);
        tongGiay--;
    }

    return 0;
}
