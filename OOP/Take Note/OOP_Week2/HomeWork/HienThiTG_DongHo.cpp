#include<iostream>

using namespace std;


class Time{
    private:
        int gio;
        int phut;
        int giay;
    public:
        Time(){

        }

        int getGio(){
            return gio;
        }
        int getPhut(){
            return phut;
        }
        int getGiay(){
            return giay;
        }

        void input(){
            cin >> gio >> phut >> giay;
        }

        void output(){
            cout << gio << " " << phut << " " << giay;
        }
};


class Oclock{
    private:
        Time A;
    public:
        Oclock(){};
        void nhap(){
            A.input();
        }
        void xuat(){
            A.output();
        }
};


int main(){
    Oclock a;
    a.nhap();
    a.xuat();
    return 0;
}