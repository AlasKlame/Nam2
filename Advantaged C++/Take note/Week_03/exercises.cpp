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
    for(int i = p+1; i <= n; i++){
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

    for(int i = p + m; i < m + n; i++){
        q[i] = s[i-m];
    }

    q[n+m] = '\0';
    return q;

}

int countWord(char* s, char delim){
    int count = 1;
    int i = 0;
    while(s[i] != '\0'){
        if(s[i] == delim){
            count++;
        }
        i++;
        if(s[i-1] == delim){
            i--;
        }
    }
    return count;
}


int main() {
    char s[] = "Hello world   ";
    char c[] = "abc";
    char c1 = 'A';
    int p = 1;
    char* des1 = insertCharacter(s, c1, p);
    printf("%s\n", des1);
    char* des2 = insertString(s, c, p);
    printf("%s\n", des2);
    printf("So luong phan tu cua %s la %d\n", des2, countWord(s, ' '));
    delete[]des1; delete[]des2;
    return 0;
}