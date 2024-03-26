#include "utility.h"
#include <iostream>
#include <memory.h>
#include <cstring>
#include <stdlib.h>
using namespace std;

int memSize(int nItem, int szItem) {
    return headSize + nItem * szItem;
}

void* origin_addr(void* aData) {
    if (aData != NULL)
        return(char*)aData - headSize;
    return NULL;
}

void* data_addr(void* origin) {
    if (origin != NULL)
    {
        return (char*)origin + headSize;
    }
    return NULL;
}

void* sizeItemAddr(void* aData)
{
    if (aData != NULL)
        return ((char*)(aData) - sizeof(int));
    return NULL;
}
int arrSize(void* aData)
{
    if (aData != NULL)
        return *(int*)origin_addr(aData);
    return -1;//Sẽ trả về -1
}
void* arrInit(int sizeArr, int sizeItem)
{
    int size = memSize(sizeArr, sizeItem);
    void* aOrigin = malloc(size);//aData khởi tạo là origin
    if (aOrigin != NULL)
    {
        memset(aOrigin, 0, size);
        void* aData = data_addr(aOrigin);
        *(int*)sizeItemAddr(aData) = sizeItem;
        *(int*)origin_addr(aData) = sizeArr;
        return aData;
    }
    return NULL;
}
void* ArrResize(void* aData, int nItem)
{
    if (aData == NULL || nItem < 0)
        return NULL;
    void* aOrigin = origin_addr(aData);
    int sizeItem = *(int*)sizeItemAddr(aData);
    int sz = memSize(nItem, sizeItem);
    void* aNew = realloc(aOrigin, sz);
    if (aNew != NULL)
    {
        aOrigin = aNew;
        *(int*)aOrigin = nItem;
        return data_addr(aOrigin);
    }
    return NULL;
}
int soPhucArrPushback(void** aData, void* x)
{
    int nItem = *(int*)origin_addr(*aData);
    int sizeItem = *(int*)sizeItemAddr(*aData);
    void* aNew=ArrResize(*aData, nItem + 1);
    if (aNew != NULL)
    {
        memmove((char*)aNew + nItem * sizeItem, x, sizeItem);
        *aData = aNew;
        return 1;
    }
    return 0;
}
int InputSoPhuc(SOPHUC* x)
{
    cout << "Nhap vao phan nguyen: "; 
    cin >> x->real; 
    if (cin.fail())
    {
        cin.clear();
        return 0;
    }
    cout << "Nhap vao phan ao: "; 
    cin >> x->im;
        if (cin.fail())
        {
            cin.clear();
            return 0;
        }
    return 1;
}
SOPHUC* soPhucArrInput()
{
    void* ret = arrInit(0, sizeof(SOPHUC));
    SOPHUC x;
    while (InputSoPhuc(&x))
    {
        soPhucArrPushback(&ret, &x);
    }
    return (SOPHUC*)ret;
}
void* soPhucArrPopback(void** aData)
{
    if (*aData != NULL)
    {
        int nItem = arrSize(*aData);
        int sizeItem = *(int*)sizeItemAddr(*aData);
        if (nItem > 0)
        {
            nItem--;
            void* x=malloc(sizeItem);
            memmove(x, (char*)(*aData) + nItem * sizeItem, sizeItem);
            void* aNew=ArrResize(*aData, nItem);
            if (aNew != NULL)
                *aData = aNew;
            return x;
        }
    } 
    return NULL;
}
void outPutSoPhuc(SOPHUC x)
{
    {
        cout << x.real;
        if (x.im >= 0) cout << '+';
        cout << x.im << "i";
    }
}
void soPhucArrOut(SOPHUC* aData)
{
    int n = *(int*)(origin_addr(aData));
    for (int i = 0; i < n; i++)
    {
        outPutSoPhuc(aData[i]);
        cout << endl;
    }
}
void soPhucArrFree(SOPHUC* aData) {
    if (aData != NULL) {
        free((SOPHUC*)origin_addr((void*)aData));
    }
}