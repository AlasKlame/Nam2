#include <iostream>
using namespace std;

#define MAX_SIZE 100

int items[MAX_SIZE];
int front = -1;
int rear = -1;

bool isEmpty() {
    return (front == -1 && rear == -1);
}

bool isFull() {
    return ((rear + 1) % MAX_SIZE == front); 
}

void enqueue(int data) {
    if (isFull()) {
        cout << "Queue is full!" << endl;
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX_SIZE;
    }
    items[rear] = data;
}

int peek() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    return items[front];
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return;
    }
    if (front == rear) { 
        front = rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }
}

void clear() {
    front = rear = -1;
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