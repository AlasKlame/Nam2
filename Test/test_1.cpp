#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

int countNum(int n){
    int i = 0;
    while(n > 0){
        n /= 10;
        i++;
    }
    return i;
}

int solve(int n){
    int dem = countNum(n);
    int max = 0;
    int a=0;
    int sothaythen=n;
    for(int i = 0; i < dem; i++){
        int j = 1;
        
        while(j <=i+1){
            a = sothaythen - sothaythen%int(pow(10,j));
            j++;
        }
        a /=10;
        a+=n%int(pow(10,i));
        if(max<a)max=a;
    }
    return max;
}

int main(){
    int n;
    cin >>n;
    int max = solve(n);
    cout << max << endl;
    return 0;
}