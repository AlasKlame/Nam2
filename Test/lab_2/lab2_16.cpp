#include <iostream>

using namespace std;

int main() {
    char loaiTaiKhoan;
    int soDuToiThieu, soDuCuoiThang;
    float laiSuat, tongTienLai;

    cout << "Nhap loai tai khoan ('t' cho tiet kiem, 'v' cho vang lai): ";
    cin >> loaiTaiKhoan;
    cout << "Nhap so du toi thieu: ";
    cin >> soDuToiThieu;
    cout << "Nhap so du cuoi thang: ";
    cin >> soDuCuoiThang;

    if (loaiTaiKhoan == 't') {
        if (soDuCuoiThang >= soDuToiThieu) {
            laiSuat = 0.04;
            tongTienLai = (soDuCuoiThang - soDuToiThieu) * laiSuat;
        } else {
            tongTienLai = -10; 
        }
    } else if (loaiTaiKhoan == 'v') {
        
        if (soDuCuoiThang >= soDuToiThieu) {
            if (soDuCuoiThang - soDuToiThieu >= 5000)
                laiSuat = 0.03;
            else
                laiSuat = 0.05;
            tongTienLai = (soDuCuoiThang - soDuToiThieu) * laiSuat;
        } else {
            tongTienLai = -25; 
        }
    } else {
        cout << "Loi! Loai tai khoan khong hop le.\n";
        return -1;
    }

    if (tongTienLai >= 0)
        cout << "Tong so tien lai khach hang nhan duoc: $" << tongTienLai << endl;
    else
        cout << "So tien phat: $" << -tongTienLai << endl;

    return 0;
}
