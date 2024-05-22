#include<iostream>
#define MAX 100

using namespace std; 

void reverseCharArray(char a[MAX]){
    for (int i = 0; i < MAX / 2; i++) {
        char temp = a[i];
        a[i] = a[MAX - i - 1];
        a[MAX - i - 1] = temp;
    }
}

int checkSymmetricArray(char a[MAX]){
    for (int i = 0; i < MAX / 2; i++) {
        if (a[i] != a[MAX - i - 1]) {
            return 0;
        }
    }
    return 1;

}
int countOccurrencesChar(char a[MAX], char c){
    int count = 0;
    for (int i = 0; i < MAX; i++) {
        if (a[i] == c) {
            count++;
        }
    }
    return count;
}
int findMostFrequentChar(char a[MAX], char &chr){
    int max = 0;
    for (int i = 0; i < MAX; i++) {
        int count = 0;
        for (int j = 0; j < MAX; j++) {
            if (a[j] == a[i]) {
                count++;
            }
        }
        if (count > max) {
            max = count;
            chr = a[i];
        }
    }
    return max;
}
void insertCharAtPosition(char str[], char chr, int pos){
    for (int i = MAX - 1; i > pos; i--) {
        str[i] = str[i - 1];
    }
    str[pos] = chr;
}

void formatNumberWithCommas(char str[]){
    int len = 0;
    for (int i = 0; i < MAX; i++) {
        if (str[i] == '\0') {
            len = i;
            break;
        }
    }
    int count = 0;
    for (int i = len - 1; i >= 0; i--) {
        count++;
        if (count % 3 == 0 && i != 0) {
            insertCharAtPosition(str, ',', i);
        }
    }
}

