#include<iostream>
#include<memory.h>
#include "utility.h"
using namespace std;
void main() {
    cout << "Input complex item \n";
    SOPHUC* B = soPhucArrInput();
    SOPHUC *x = (SOPHUC*)soPhucArrPopback((void**)&B);
    cout << "After pop: \n";
    soPhucArrOut(B);
    cout << "\nPopped element: ";
    if(x)
    outPutSoPhuc(*x);
    soPhucArrFree(B);
    if(x)
    free(x);
}
