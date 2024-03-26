#pragma once
struct SOPHUC {
    int real, im;
};
const int headSize = sizeof(int) + sizeof(int);
void* arrInit(int sizeArr, int sizeItem);
void* origin_addr(void* aData);
int memSize(int nItem, int szItem);
void* data_addr(void* origin);
void* sizeItemAddr(void* aData);
int arrSize(void* aData);
void* ArrResize(void* aData, int nItem);
int soPhucArrPushback(void* aData, void* x);
int InputSoPhuc(SOPHUC* );
SOPHUC* soPhucArrInput();
void* soPhucArrPopback(void**);
void outPutSoPhuc(SOPHUC x);
void soPhucArrOut(SOPHUC* aData);
void soPhucArrFree(SOPHUC*);