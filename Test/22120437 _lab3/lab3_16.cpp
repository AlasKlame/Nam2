#include <iostream>

int main() {
    int luaChon;
    double soThuNhat, soThuHai;

    while (true) {
        std::cout << "MAY TINH DON GIAN" << std::endl;
        std::cout << "1. Cong" << std::endl;
        std::cout << "2. Tru" << std::endl;
        std::cout << "3. Nhan" << std::endl;
        std::cout << "4. Chia" << std::endl;
        std::cout << "0. Dung chuong trinh" << std::endl;
        std::cout << "Lua chon cua ban la: ";
        std::cin >> luaChon;

        switch (luaChon) {
            case 1:
                std::cout << "Nhap hai so can cong: ";
                std::cin >> soThuNhat >> soThuHai;
                std::cout << "Tong cua " << soThuNhat << " va " << soThuHai << " la: " << soThuNhat + soThuHai << std::endl;
                break;
            case 2:
                std::cout << "Nhap hai so can tru: ";
                std::cin >> soThuNhat >> soThuHai;
                std::cout << "Hieu cua " << soThuNhat << " va " << soThuHai << " la: " << soThuNhat - soThuHai << std::endl;
                break;
            case 3:
                std::cout << "Nhap hai so can nhan: ";
                std::cin >> soThuNhat >> soThuHai;
                std::cout << "Tich cua " << soThuNhat << " va " << soThuHai << " la: " << soThuNhat * soThuHai << std::endl;
                break;
            case 4:
                std::cout << "Nhap so bi chia va so chia: ";
                std::cin >> soThuNhat >> soThuHai;
                if (soThuHai != 0) {
                    std::cout << "Thuong cua " << soThuNhat << " va " << soThuHai << " la: " << soThuNhat / soThuHai << std::endl;
                } else {
                    std::cout << "Khong the chia cho 0." << std::endl;
                }
                break;
            case 0:
                std::cout << "Cam on da su dung chuong trinh." << std::endl;
                return 0;
            default:
                std::cout << "Lua chon khong hop le. Vui long chon lai." << std::endl;
        }
    }

    return 0;
}
