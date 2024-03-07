#include<iostream>


using namespace std;


class Student{
    private:
        string name;
        float diem_toan;
        float diem_van;
    public:
        Student(){

        }
        Student(string name, float diem_toan, float diem_){
            this->name = name;
            this->diem_toan = diem_toan;
            this->diem_van = diem_van;
        }

        void input(){
            getline(cin, name);
            cin >> diem_toan;
            cin >> diem_van;
        }

        void print(){
            cout << name << endl;
            cout << diem_toan << endl;
            cout << diem_van << endl;
        }
        string getName(){
            return name;
        }
        float getDiem_toan(){
            return diem_toan;
        }
        float getDiem_van(){
            return diem_van;
        }

        float diemTB(){
            return (diem_toan + diem_van)/2;
        }
        
};


int main(){
    Student a;
    a.input();
    a.print();
    float b = a.diemTB();
    cout << b << endl;
    
    return 0;

}
