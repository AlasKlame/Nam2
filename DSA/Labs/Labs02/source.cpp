#include<iostream>

using namespace std;


int sumHalf(int n, int& count_assignments, int& count_comparisons){
    count_assignments = 0;
    count_comparisons = 0;
    int a = 0; count_assignments++;
    int i = n; count_assignments++;
    count_comparisons++;
    while(i > 0){
        a = a + i;count_assignments++;
        i = i / 2;count_assignments++;  
        count_comparisons++;
    }
    return a;
}

int main(){
    int n, count_assignments = 0, count_comparisons = 0;
    cout << "Enter n: ";
    cin >> n;
    cout << "Sum of half: " << sumHalf(n, count_assignments, count_comparisons) << endl;
    cout << "Number of assignments: " << count_assignments << endl;
    cout << "Number of comparisons: " << count_comparisons << endl;
    return 0;
}