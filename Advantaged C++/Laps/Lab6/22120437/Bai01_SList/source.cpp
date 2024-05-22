#include <iostream>
using namespace std;

// Cấu trúc Node cho danh sách liên kết
struct Node {
    int data;
    Node* next;
};

// Cấu trúc Stack
struct Stack {
    Node* top; 
};

// 1. Khởi tạo stack rỗng
void initStack(Stack& stack) {
    stack.top = nullptr; 
}

// 2. Kiểm tra stack có rỗng không
bool isEmpty(Stack stack) {
    return stack.top == nullptr;
}

// 4. Thêm một phần tử vào đầu stack (push)
void push(Stack& stack, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = stack.top; // Node mới trỏ đến node cũ
    stack.top = newNode; // Cập nhật top
}

// 5. Lấy giá trị của phần tử đầu stack (peek)
int peek(Stack stack) {
    if (isEmpty(stack)) {
        cout << "Stack rỗng." << endl;
        return -1;
    }
    return stack.top->data;
}

// 6. Lấy phần tử đầu ra khỏi stack (pop)
int pop(Stack& stack) {
    if (isEmpty(stack)) {
        cout << "Stack rỗng." << endl;
        return -1;
    }
    Node* temp = stack.top;
    int value = temp->data;
    stack.top = stack.top->next; // Cập nhật top
    delete temp; // Giải phóng bộ nhớ
    return value;
}

// 7. Làm rỗng stack
void clearStack(Stack& stack) {
    while (!isEmpty(stack)) {
        pop(stack);
    }
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