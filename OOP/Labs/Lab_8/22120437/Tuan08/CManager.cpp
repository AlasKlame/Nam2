#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>
#include<iomanip>
#include<algorithm>
using namespace std;




class CNhanVien{
    protected:
        string m_ID;
        int m_Department;
        string m_Name;
        string m_Birthday;
        string m_Address;
        float m_WageCoefficient;
    public:
        CNhanVien(){
            m_ID = "";
            m_Department = 0;
            m_Name = "";
            m_Birthday = "";
            m_Address = "";
            m_WageCoefficient = 0;
        }
        virtual void Input(stringstream& ss) { 
            string token;

            getline(ss, m_ID, ',');
            getline(ss, token, ','); 
            m_Department = stoi(token);
            getline(ss, m_Name, ',');
            getline(ss, m_Birthday, ',');
            getline(ss, m_Address, ',');
            getline(ss, token, ','); 
            m_WageCoefficient = stof(token);
        }

        virtual void Output(ostream& os) {
            os << m_ID << ", " << m_Name << ", " << m_Birthday << endl;
        } 

        virtual ~CNhanVien() {}
        

        virtual float getWageCoefficient(){
            return m_WageCoefficient;
        }
        virtual string getID(){
            return m_ID;
        }
        virtual string getName(){
            return m_Name;
        }
        virtual int getDepartment(){
            return m_Department;
        }
        virtual string getBirthday(){
            return m_Birthday;
        }
        virtual string getAddress(){
            return m_Address;
        }

};

class CManager : public CNhanVien{
    public:
        CManager(){
            m_ID = "";
            m_Department = 0;
            m_Name = "";
            m_Birthday = "";
            m_Address = "";
            m_WageCoefficient = 0;
        }
        CManager(string ID, int Department, string Name, string Birthday, string Address, float WageCoefficient){
            m_ID = ID;
            m_Department = Department;
            m_Name = Name;
            m_Birthday = Birthday;
            m_Address = Address;
            m_WageCoefficient = WageCoefficient;
        }
};


class CProgrammer : public CNhanVien{
    public:
        CProgrammer(){
            m_ID = "";
            m_Department = 0;
            m_Name = "";
            m_Birthday = "";
            m_Address = "";
            m_WageCoefficient = 0;
        }
        CProgrammer(string ID, int Department, string Name, string Birthday, string Address, float WageCoefficient){
            m_ID = ID;
            m_Department = Department;
            m_Name = Name;
            m_Birthday = Birthday;
            m_Address = Address;
            m_WageCoefficient = WageCoefficient;
        }
       

};


class CDesigner : public CNhanVien{
    public:
        CDesigner(){
            m_ID = "";
            m_Department = 0;
            m_Name = "";
            m_Birthday = "";
            m_Address = "";
            m_WageCoefficient = 0;
        }
        CDesigner(string ID, int Department, string Name, string Birthday, string Address, float WageCoefficient){
            m_ID = ID;
            m_Department = Department;
            m_Name = Name;
            m_Birthday = Birthday;
            m_Address = Address;
            m_WageCoefficient = WageCoefficient;
        }
        
};


class CTester : public CNhanVien{
    public:
        CTester(){
            m_ID = "";
            m_Department = 0;
            m_Name = "";
            m_Birthday = "";
            m_Address = "";
            m_WageCoefficient = 0;
        };
        CTester(string ID, int Department, string Name, string Birthday, string Address, float WageCoefficient){
            m_ID = ID;
            m_Department = Department;
            m_Name = Name;
            m_Birthday = Birthday;
            m_Address = Address;
            m_WageCoefficient = WageCoefficient;
        }
       
};

int countFile(string filename) {
    ifstream file(filename);
    int count = 0;
    string type;
    while (getline(file, type)) {
        count++;
    }
    return count ; // Chia đôi số dòng để có số lượng nhân viên
}

