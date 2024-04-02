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

int checkNgto(int a, int b){
    int maxValue = max(a,b);
    int count = 0; int count_1 = 0;
        for(int i = 0; i < maxValue; i++){
            
            if(a % i == 0 && b % i != 0){
                count++;
            }
            if(i == a) count--;
            if(a % i != 0 && b % i ==0){
                count_1++;
            }
            if(i == b){
                count_1--;
            }
        }
    return abs(count - count_1);
}

int main(){
    int a, b;
    cin >>a >> b;
    int max = checkNgto(a,b);
    cout << max << endl;
    return 0;
}