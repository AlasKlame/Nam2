    #include <iostream>
#include <vector>

using namespace std;

// Hàm merge để hợp nhất hai mảng đã sắp xếp
void merge(vector<int>& arr, int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;

  // Tạo hai mảng tạm thời
  vector<int> L(n1);
  vector<int> R(n2);

  // Sao chép dữ liệu vào mảng tạm thời
  for (int i = 0; i < n1; i++) {
    L[i] = arr[left + i];
  }
  for (int j = 0; j < n2; j++) {
    R[j] = arr[mid + 1 + j];
  }

  // Hợp nhất hai mảng tạm thời
  int i = 0;
  int j = 0;
  int k = left;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  // Sao chép phần còn lại của mảng L
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  // Sao chép phần còn lại của mảng R
  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

// Hàm Merge Sort
void mergeSort(vector<int>& arr, int left, int right) {
  if (left < right) {
    // Tìm điểm giữa của mảng
    int mid = left + (right - left) / 2;

    // Sắp xếp hai nửa mảng
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // Hợp nhất hai nửa mảng đã sắp xếp
    merge(arr, left, mid, right);
  }
}

int main() {
  vector<int> arr = {5, 2, 4, 6, 1, 3};
  int n = arr.size();

  // Sắp xếp mảng sử dụng Merge Sort
  mergeSort(arr, 0, n - 1);

  // In mảng đã sắp xếp
  cout << "Mảng đã sắp xếp: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}