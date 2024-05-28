#include <iostream>
#include <vector>

using namespace std;

// Hàm tìm kiếm nhị phân
int binarySearch(vector<int>& arr, int target) {
  int left = 0;
  int right = arr.size() - 1;

  // Duyệt qua mảng cho đến khi left lớn hơn right
  while (left <= right) {
    // Tìm vị trí giữa của mảng
    int mid = left + (right - left) / 2;

    // Nếu phần tử tại vị trí giữa bằng target
    if (arr[mid] == target) {
      return mid; // Trả về vị trí của target
    }
    // Nếu phần tử tại vị trí giữa nhỏ hơn target
    else if (arr[mid] < target) {
      left = mid + 1; // Tiếp tục tìm kiếm ở nửa bên phải
    }
    // Nếu phần tử tại vị trí giữa lớn hơn target
    else {
      right = mid - 1; // Tiếp tục tìm kiếm ở nửa bên trái
    }
  }

  // Không tìm thấy target
  return -1;
}

int main() {
  vector<int> arr = {2, 3, 4, 10, 40};
  int target = 10;

  // Tìm kiếm phần tử sử dụng Binary Search
  int index = binarySearch(arr, target);

  // In kết quả
  if (index != -1) {
    cout << "Phần tử " << target << " được tìm thấy tại vị trí: " << index << endl;
  } else {
    cout << "Phần tử " << target << " không được tìm thấy trong mảng." << endl;
  }

  return 0;
}