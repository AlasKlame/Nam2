#include <iostream>

int main() {
    std::cout << "Bảng mã ASCII:" << std::endl;
    std::cout << "----------------------" << std::endl;
    std::cout << "Ký tự | Mã ASCII" << std::endl;
    std::cout << "----------------------" << std::endl;

    // In ký tự và mã ASCII tương ứng
    for (int i = 0; i < 26; ++i) {
        char uppercase = 'A' + i;
        char lowercase = 'a' + i;
        std::cout << uppercase << "     | " << static_cast<int>(uppercase) << std::endl;
        std::cout << lowercase << "     | " << static_cast<int>(lowercase) << std::endl;
    }

    return 0;
}
