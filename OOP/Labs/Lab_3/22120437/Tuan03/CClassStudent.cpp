#include<iostream>


using namespace std;



class CStudent{
    private:
        string m_Name;
        string m_Code;
        float m_Math;
        float m_Literature;
    public:
        CStudent(){};
        CStudent(string name, string code, float math, float literature){
            m_Name = name;
            m_Code = code;
            m_Math = math;
            m_Literature = literature;
        }
        long getCode(){
            long code = stoi(m_Code);
            return code; 
        }
        float getAverage(){
            return (m_Math + m_Literature) / 2;
        }
        void setRank(string rank){
            cout << "Rank: " << rank << endl;
        }
       
        friend istream& operator>>(istream &is, CStudent &student){
            cout << "Enter name: ";
            is >> student.m_Name;
            cout << "Enter code: ";
            is >> student.m_Code;
            cout << "Enter math score: ";
            is >> student.m_Math;
            cout << "Enter literature score: ";
            is >> student.m_Literature;
            return is;
        }
        friend ostream& operator<<(ostream &os, CStudent &student){
            os << "Name: " << student.m_Name << endl;
            os << "Code: " << student.m_Code << endl;
            os << "Math score: " << student.m_Math << endl;
            os << "Literature score: " << student.m_Literature << endl;
            return os;
        }
        float averageGreade(){
            return (m_Math + m_Literature) / 2;
        }
        bool operator>(CStudent &student){
            return this->averageGreade() > student.averageGreade();
        }
        bool operator<(CStudent &student){
            return this->averageGreade() < student.averageGreade();
        }
        bool operator>=(CStudent &student){
            return this->averageGreade() >= student.averageGreade();
        }
        bool operator<=(CStudent &student){
            return this->averageGreade() <= student.averageGreade();
        }
        bool operator==(CStudent &student){
            return this->averageGreade() == student.averageGreade();
        }
        
};


class CClassStudent{
    private:
        CStudent *m_Students;
        int m_Amount;
    public:
        CClassStudent(){
            m_Amount = 0;
            m_Students = new CStudent[m_Amount];
        }
        void input(){
            cout << "Enter amount of students: ";
            cin >> m_Amount;
            m_Students = new CStudent[m_Amount];
            for(int i = 0; i < m_Amount; i++){
                cin >> m_Students[i];
            }
        }
        void output(){
            for(int i = 0; i < m_Amount; i++){
                cout << m_Students[i];
            }
            cout << endl;
        }
        int getAmount(){
            return m_Amount;
        }
        
        CStudent Max(){
            CStudent max = m_Students[0];
            int index = 0;
            for(int i = 1; i < m_Amount; i++){
                if(m_Students[i] > max){
                    max = m_Students[i];
                    index = i;
                }
            }
            return m_Students[index];
        }
        CStudent Min(){
            CStudent min = m_Students[0];
            int index = 0;
            for(int i = 1; i < m_Amount; i++){
                if(m_Students[i] < min){
                    min = m_Students[i];
                    index = i;
                }
            }
            return m_Students[index];
        }
        
        void AscendingFromAverage(){
            for(int i = 0; i < m_Amount - 1; i++){
                for(int j = i + 1; j < m_Amount; j++){
                    if(m_Students[i].averageGreade() > m_Students[j].averageGreade()){
                        CStudent temp = m_Students[i];
                        m_Students[i] = m_Students[j];
                        m_Students[j] = temp;
                    }
                }
            }
        }
        
        void DescendingFromAverage(){
            for(int i = 0; i < m_Amount - 1; i++){
                for(int j = i + 1; j < m_Amount; j++){
                    if(m_Students[i].averageGreade() < m_Students[j].averageGreade()){
                        CStudent temp = m_Students[i];
                        m_Students[i] = m_Students[j];
                        m_Students[j] = temp;
                    }
                }
            }
        }

        void DeleteStudent(long code){
            int index = -1;
            for(int i = 0; i < m_Amount; i++){
                if(m_Students[i].getCode() == code){
                    index = i;
                    break;
                }
            }
            if(index == -1){
                cout << "Student not found" << endl;
            }else{
                for(int i = index; i < m_Amount - 1; i++){
                    m_Students[i] = m_Students[i + 1];
                }
                m_Amount--;
            }
        }

        void  FindStudent(long code){
            int index = -1;
            for(int i = 0; i < m_Amount; i++){
                if(m_Students[i].getCode() == code){
                    index = i;
                    break;
                }
            }
            if(index == -1){
                cout << "Student not found" << endl;
            }else{
                cout << m_Students[index];
            }
        }
        
        void rank(){
            for(int i = 0; i < m_Amount; i++){
                if(m_Students[i].getAverage() >= 9){
                    m_Students[i].setRank("Xuat sac");
                }else if(m_Students[i].getAverage() >= 8){
                    m_Students[i].setRank("Gioi");
                }else if(m_Students[i].getAverage() >= 6.5){
                    m_Students[i].setRank("Kha");
                }
                else if (m_Students[i].getAverage() >= 3.0)
                {
                    m_Students[i].setRank("Yeu");
                }
                else
                {
                    m_Students[i].setRank("Kem");
                }
                cout << endl;
            }
        }
};


int main(){
    CClassStudent classStudent;
    classStudent.input();
    classStudent.output();
    
    classStudent.rank();
    cout << endl;
    classStudent.AscendingFromAverage();
    classStudent.output();
    classStudent.DescendingFromAverage();
    classStudent.output();
    long code;
    cout << "Enter student code to find: ";
    cin >> code;
    classStudent.FindStudent(code);
    cout << endl;
    cout << "Enter student code to delete: ";
    cin >> code;
    classStudent.DeleteStudent(code);
    classStudent.output();
    return 0;
}