float calculateSalary(CNhanVien* nv, float basicSalary, ifstream& salaryFile) {
    float salary = basicSalary * nv->getWageCoefficient();
    string line;
    while (getline(salaryFile, line)) {
        stringstream ss(line);
        string id, token;
        getline(ss, id, ' ');
        if (id == nv->getID()) {
            if (dynamic_cast<CProgrammer*>(nv)) {
                getline(ss, token, ' ');
                salary += stof(token); // Thêm tiền overtime
            } else if (dynamic_cast<CDesigner*>(nv)) {
                getline(ss, token, ' ');
                salary += stof(token); // Thêm tiền bonus
            } else if (dynamic_cast<CTester*>(nv)) {
                getline(ss, token, ' ');
                salary += stoi(token) * 100000; // Thêm tiền thưởng lỗi
            }
            break;
        }
    }
    return salary;
}

void searchDepartment(vector<CNhanVien*>& list, int departmentToSearch) {
    ofstream outputFile("search.txt");
    if (!outputFile.is_open()) {
        cerr << "Không thể mở file SEARCH.TXT" << endl;
        return;
    }

    for (CNhanVien* nv : list) {
        if (nv->getDepartment() == departmentToSearch) {
            outputFile << nv->getID() << ", " << nv->getName() << ", "
                       << nv->getBirthday() << ", " << nv->getAddress() << endl;
        }
    }

    outputFile.close();
    cout << "Đã ghi kết quả vào file SEARCH.TXT" << endl;
}
int calculateAge(const string& birthday) {
    stringstream ss(birthday);
    int day, month, year;
    char slash;
    ss >> day >> slash >> month >> slash >> year;
    return 2024 - year; // Giả sử năm hiện tại là 2023
}

bool compareAge( CNhanVien* a, CNhanVien* b) {
    return calculateAge(a->getBirthday()) > calculateAge(b->getBirthday());
}
void sortAndWriteToFile(vector<CNhanVien*>& list) {
    ofstream outputFile("SORTYEAROLD.OUT");
    if (!outputFile.is_open()) {
        cerr << "Không thể mở file SORTYEAROLD.OUT" << endl;
        return;
    }

    // Sắp xếp danh sách nhân viên theo tuổi giảm dần
    sort(list.begin(), list.end(), compareAge);

    // Ghi danh sách nhân viên đã sắp xếp vào file
    for (size_t i = 0; i < list.size(); ++i) {
        outputFile << i + 1 << ". " << list[i]->getID() << " " << list[i]->getName() << " "
                   << calculateAge(list[i]->getBirthday()) << endl;
    }

    outputFile.close();
    cout << "Đã ghi kết quả vào file SORTYEAROLD.OUT" << endl;
}

int main(){
    vector<CNhanVien*> list;
    ifstream file("input.txt");
    ofstream fileout("output.txt");
    bool firstLine = true;
    while (!file.eof()) {
        CNhanVien* nv;
        string type;
        string line;

        getline(file, line); // Đọc toàn bộ dòng
        if (firstLine) {
            if (line.size() >= 3 && line[0] == '\xef' && line[1] == '\xbb' && line[2] == '\xbf') {
                line.erase(0, 3);
            }
            firstLine = false;
        }
        type = line[0];     
        

        stringstream ss(line); 

        if (type == "M") {
            nv = new CManager();
        } else if (type == "P") {
            nv = new CProgrammer();
        } else if (type == "D") {
            nv = new CDesigner();
        } else if (type == "T") {
            nv = new CTester();
        } else {
            continue; 
        }

        nv->Input(ss);
        list.push_back(nv); 
    }
    fileout << countFile("input.txt") - 1 << " Nhan vien\n";
    for (int i = 0; i < list.size(); i++) {
        fileout << i + 1 << ". ";
        list[i]->Output(fileout);
    }

    ifstream salaryFile("salary.txt");
    float basicSalary;
    salaryFile >> basicSalary;

    // Tính lương và tổng lương
    float totalSalary = 0;
    for (CNhanVien* nv : list) {
        float salary = calculateSalary(nv, basicSalary, salaryFile);
        totalSalary += salary;
        cout << nv->getName() << ": " << fixed << setprecision(0) << salary<< endl; // In tên và lương
    }
    salaryFile.close();
    cout << "Tổng lương: " << fixed << setprecision(0) << totalSalary << endl;
    
    
    int departmentToSearch;
    cout << "Nhập thông tin phòng ban: ";
    cin >> departmentToSearch;
    searchDepartment(list, departmentToSearch);

    sortAndWriteToFile(list);
    
    // Giải phóng bộ nhớ
    for (CNhanVien* nv : list) {
        delete nv;
    }
    
}