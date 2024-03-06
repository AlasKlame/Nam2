#include<iostream>

using namespace std;

class phanso{
private:
    int tu, mau;
public:
    phanso();
    phanso(int);
    phanso(int,int);
    
};

phanso::phanso(){
    tu = 0; mau = 1;
    cout << tu << "/"  << endl;
}

phanso::phanso(int t){
    tu = t; mau = 1;
    cout << tu << "/" << mau<< endl;
}

phanso::phanso(int t, int m){
    if(m < 0){
        t = -t ; m = -m;
    }

    if(m==0) m = 1;
    tu = t; mau = m;
    cout << tu << "/" << mau <<endl;
}

int main(){
    phanso a(2,3);
    phanso b(3);
    phanso c;
    c = 7;
    cout << endl;
    
}

