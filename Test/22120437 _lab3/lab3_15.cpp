#include <iostream>

double TimChieuCaoLonNhat(double arr[], int n) {
    double maxHeight = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > maxHeight) {
            maxHeight = arr[i];
        }
    }
    return maxHeight;
}

double TimChieuCaoNhoNhat(double arr[], int n) {
    double minHeight = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] < minHeight) {
            minHeight = arr[i];
        }
    }
    return minHeight;
}

int main() {
    const int MAX_SIZE = 100;
    double heights[MAX_SIZE]; 
    double height;
    int count = 0;

    std::cout << "Nhap chieu cao cua hoc sinh (nhap 0 de ket thuc):" << std::endl;
    while (true) {
        std::cin >> height;
        if (height == 0) {
            break; 
        }
        heights[count++] = height;
        if (count >= MAX_SIZE) {
            std::cout << "Vuot qua kich thuoc toi da. Chi nhap toi da " << MAX_SIZE << " phan tu." << std::endl;
            break;
        }
    }

    if (count == 0) {
        std::cout << "Danh sach rong. Khong co hoc sinh nao." << std::endl;
        return 0;
    }

    double maxHeight = TimChieuCaoLonNhat(heights, count);
    double minHeight = TimChieuCaoNhoNhat(heights, count);

    std::cout << "Chieu cao cua hoc sinh dung dau danh sach: " << minHeight << " m" << std::endl;
    std::cout << "Chieu cao cua hoc sinh cuoi danh sach: " << maxHeight << " m" << std::endl;

    return 0;
}
