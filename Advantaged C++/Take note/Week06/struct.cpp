#include <iostream>
#include <iomanip>
#pragma pack(1)
using namespace std;


struct SOPHUC {
    float real;
    float im;
};

struct aStruct {
    int m, n, sizeItem;
    void* Data[1];
};

static int headSize = sizeof(int) + sizeof(int) + sizeof(int);


int nRow(void** aData) {
    aStruct* as = (aStruct*)((char*)aData - headSize);
    if (as != NULL) return as->m;
    return 0;
}


int nCol(void** aData) {
    aStruct* as = (aStruct*)((char*)aData - headSize);
    if (as != NULL) return as->n;
    return 0;
}


void Free2D(void** aData) {
    if (aData != NULL) {
        void* p = (char*)aData - headSize;
        free(p);
    }
}

void alloc2D(void*** a, int m, int n, int sz) {
    if (m <= 0 || n <= 0 || sz <= 0) return;
    int szRow = n * sz;
    int sz1 = m * sizeof(void*);
    int sz2 = m * szRow;
    void* buf = calloc(headSize + sz1 + sz2, 1);
    if (buf == NULL) return;
    aStruct* as = (aStruct*)buf;
    as->m = m; as->n = n; as->sizeItem = sz;
    buf = (char*)buf + headSize + sz1;
    as->Data[0] = buf;
    for (int i = 1; i < m; i++) {
        buf = (char*)buf + szRow;
        as->Data[i] = buf;
    }
    *a = as->Data;
}

void arr2D_Output(SOPHUC* a[]) {
    int m = nRow((void**)a), n = nCol((void**)a);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout <<setw(7)<< a[i][j].real << " + " << a[i][j].im << "i\t";
        }
        cout << endl;
    }
}
void arr2D_Input(SOPHUC* a[]) {
    int m = nRow((void**)a), n = nCol((void**)a);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Nhap phan thuc: " << endl;
            cin >> a[i][j].real;
            cout << "Nhap phan ao: " << endl;
            cin >> a[i][j].im;
        }
    }
}

int main() {
    SOPHUC** A;
    int row, col;
    cout << "Nhap hang: ";
    cin >> row;
    cout << "Nhap cot: ";
    cin >> col;
    alloc2D((void***)&A, row, col, sizeof(SOPHUC));
    arr2D_Input(A);
    arr2D_Output(A);
    Free2D((void**)A);
    return 0;
}