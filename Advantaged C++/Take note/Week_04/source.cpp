#include<iostream>
#include<memory.h>

using namespace std;

static int headSize = sizeof(int);

int memSize(int nItem) {
    return headSize + nItem * sizeof(float);
}

void* origin_addr(void* aData){
    return(char*)aData - headSize;
}

float* data_addr(void* origin){
    return (float*)((char*)origin + headSize);
}

void set_nItem(void* aData, int nItem){
    *((int*)origin_addr(aData)) = nItem;
}
int get_nItem(float* aData){
    return *((int*)origin_addr(aData));
}

int floatArrSize(float* aData){
    if(aData != NULL){
        return get_nItem(aData);
    }
    return 0;
}

float* floatArrResize(float* aData, int nItem){
    int sz = memSize(nItem);
    float* anew = NULL;
    void *originAddr = NULL;
    if(aData != NULL){
        originAddr = origin_addr(aData);
    } 
    anew = (float*)realloc(originAddr, sz);
    if(anew != NULL){
        if(aData == NULL){
            memset(anew, 0, sz);
        }
        aData = data_addr(anew);
        set_nItem(aData, nItem);
    }
    return aData;
}


int floatArrPushback(float** aData, float x){
    int n = floatArrSize(*aData);
    float* anew = floatArrResize(*aData, n+1);
    if(anew != NULL){
        anew[n] = x;
        *aData = anew;
        return 1;
    }
    return 0;
}

float floatArrPopback(float** aData){
    int n = floatArrSize(*aData);
    float x = 0;
    if(*aData != NULL && n > 0){
        n--;
        x = (*aData)[n];
        float* anew = floatArrResize(*aData, n);
        if(anew != NULL){
            *aData = anew;
        }
    }
    return x;
}

void floatArrFree(float* aData){
    if(aData != NULL){
        free(origin_addr(aData));
    }
}

float* floatArrInput(){
    float* a = NULL, x = 0;
    while(cin >> x){
        floatArrPushback(&a, x);
    }
    cin.clear();
    return a;
}

void floatArrOutput(){
    float* a = floatArrInput();
    int n = floatArrSize(a);
    for(int i = 0; i < n; i++){
        std::cout << a[i] << " ";
    }
    std::cout << endl;
    floatArrFree(a);
}

void main(){
    std::cout << "Input complex item \n";
    float *B = floatArrInput();
    float x = floatArrPopback(&B);
    std::cout << "After pop: \n";
    floatArrOutput();
    std::cout << "\nPopped element: " << x << endl;
    
    floatArrFree(B);
    
}
