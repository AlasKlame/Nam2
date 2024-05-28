#include <iostream>
#include <vector>

using namespace std;

// Hàm hoán đổi hai phần tử trong mảng
void swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

// Hàm phân vùng (partition)
int partition(vector<int>& arr, int low, int high) {
  // Chọn phần tử cuối cùng là phần tử trục
  int pivot = arr[high];
  int i = (low - 1);

  // Duyệt qua các phần tử từ low đến high-1
  for (int j = low; j <= high - 1; j++) {
    // Nếu phần tử hiện tại nhỏ hơn hoặc bằng phần tử trục
    if (arr[j] <= pivot) {
      // Tăng i và hoán đổi phần tử hiện tại với phần tử tại i + 1
      i++;
      swap(arr[i], arr[j]);
    }
  }

  // Hoán đổi phần tử trục với phần tử tại i + 1
  swap(arr[i + 1], arr[high]);

  // Trả về vị trí của phần tử trục sau khi phân vùng
  return (i + 1);
}

// Hàm Quick Sort
void quickSort(vector<int>& arr, int low, int high) {
  if (low < high) {
    // Phân vùng mảng, trả về vị trí của phần tử trục
    int pi = partition(arr, low, high);

    // Sắp xếp đệ quy hai nửa mảng
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

int main() {
  vector<int> arr = {5, 2, 4, 6, 1, 3};
  int n = arr.size();

  // Sắp xếp mảng sử dụng Quick Sort
  quickSort(arr, 0, n - 1);

  // In mảng đã sắp xếp
  cout << "Mảng đã sắp xếp: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}