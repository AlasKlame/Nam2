#include<iostream>

using namespace std;

int main(){
    int *p_1 = nullptr;
    int *p_2 = p_1;
    if(p_2 == nullptr){
        cout << "riel";
    }
    else{
        cout <<"Not riel" << endl;
        cout << *p_1 << endl;
    }
    return 0;
}