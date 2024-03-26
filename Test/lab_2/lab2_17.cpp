#include <iostream>

using namespace std;

float tinhLuongMoNu(float canNang, float kichThuocCoTay, float kichThuocEo, float kichThuocHong, float kichThuocCanhTay) {
    float A1 = (canNang * 0.732) + 8.987;
    float A2 = kichThuocCoTay / 3.140;
    float A3 = kichThuocEo * 0.157;
    float A4 = kichThuocHong * 0.249;
    float A5 = kichThuocCanhTay * 0.434;
    float B = A1 + A2 - A3 - A4 + A5;
    float luongMo = canNang - B;
    return luongMo;
}

float tinhLuongMoNam(float canNang, float kichThuocCoTay) {
    float A1 = (canNang * 1.082) + 9.442;
    float A2 = kichThuocCoTay * 4.15;
    float B = A1 - A2;
    float luongMo = canNang - B;
    return luongMo;
}

int main() {
    char gioiTinh;
    float canNang, kichThuocCoTay, kichThuocEo, kichThuocHong, kichThuocCanhTay;
    
    cout << "Nhap gioi tinh (n: nu, m: nam): ";
    cin >> gioiTinh;
    cout << "Nhap can nang (kg): ";
    cin >> canNang;
    cout << "Nhap kich thuoc co tay (cm): ";
    cin >> kichThuocCoTay;

    if (gioiTinh == 'n') {
        cout << "Nhap kich thuoc eo (cm): ";
        cin >> kichThuocEo;
        cout << "Nhap kich thuoc hong (cm): ";
        cin >> kichThuocHong;
        cout << "Nhap kich thuoc canh tay (cm): ";
        cin >> kichThuocCanhTay;

        float luongMoNu = tinhLuongMoNu(canNang, kichThuocCoTay, kichThuocEo, kichThuocHong, kichThuocCanhTay);
        float phanTramLuongMoNu = luongMoNu * 100 / canNang;
        cout << "Luong mo trong co the cua ban la: " << luongMoNu << " kg (" << phanTramLuongMoNu << "%)\n";
    } else if (gioiTinh == 'm') {
        float luongMoNam = tinhLuongMoNam(canNang, kichThuocCoTay);
        float phanTramLuongMoNam = luongMoNam * 100 / canNang;
        cout << "Luong mo trong co the cua ban la: " << luongMoNam << " kg (" << phanTramLuongMoNam << "%)\n";
    } else {
        cout << "Loi! Gioi tinh khong hop le.\n";
        return -1;
    }

    return 0;
}
