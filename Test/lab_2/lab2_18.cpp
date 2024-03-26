#include <iostream>

using namespace std;

float tinhBMI(float canNang, float chieuCao) {
    return canNang / (chieuCao * chieuCao);
}

void inTinhTrangBMI(float BMI) {
    cout << "Chinh phuc cao nguyen thong qua BMI!!!\n";
    cout << "BMI cua ban la: " << BMI << endl;
    if (BMI < 18.5)
        cout << "Ban dang duoi chuan!\n";
    else if (BMI >= 18.5 && BMI < 25)
        cout << "Ban dang o trang thai chuan!\n";
    else if (BMI >= 25 && BMI < 30)
        cout << "Ban dang thua can!\n";
    else if (BMI >= 30 && BMI < 40)
        cout << "Ban dang bi beo phi, nen giam can!\n";
    else
        cout << "Ban dang rat beo phi, can giam can ngay!\n";
}

int main() {
    float canNang, chieuCao;

    cout << "Nhap can nang (kg): ";
    cin >> canNang;
    cout << "Nhap chieu cao (m): ";
    cin >> chieuCao;

    // Tính chỉ số BMI
    float BMI = tinhBMI(canNang, chieuCao);

    inTinhTrangBMI(BMI);

    return 0;
}
