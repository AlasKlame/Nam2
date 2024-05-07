#include<iostream>

using namespace std;


int recursiveSquareSum(int n, int& count_assignments, int& count_comparisons) {
    count_comparisons++;
    if (n < 1) {
        return 0;
    }
    count_assignments += 2; 
    int temp = n * n;
    int result = temp + recursiveSquareSum(n - 1, count_assignments, count_comparisons);
    return result;
}

int recursiveSquareNums(int n){
    if(n < 1){
        return 0;
    }
    return n * n + recursiveSquareNums(n - 1);
}

int main(){
    int count_assignments = 0;
    int count_comparisons = 0;
    int n;
    cin >> n;
    cout << recursiveSquareSum(n, count_assignments, count_comparisons) << endl;
    cout << "Square Sum:" << recursiveSquareNums(n) << endl;
    cout << "Number of assignments: " << count_assignments << endl;
    cout << "Number of comparisons: " << count_comparisons << endl;
    return 0;
}
