#include<iostream>
#include<string>

using namespace std;


int main(){
    string s;

    cout << "Nhap chuoi: ";
    getline(cin, s);
    string a;
    
    for(int i = s.length(); i > 0; i--){
        if(s[i] == ' '){
            a = s.substr(i+1, s.length());
            break;
        }
    }
    cout << "Chuoi vua nhap: " << s << endl;
    cout << "Chuoi moi: " << a << endl;
}