#include <iostream>
using namespace std;

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int* ptr1 = &arr[0];  // Con trỏ đến phần tử đầu tiên
    int* ptr2 = &arr[2];  // Con trỏ đến phần tử thứ ba

    cout << "Địa chỉ của arr[0]: " << ptr1 << endl;
    cout << "Địa chỉ của arr[2]: " << ptr2 << endl;

    cout << "ptr2 - ptr1: " << (ptr2 - ptr1) << endl;
    cout << "*(ptr1 + 1): " << *(ptr1 + 1) << endl;

    return 0;
}
