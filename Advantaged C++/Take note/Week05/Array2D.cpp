#include<iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct SOPHUC {
    float real;
    float im;
};


void alloc2D(void***a, int m, int n, int szItem){
    if(m <= 0 || n <= 0 || szItem <= 0){
        return;
    }
    int szRow = n*szItem , sz1 = m * sizeof(void*), sz2 = m * szRow;
    void* buf = calloc(12 + sz1 + sz2, 1);
    if(buf == NULL){
        return;
    }
    int* bs = (int*)buf;
    bs[0] = m;
    bs[1] = n;
    bs[2] = szItem;
    buf = (char*)buf + 12;
    *a = (void**)buf;
    buf = (char*)buf + sz1;
    (*a)[0] = buf;
    for(int i = 1; i < m; i++){
        buf = (char*)buf + szRow;
        (*a)[i] = buf;
    }

}

int nRow(void** c) {
    int* bs = (int*)((char*)c - 12);
    return bs[0];
}

int nCol(void** d) {
    int* bs = (int*)((char*)d - 12);
    return bs[1];
}

void arr2D_Input(SOPHUC* a[]) {
    int m = nRow((void**)a), n = nCol((void**)a);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << "Nhap phan thuc: " << endl;
            cin >> a[i][j].real;
            cout << "Nhap phan ao: " << endl;
            cin >> a[i][j].im;
        }
    }
}

void arr2D_Output(SOPHUC* a[]) {
    int m = nRow((void**)a), n = nCol((void**)a);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << a[i][j].real << " + " << a[i][j].im << "i\t";
        }
        cout << endl;
    }
}

void free2D(void** a){
    if(a!= NULL){
        void* p = (char*)a - 12;
        free(p);
    }
}

void resize2D(void***a, int m, int n){
    if(*a == NULL || m <= 0 || n <= 0){
        return;
    }
    int* bs = (int*)((char*)(*a) - 12);
    int m_old = bs[0], n_old = bs[1], szItem_old = bs[2];
    void** anew;
    alloc2D(&anew, m, n, szItem_old);
    if(anew == NULL){
        return;
    }
    for(int i = 0; i < m_old && i < m; i++){
        for(int j = 0; j < n_old && j < n; j++){
            char* d = (char*)anew[i] + j * szItem_old;
            char* s = (char*)(*a)[i] + j * szItem_old;
            memmove(d,s,szItem_old);
        }
    }
    free2D(*a);
    *a = anew;
}



int main(){
    SOPHUC** a;
    int d, c;
    int m , n;
    cout << "Nhap kich thuoc mang (d x c) muon cap phat: ";
    cin >> d >> c;
    alloc2D((void***)&a, d, c, sizeof(SOPHUC));
    arr2D_Input(a); 
    arr2D_Output(a);
    cout << "Nhap kich thuoc mang muon thay doi kich thuoc (m x n): ";
    cin >> m >> n;
    resize2D((void***)&a, m, n);
    arr2D_Output(a);
    free2D((void**)a);
    return 0;
}