#include<iostream>
#define MAX 10000
using namespace std;


int findMaxArray(int arr[], int n, int &count_assignment , int &count_comparison ) {
    count_assignment += 2;
    int count_max = -1;
    int count = 1;
    count_assignment += 1;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] < arr[i + 1]) {
            count_assignment += 1;
            count_comparison += 1;
            count++;
            if (i == n - 2) {
                count_comparison += 1;
                if (count > count_max) {
                    count_comparison += 1;
                    count_max = count;
                    count_assignment += 1;
                }
            }
        }
        else {
            count_comparison += 1;
            if (count > count_max) {
                count_comparison += 1;
                count_max = count;
                count = 1;
                count_assignment += 2;
            }
            else {
                count_comparison += 1;
                count = 1;
                count_assignment += 1;
            }
        }
        count_assignment += 1;
      
    }
    return count_max;
}

int findMaxArray_cubic(int arr[], int n, int& count_assignments, int& count_comparisons) {
  count_assignments += 1; // Khởi tạo count_max
  int count_max = 1;
  count_assignments += 1; // Khởi tạo i
  for (int i = 0; i < n; i++) {
    count_assignments += 1; // Khởi tạo j
    for (int j = i + 1; j < n; j++) {
      count_assignments += 1; // Khởi tạo current_count
      int current_count = 1;
      count_assignments += 1; // Khởi tạo k
      for (int k = j; k < n - 1; k++) {
        count_comparisons += 1; // So sánh arr[k] và arr[k+1]
        if (arr[k] < arr[k + 1]) {
          count_assignments += 1; // Tăng current_count
          current_count++;
        } else {
          break; // Thoát khỏi vòng lặp k nếu không tăng
        }
      }
      count_comparisons += 1; // So sánh current_count và count_max
      if (current_count > count_max) {
        count_assignments += 1; // Cập nhật count_max
        count_max = current_count;
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
        arr[i] = rand() % 10000;
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    int count_assignment = 0;
    int count_comparison = 0;
    int count_assignment_lessEfficient = 0;
    int count_comparison_lessEfficient = 0;
    cout << "Max array: " << findMaxArray(arr, n, count_assignment, count_comparison) << endl;
    cout << "Count assignment: " << count_assignment << endl;
    cout << "Count comparison: " << count_comparison << endl;
    cout << "Max array less efficient: " << findMaxArray_cubic(arr, n, count_assignment_lessEfficient, count_comparison_lessEfficient) << endl;
    cout << "Count assignment less efficient: " << count_assignment_lessEfficient << endl;
    cout << "Count comparison less efficient: " << count_comparison_lessEfficient << endl;
    return 0;
}




