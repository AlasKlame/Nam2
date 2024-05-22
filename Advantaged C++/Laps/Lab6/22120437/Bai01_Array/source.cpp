#include <iostream>
using namespace std;

#define MAX_SIZE 100

struct Stack {
    int top;
    int data[MAX_SIZE];
};

// 1. Khởi tạo stack rỗng
void initStack(Stack& stack) {
    stack.top = -1; 
}

// 2. Kiểm tra stack có rỗng không
bool isEmpty(Stack stack) {
    return stack.top == -1;
}

// 3. Kiểm tra stack đã đầy chưa
bool isFull(Stack stack) {
    return stack.top == MAX_SIZE - 1;
}

// 4. Thêm một phần tử vào đầu stack (push)
void push(Stack& stack, int value) {
    if (isFull(stack)) {
        cout << "Stack đã đầy." << endl;
        return;
    }
    stack.top++;
    stack.data[stack.top] = value;
}

// 5. Lấy giá trị của phần tử đầu stack (peek)
int peek(Stack stack) {
    if (isEmpty(stack)) {
        cout << "Stack rỗng." << endl;
        return -1;
    }
    return stack.data[stack.top];
}

// 6. Lấy phần tử đầu ra khỏi stack (pop)
int pop(Stack& stack) {
    if (isEmpty(stack)) {
        cout << "Stack rỗng." << endl;
        return -1;
    }
    int value = stack.data[stack.top];
    stack.top--;
    return value;
}

// 7. Làm rỗng stack
void clearStack(Stack& stack) {
    stack.top = -1;
}

int main() {
    Stack myStack;
    initStack(myStack);

    push(myStack, 10);
    push(myStack, 20);
    push(myStack, 30);

    cout << "Peek: " << peek(myStack) << endl; // Peek: 30

    cout << "Pop: " << pop(myStack) << endl; // Pop: 30
    cout << "Peek: " << peek(myStack) << endl; // Peek: 20

    clearStack(myStack);
    cout << "Is Empty: " << isEmpty(myStack) << endl; // Is Empty: 1 (true)

    return 0;
}