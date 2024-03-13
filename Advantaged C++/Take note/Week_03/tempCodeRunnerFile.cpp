#include<iostream>

using namespace std;


char* insertCharacter (char* s,char c, int p){
    int n= 0;
    while(s[n] != '\0'){
        n++;
    }

    char* q = new char[n+2];
    for(int i = 0; i < p; i++){
        q[i] = s[i];
    }

    q[p] = c;
    for(int i = p; i < n; i++){
        q[i] = s[i-1];
    }
    q[n+1] = '\0';
    return q;
}


char* insertString(char* s, char* c, int p){
    int n = 0;
    while(s[n] != '\0'){
        n++;
    }
    int m = 0;
    while(c[m] != '\0'){
        m++;
    }
    
    char* q = new char[n + m + 2];
    for(int i = 0; i < p; i++){
        q[i] = s[i];
    }

    for(int i = p; i < p + m; i++){
        q[i] = c[i-p];
    }
    q[n+1] = '\0';
    return q;

}

int main(){
    char s[] = "Hello";
    char c[] = "'toilakien";
    int p = 3;
    //char* q = insertCharacter(s,c,p);
    char* r = insertString(s,c,p);
    cout << r << endl;
    return 0;
}