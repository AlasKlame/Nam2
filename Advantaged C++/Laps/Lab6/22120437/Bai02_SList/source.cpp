#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* front = nullptr;
Node* rear = nullptr;

bool isEmpty() {
    return (front == nullptr);
}

void enqueue(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        newNode->prev = rear;
        rear = newNode;
    }
}

int peek() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    return front->data;
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return;
    }
    Node* temp = front;
    front = front->next;

    if (front != nullptr) { 
        front->prev = nullptr;
    } else {
        rear = nullptr; // Nếu queue rỗng sau khi dequeue
    }

    delete temp;
}

void clear() {
    while (!isEmpty()) {
        dequeue();
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    cout << "Peek: " << peek() << endl; 

    dequeue();

    cout << "Peek: " << peek() << endl;

    clear();

    return 0;
}