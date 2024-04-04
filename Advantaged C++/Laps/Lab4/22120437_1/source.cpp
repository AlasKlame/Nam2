#include <iostream>
#include <string.h>

struct SinhVien {
    char* maSo;
    char* hoTen;
    float diemTrungBinh;
};

void ChuanHoaHoTen(char* ten) {
    int len = strlen(ten);
    if (len > 0) {
        ten[0] = toupper(ten[0]);
        for (int i = 1; i < len; ++i) {
            if (ten[i - 1] == ' ' && ten[i] != ' ') { // Xoa khoang trang thua va viet hoa ki tu sau moi khoang trang
                ten[i] = toupper(ten[i]);
            } else {
                ten[i] = tolower(ten[i]);
            }
        }
    }
}

bool KiemTraMaSoHopLe(SinhVien* sv, int n, const char* maSo) {
    if (strlen(maSo) != 7) return false;
    for (int i = 0; i < n; ++i) {
        if (strcmp(sv[i].maSo, maSo) == 0) return false; 
    }
    return true;
}

void NhapSinhVien(SinhVien* sv, int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << "Nhap thong tin sinh vien thu " << i + 1 << ":" << std::endl;
        sv[i].maSo = new char[8]; 
        do {
            std::cout << "Ma so sinh vien (7 chu so): ";
            std::cin >> sv[i].maSo;
        } while (!KiemTraMaSoHopLe(sv, i, sv[i].maSo)); 
        sv[i].hoTen = new char[31]; 
        std::cout << "Ho ten sinh vien (toi da 30 ky tu): ";
        std::cin.ignore();
        std::cin.getline(sv[i].hoTen, 31);
        ChuanHoaHoTen(sv[i].hoTen);
        std::cout << "Diem trung binh: ";
        std::cin >> sv[i].diemTrungBinh;
        while (sv[i].diemTrungBinh < 0 || sv[i].diemTrungBinh > 10) { 
            std::cout << "Diem trung binh khong hop le. Nhap lai: ";
            std::cin >> sv[i].diemTrungBinh;
        }
    }
}

void XuatSinhVien(SinhVien* sv, int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << "Sinh vien thu " << i + 1 << ":" << std::endl;
        std::cout << "Ma so sinh vien: " << sv[i].maSo << std::endl;
        std::cout << "Ho ten sinh vien: " << sv[i].hoTen << std::endl;
        std::cout << "Diem trung binh: " << sv[i].diemTrungBinh << std::endl;
        std::cout << std::endl;
    }
}

void TimSinhVienTheoTen(SinhVien* sv, int n, char* timTen) {
    bool timThay = false;
    std::cout << "----------------------------------" << std::endl;
    std::cout << "Danh sach sinh vien co chuoi '" << timTen << "' trong ho ten:" << std::endl;
    for (int i = 0; i < n; ++i) {
        if (strstr(sv[i].hoTen, timTen) != nullptr) {
            std::cout << "Sinh vien thu " << i + 1 << ":" << std::endl;
            std::cout << "Ma so sinh vien: " << sv[i].maSo << std::endl;
            std::cout << "Ho ten sinh vien: " << sv[i].hoTen << std::endl;
            std::cout << "Diem trung binh: " << sv[i].diemTrungBinh << std::endl;
            std::cout << std::endl;
            timThay = true;
        }
    }
    if (!timThay) {
        std::cout << "Khong tim thay sinh vien nao co chuoi '" << timTen << "' trong ho ten." << std::endl;
    }
}

SinhVien SinhVienCoDiemTBThapNhat(SinhVien* sv, int n) {
    SinhVien svMin = sv[0];
    for (int i = 1; i < n; ++i) {
        if (sv[i].diemTrungBinh < svMin.diemTrungBinh) {
            svMin = sv[i];
        }
    }
    return svMin;
}

void SapXepTheoMSSV(SinhVien* sv, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (strcmp(sv[i].maSo, sv[j].maSo) > 0) {
                std::swap(sv[i], sv[j]);
            }
        }
    }
}

void SapXepTheoDiemTB(SinhVien* sv, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (sv[i].diemTrungBinh < sv[j].diemTrungBinh ||
                (sv[i].diemTrungBinh == sv[j].diemTrungBinh && strcmp(sv[i].maSo, sv[j].maSo) > 0)) {
                std::swap(sv[i], sv[j]);
            }
        }
    }
}

