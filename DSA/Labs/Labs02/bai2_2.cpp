#include<iostream>
#define MAX 1000
using namespace std;


int findMaxArray(int arr[], int n, int &count_assignment , int &count_comparison ) {

    int count_max = -1;
    int count = 1;

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] < arr[i + 1]) {
            count++;
            if (i == n - 2) {
                if (count > count_max) {
                    count_max = count;
                }
            }
        }
        else {
            if (count > count_max) {
                count_max = count;
                count = 1;
            }
            else {
                count = 1;
            }
        }
      
    }
    return count_max;
}


int main() {
    int n, start = 0, end = 0;
    cin >> n;
    int arr[MAX];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 500;
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "Max array: " << findMaxArray(arr, n) << endl;
    return 0;
}




// #include <iostream>
// #include <vector>

// using namespace std;

// int main() {
//   int n;
//   cin >> n;
//   vector<int> A(n);
//   for (int i = 0; i < n; ++i) {
//     cin >> A[i];
//   }

//   int maxLength = 1; // Độ dài dãy con không giảm lớn nhất

//   // Vòng lặp ngoài: duyệt qua từng phần tử như điểm bắt đầu
//   for (int i = 0; i < n; ++i) {
//     int currentLength = 1; // Độ dài dãy con hiện tại

//     // Vòng lặp trong: kiểm tra các phần tử tiếp theo
//     for (int j = i + 1; j < n; ++j) {
//       if (A[j] >= A[j - 1]) {
//         currentLength++;
//       } else {
//         break; // Dãy con không giảm bị phá vỡ
//       }
//     }

//     // Cập nhật độ dài lớn nhất
//     maxLength = max(maxLength, currentLength);
//   }

//   cout << maxLength << endl;
//   return 0;
// }