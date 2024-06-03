#include <iostream>
#include <vector>
#include <fstream>
#include <string.h>
#include <sstream>
#include <ctime>

using namespace std;

class TaiXe {
protected:
    string mataixe;
    int luongCung;
    float hoahong;
    int doanhthu;
    string ngaykihopdong;

public:
    TaiXe(string mataixe1) {
        mataixe = mataixe1;
        luongCung = 0;
        hoahong = 0;
        doanhthu = 0;
        ngaykihopdong = "";
    }

    virtual void input(ifstream &inputFile) {
        inputFile >> luongCung;
        inputFile.ignore();
        inputFile >> hoahong;
        inputFile.ignore(2);
        inputFile >> doanhthu;
        inputFile.ignore(2);
        getline(inputFile, ngaykihopdong);
        
        hoahong /= 100;
    }

    virtual float tinhDoanhThuThucTe() {
        return 0; 
    }

    virtual void output(ofstream &outputFile) {
        outputFile << mataixe << "," << luongCung << "," << hoahong << "," << doanhthu << "," << ngaykihopdong << endl;
            
    }

    string getMataixe() {
        return mataixe;
    }

    bool checkNgayKiHopDong(const string& ngay) {
        if (ngay.length() != 10) {
            return false;
        }

        if (ngay[2] != '/' || ngay[5] != '/') {
            return false;
        }

        int ngayInt = stoi(ngay.substr(0, 2));
        int thangInt = stoi(ngay.substr(3, 2));
        int namInt = stoi(ngay.substr(6, 4));

        time_t now = time(0);
        tm *ltm = localtime(&now);
        int namHienTai =1900 + ltm->tm_year;
        int thangHienTai = 1 + ltm->tm_mon;
        int ngayHienTai = ltm->tm_mday;
        
        if (ngayInt < 1 || ngayInt > 31 || thangInt < 1 || thangInt > 12 || namInt < 1  ) {
            return false;
        }
        if(ngayInt > ngayHienTai && thangInt >= thangHienTai && namInt >= namHienTai) {
            return false;
        }


        if ((thangInt == 2 && ngayInt > 29) || (thangInt == 4 || thangInt == 6 || thangInt == 9 || thangInt == 11) && ngayInt > 30) {
            return false;
        }

        return true;
    }

    string getNgayKiHopDong() {
        return ngaykihopdong;
    }

    void setHoahong(float newHoahong) {
        hoahong = newHoahong;
    }
};

class TaiXeXeMay : public TaiXe {
public:
    TaiXeXeMay(string mataixe1) : TaiXe(mataixe1) {
        luongCung = 0;
        hoahong = 0;
        doanhthu = 0;
        ngaykihopdong = "";
    }
    virtual void input(ifstream &inputFile) override {
        TaiXe::input(inputFile);
    }

    virtual float tinhDoanhThuThucTe() override {
        float daiNgo = 0;
        if (doanhthu > 25000000) {
            daiNgo += doanhthu * 0.02;
        } else if (doanhthu > 20000000) {
            daiNgo += doanhthu * 0.01;
        }
        return luongCung + (doanhthu * hoahong) + daiNgo;
    }

    virtual void output(ofstream &outputFile) override {
        TaiXe::output(outputFile);
    }
};

class TaiXeXeTai : public TaiXe {
public:
    TaiXeXeTai(string mataixe1) : TaiXe(mataixe1) {
        luongCung = 0;
        hoahong = 0;
        doanhthu = 0;
        ngaykihopdong = "";
    }
    virtual void input(ifstream &inputFile) override {
        TaiXe::input(inputFile);
    }

    virtual float tinhDoanhThuThucTe() override {
        return luongCung + (doanhthu * hoahong);
    }

    virtual void output(ofstream &outputFile) override {
        TaiXe::output(outputFile);
    }
};

bool check(string a, char b) {
    for (int i = 0; i < a.length(); i++) {
        if (a[i] == b) {
            return true;
        }
    }
    return false;
}

class CongTyTaiXe {
private:
    vector<TaiXe*> List;

public:
    CongTyTaiXe() {
        List.clear();
    }

    TaiXe* createTaiXe(ifstream &inFile) {
        string mataixe;
        getline(inFile, mataixe, ',');
        if (check(mataixe, 'B')) {
            return new TaiXeXeMay(mataixe);
        } else if (check(mataixe, 'C')) {
            return new TaiXeXeTai(mataixe);
        }
        
        return nullptr;
    }

    void addTaiXe(TaiXe *a) {
        List.push_back(a);
    }

    void input(ifstream &inFile) {
        TaiXe* taixe;
        while (inFile.good()) { 
            taixe = createTaiXe(inFile);
            if (taixe != nullptr) {
                taixe->input(inFile);
                addTaiXe(taixe);
            } else {
                break;
            }
        }
    }

    void output(ofstream &outFile) {
        for (int i = 0; i < List.size(); i++) {
            List[i]->output(outFile);
        }
    }

    void lietKeTaiXeNgayKiHopDongSai() {
        cout << "Danh sach tai xe co ngay ki hop dong sai:" << endl;
        for (int i = 0; i < List.size(); i++) {
            if (!List[i]->checkNgayKiHopDong(List[i]->getNgayKiHopDong())) {
                cout << "Ma tai xe: " << List[i]->getMataixe() << ", Ngay ki hop dong: " << List[i]->getNgayKiHopDong() << endl;
            }
        }
    }

    void thayDoiHoahong() {
        string maTaiXe;
        float hoahongMoi;

        cout << "Nhap ma tai xe can thay doi hoa hong: ";
        cin >> maTaiXe;

        cout << "Nhap hoa hong moi: ";
        cin >> hoahongMoi;

        for (int i = 0; i < List.size(); i++) {
            if (List[i]->getMataixe() == maTaiXe) {
                List[i]->setHoahong(hoahongMoi);
                cout << "Da thay doi hoa hong thanh cong!" << endl;
                return;
            }
        }

        cout << "Khong tim thay tai xe co ma " << maTaiXe << endl;
    }
};

int main() {
    CongTyTaiXe a;
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");
    a.input(inputFile);
    a.lietKeTaiXeNgayKiHopDongSai();
    a.thayDoiHoahong();
    a.output(outputFile);
    inputFile.close();
    outputFile.close();
    
    return 0;
}