void SapXepTheoTen(SinhVien* sv, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (strcmp(sv[i].hoTen, sv[j].hoTen) > 0 ||
                (strcmp(sv[i].hoTen, sv[j].hoTen) == 0 && strcmp(sv[i].maSo, sv[j].maSo) < 0)) {
                std::swap(sv[i], sv[j]);
            }
        }
    }
}

int DemTenKhacNhau(SinhVien* sv, int n) {
    int dem = 0;
    char* danhSachTen[100];
    for (int i = 0; i < n; ++i) {
        bool daCo = false;
        for (int j = 0; j < dem; ++j) {
            if (strcmp(sv[i].hoTen, danhSachTen[j]) == 0) {
                daCo = true;
                break;
            }
        }
        if (!daCo) {
            danhSachTen[dem] = sv[i].hoTen;
            ++dem;
        }
    }
    std::cout << "Danh sach ten khac nhau trong danh sach:" << std::endl;
    for (int i = 0; i < dem; ++i) {
        std::cout << danhSachTen[i] << std::endl;
    }
    return dem;
}

void TimHaiSinhVienCaoDiemNhat(SinhVien* sv, int n, SinhVien& sv1, SinhVien& sv2) {
    sv1 = sv2 = sv[0];
    for (int i = 1; i < n; ++i) {
        if (sv[i].diemTrungBinh > sv1.diemTrungBinh) {
            sv2 = sv1;
            sv1 = sv[i];
        } else if (sv[i].diemTrungBinh > sv2.diemTrungBinh || 
                   (sv[i].diemTrungBinh == sv2.diemTrungBinh && strcmp(sv[i].maSo, sv2.maSo) < 0)) {
            sv2 = sv[i];
        }
    }
}

int main() {
    int n;
    std::cout << "Nhap so luong sinh vien: ";
    std::cin >> n;

    SinhVien* danhSach = new SinhVien[n];

    NhapSinhVien(danhSach, n);
    std::cout << "Danh sach sinh vien sau khi nhap:" << std::endl;
    XuatSinhVien(danhSach, n);

    char timTen[31];
    std::cout << "Nhap chuoi ky tu can tim kiem trong ho ten: ";
    std::cin.ignore();
    std::cin.getline(timTen, 31);
    TimSinhVienTheoTen(danhSach, n, timTen);

    SinhVien svMin = SinhVienCoDiemTBThapNhat(danhSach, n);
    std::cout << "Sinh vien co diem trung binh thap nhat:" << std::endl;
    std::cout << "Ma so sinh vien: " << svMin.maSo << std::endl;
    std::cout << "Ho ten sinh vien: " << svMin.hoTen << std::endl;
    std::cout << "Diem trung binh: " << svMin.diemTrungBinh << std::endl;

    SapXepTheoMSSV(danhSach, n);
    std::cout << "Danh sach sinh vien sau khi sap xep tang dan theo MSSV:" << std::endl;
    XuatSinhVien(danhSach, n);

    SapXepTheoDiemTB(danhSach, n);
    std::cout << "Danh sach sinh vien sau khi sap xep giam dan theo Diem TB, neu trung sap xep tang dan theo MSSV:" << std::endl;
    XuatSinhVien(danhSach, n);

    SapXepTheoTen(danhSach, n);
    std::cout << "Danh sach sinh vien sau khi sap xep tang dan theo Ten, neu trung sap xep giam dan theo Ho:" << std::endl;
    XuatSinhVien(danhSach, n);

    std::cout << "So ten khac nhau trong danh sach: " << DemTenKhacNhau(danhSach, n) << std::endl;

    SinhVien sv1, sv2;
    TimHaiSinhVienCaoDiemNhat(danhSach, n, sv1, sv2);
    std::cout << "Hai sinh vien co diem trung binh cao nhat:" << std::endl;
    std::cout << "Sinh vien 1:" << std::endl;
    std::cout << "Ma so sinh vien: " << sv1.maSo << std::endl;
    std::cout << "Ho ten sinh vien: " << sv1.hoTen << std::endl;
    std::cout << "Diem trung binh: " << sv1.diemTrungBinh << std::endl;
    std::cout << "Sinh vien 2:" << std::endl;
    std::cout << "Ma so sinh vien: " << sv2.maSo << std::endl;
    std::cout << "Ho ten sinh vien: " << sv2.hoTen << std::endl;
    std::cout << "Diem trung binh: " << sv2.diemTrungBinh << std::endl;

    for (int i = 0; i < n; ++i) {
        delete[] danhSach[i].maSo;
        delete[] danhSach[i].hoTen;
    }
    delete[] danhSach;

    return 0;
}
