#include<iostream>
#include<cstring>
#include<iomanip>

using namespace std;

struct Student {
    char *name;
    float mathGrade;
    float physicsGrade;
    float chemicalGrade;
    float averageGrade;
    char classification[20];
    char district[20];
    char city[50];
};

void input(Student &student) {
    student.name = new char[41];
    cin.ignore();
    cout << "Nhap ten sinh vien: ";
    cin.getline(student.name, 40);
    cout << "Nhap diem toan: ";
    cin >> student.mathGrade;
    cout << "Nhap diem ly: ";
    cin >> student.physicsGrade;
    cout << "Nhap diem hoa: ";
    cin >> student.chemicalGrade;
    cin.ignore();
    cout << "Nhap quan/huyen: ";
    cin.getline(student.district, 20);
    cout << "Nhap ten thanh pho: ";
    cin.getline(student.city, 50);
    cin.ignore();
}

void averageGrade(Student &student) {
    student.averageGrade = (student.mathGrade + student.physicsGrade + student.chemicalGrade) / 3;
}

void classification(Student &student) {
    if (student.averageGrade >= 9) {
        strcpy(student.classification, "Xuat sac");
    } else if (student.averageGrade >= 8) {
        strcpy(student.classification, "Gioi");
    } else if (student.averageGrade >= 7) {
        strcpy(student.classification, "Kha");
    } else if (student.averageGrade >= 5) {
        strcpy(student.classification, "Trung binh");
    } else {
        strcpy(student.classification, "Yeu");
    }
}

void output(Student &student) {
    averageGrade(student);
    classification(student);
    cout << student.name << endl;
    cout << "Diem toan: " << student.mathGrade << endl;
    cout << "Diem ly: " << student.physicsGrade << endl;
    cout << "Diem hoa: " << student.chemicalGrade << endl;
    cout << "Dia chi: " << student.district << "/" << student.city << endl;
    cout << "Diem trung binh: " << fixed << setprecision(2) << student.averageGrade << endl;
    cout << "Xep loai: " << student.classification << endl;
}

void findStudentfromAddress(Student *student, int n, char district[20], char city[50]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(student[i].district, district) == 0 || strcmp(student[i].city, city) == 0) {
            cout << "Sinh vien thu " << i + 1 << ":" << endl;
            cout << student[i].name << endl;
            cout << "Diem toan: " << student[i].mathGrade << endl;
            cout << "Diem ly: " << student[i].physicsGrade << endl;
            cout << "Diem hoa: " << student[i].chemicalGrade << endl;
            cout << "Dia chi: " << student[i].district << "/" << student[i].city << endl;
            cout << "Diem trung binh: " << fixed << setprecision(2) << student[i].averageGrade << endl;
            cout << "Xep loai: " << student[i].classification << endl;
        }
    }
}

int main() {
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    Student *students = new Student[n];

    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin sinh vien thu " << i + 1 << ":" << endl;
        input(students[i]);
    }

    char district[20];
    char city[50];
    cout << "Nhap quan/huyen can tim: ";
    cin.getline(district, 20);
    cout << "Nhap ten thanh pho can tim: ";
    cin.getline(city, 50);

    findStudentfromAddress(students, n, district, city);

    delete[] students;

    return 0;
}
