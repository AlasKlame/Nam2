#include <iostream>
#include<cstring>
void intToBinary(int num, char bitArray[]) {
    for (int i = 7; i >= 0; --i) {
        bitArray[i] = (num & 1) + '0';
        num >>= 1;
    }
}

int binaryToInt(char bitArray[]) {
    int result = 0;
    for (int i = 0; i < 8; ++i) {
        result = (result << 1) + (bitArray[i] - '0');
    }
    if (bitArray[0] == '1') {
        result -= (1 << 8);
    }
    return result;
}

void print(char arr[]){
    for(int i = 0; i < 8; i++){ 
        std::cout << arr[i];
    }
    std::cout << std::endl;
}

void add(char arrA[], char arrB[], char result[]) {
    int carry = 0;
    for (int i = 7; i >= 0; --i) {
        int sum = (arrA[i] - '0') + (arrB[i] - '0') + carry;
        result[i] = (sum % 2) + '0';
        carry = sum / 2;
    }
}

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

void multiply(char arrA[], char arrB[], char result[]) {
    int product = 0;
    for (int i = 0; i < 8; ++i) {
        if (arrB[7 - i] == '1') {
            product += (binaryToInt(arrA) << i);
        }
    }
    intToBinary(product, result);
}

void divide(char arrA[], char arrB[], char result[]) {
    memset(result, '0', 8);
    bool isDivisorZero = true;
    for (int i = 0; i < 8; i++) {
        if (arrB[i] == '1') {
            isDivisorZero = false;
            break;
        }
    }
    if (isDivisorZero) {
        std::cerr << "Error: Division by zero." << std::endl;
        return;
    }

    char current[9] = {}; 
    memset(current, '0', 8);

    for (int i = 0; i < 8; i++) {
        
        memmove(current, current + 1, 7);
        current[7] = arrA[i];

        
        bool canSubtract = true;
        for (int j = 0; j < 8; j++) {
            if (arrB[j] > current[j]) {
                canSubtract = false;
                break;
            } else if (arrB[j] < current[j]) {
                break;
            }
        }

       
        if (canSubtract) {
            for (int k = 7; k >= 0; k--) {
                if (arrB[k] == '1' && current[k] == '0') {
                    int borrowIndex = k - 1;
                    while (borrowIndex >= 0 && current[borrowIndex] != '1') {
                        current[borrowIndex] = '1'; 
                        borrowIndex--;
                    }
                    if (borrowIndex >= 0) current[borrowIndex] = '0'; 
                }
                current[k] = ((arrB[k] == '1' && current[k] == '1') || (arrB[k] == '0' && current[k] == '0')) ? '0' : '1';
            }
            result[i] = '1';
        }
    }
}

void modulus(char arrA[], char arrB[], char result[]) {
    char quotient[8];
    divide(arrA, arrB, quotient);
    multiply(quotient, arrB, result);
    subtract(arrA, result, result);
}



int main() {
    int A, B;
    std::cout << "Input A (Decimal): ";
    std::cin >> A;
    std::cout << "Input B (Decimal): ";
    std::cin >> B;

    char arrA[8], arrB[8], arrResult[8];

    intToBinary(A, arrA);
    intToBinary(B, arrB);

    std::cout << "A (Binary): ";
    print(arrA);
    std::cout << "B (Binary): ";
    print(arrB);

    add(arrA, arrB, arrResult);
    std::cout << "A + B (Binary): ";
    print(arrResult);
    std::cout << "A + B (Decimal): " << binaryToInt(arrResult) << std::endl;

    subtract(arrA, arrB, arrResult);
    std::cout << "A - B (Binary): ";
    print(arrResult);
    std::cout << "A - B (Decimal): " << binaryToInt(arrResult) << std::endl;

    multiply(arrA, arrB, arrResult);
    std::cout << "A * B (Binary): ";
    print(arrResult);
    std::cout << "A * B (Decimal): " << binaryToInt(arrResult) << std::endl;

    divide(arrA, arrB, arrResult);
    std::cout << "A / B (Binary): ";
    print(arrResult);
    std::cout << "A / B (Decimal): " << binaryToInt(arrResult) << std::endl;

    modulus(arrA, arrB, arrResult);
    std::cout << "A % B (Binary): ";
    print(arrResult);
    std::cout << "A % B (Decimal): " << binaryToInt(arrResult) << std::endl;

    return 0;
}
