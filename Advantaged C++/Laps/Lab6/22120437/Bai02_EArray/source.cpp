#include <iostream>
using namespace std;

#define MAX_SIZE 100 

class Queue {
private:
    int front;
    int rear;
    int items[MAX_SIZE];

public:
    Queue() {
        front = -1;
        rear = -1;
    }

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
            return -1; // Hoặc bạn có thể throw exception 
        }
        return items[front];
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        if (front == rear) { // Chỉ còn 1 phần tử
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
    }

    void clear() {
        front = rear = -1;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Peek: " << q.peek() << endl; 

    q.dequeue();

    cout << "Peek: " << q.peek() << endl;

    q.clear();

    return 0;
}