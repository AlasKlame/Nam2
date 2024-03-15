#include <iostream>
#include <cstring>

void divide(char arrA[], char arrB[], char result[]) {
    // Initialize result array to all zeros
    memset(result, '0', 8);

    // Check if divisor is zero (all bits are 0)
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

    char current[9] = {}; // Current portion of the dividend being considered
    memset(current, '0', 8); // Initialize to all zeros

    for (int i = 0; i < 8; i++) {
        // Shift current to the left by 1 and append the next bit from the dividend
        memmove(current, current + 1, 7);
        current[7] = arrA[i];

        // Check if current >= arrB (divisor)
        bool canSubtract = true;
        for (int j = 0; j < 8; j++) {
            if (arrB[j] > current[j]) {
                canSubtract = false;
                break;
            } else if (arrB[j] < current[j]) {
                break;
            }
        }

        // Perform subtraction if possible
        if (canSubtract) {
            for (int k = 7; k >= 0; k--) {
                if (arrB[k] == '1' && current[k] == '0') {
                    // Borrow from the next left bit
                    int borrowIndex = k - 1;
                    while (borrowIndex >= 0 && current[borrowIndex] != '1') {
                        current[borrowIndex] = '1'; // Flip bits along the way
                        borrowIndex--;
                    }
                    if (borrowIndex >= 0) current[borrowIndex] = '0'; // Perform actual borrow
                }
                current[k] = ((arrB[k] == '1' && current[k] == '1') || (arrB[k] == '0' && current[k] == '0')) ? '0' : '1';
            }
            result[i] = '1'; // Indicate in result that subtraction was successful
        }
    }
}

int main() {
    char arrA[9] = "01011010"; // Example: 90
    char arrB[9] = "00000101"; // Example: 5
    char result[9] = {0};

    divide(arrA, arrB, result);

    std::cout << "Result (Binary): ";
    for (int i = 0; i < 8; i++) {
        std::cout << result[i];
    }
    std::cout << std::endl;

    return 0;
}
