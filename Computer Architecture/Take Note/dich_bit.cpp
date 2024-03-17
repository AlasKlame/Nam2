#include <iostream>

// Hàm chuyển số nguyên sang dãy bit
void intToBinary(int num, char bitArray[]) {
    for (int i = 7; i >= 0; --i) {
        bitArray[i] = (num & 1) + '0';
        num >>= 1;
    }
}

// Hàm chuyển dãy bit sang số nguyên
int binaryToInt(char bitArray[]) {
    int result = 0;
    for (int i = 0; i < 8; ++i) {
        result = (result << 1) + (bitArray[i] - '0');
    }
    return result;
}

// Hàm đảo dấu của dãy bit
void flipBinary(char bitArray[]) {
    for (int i = 0; i < 8; ++i) {
        bitArray[i] = (bitArray[i] == '0') ? '1' : '0';
    }
}

// Hàm trừ hai dãy bit
void subtract(char arrA[], char arrB[], char result[]) {
    int borrow = 0;
    for (int i = 7; i >= 0; --i) {
        int diff = (arrA[i] - '0') - (arrB[i] - '0') - borrow;
        if (diff < 0) {
            diff += 2;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result[i] = diff + '0';
    }
}

int main() {
    int A, B;
    std::cout << "Input A (Decimal): ";
    std::cin >> A;
    std::cout << "Input B (Decimal): ";
    std::cin >> B;

    char arrA[8], arrB[8], arrResult[8];

    // Chuyển A và B sang dãy bit
    intToBinary(A, arrA);
    intToBinary(B, arrB);

    // In ra dãy bit của A và B
    std::cout << "A (Binary): ";
    for (int i = 0; i < 8; ++i) {
        std::cout << arrA[i];
    }
    std::cout << std::endl;

    std::cout << "B (Binary): ";
    for (int i = 0; i < 8; ++i) {
        std::cout << arrB[i];
    }
    std::cout << std::endl;

    // Thực hiện phép trừ và in ra kết quả
    subtract(arrA, arrB, arrResult);
    std::cout << "A - B (Binary): ";
    for (int i = 0; i < 8; ++i) {
        std::cout << arrResult[i];
    }
    std::cout << std::endl;

    // Nếu kết quả là số âm (bit cao nhất bằng 1), đảo dấu kết quả
    if (arrResult[0] == '1') {
        flipBinary(arrResult);
        // In ra kết quả dưới dạng số âm
        std::cout << "A - B (Decimal): -" << binaryToInt(arrResult) << std::endl;
    } else {
        // In ra kết quả dưới dạng số dương
        std::cout << "A - B (Decimal): " << binaryToInt(arrResult) << std::endl;
    }

    return 0;
}
