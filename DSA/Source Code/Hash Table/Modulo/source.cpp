#include <iostream>

// Hàm tính (base^exponent) % mod bằng phương pháp lũy thừa nhân đôi
long long powMod(long long base, long long exponent, long long mod) {
    long long result = 1;
    base = base % mod; // Nếu base >= mod

    while (exponent > 0) {
        // Nếu exponent là số lẻ, nhân base với result
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }
        // exponent là số chẵn, chia đôi exponent
        exponent = exponent >> 1;
        // Nhân base với chính nó
        base = (base * base) % mod;
    }

    return result;
}

int main() {
    long long base, exponent, mod;
    std::cout << "Nhap base: ";
    std::cin >> base;
    std::cout << "Nhap exponent: ";
    std::cin >> exponent;
    std::cout << "Nhap mod: ";
    std::cin >> mod;

    std::cout << "Ket qua: " << powMod(base, exponent, mod) << std::endl;

    return 0;
}