#include <iostream>

using namespace std;

class Queue {
private:
    int size;
    int front;
    int rear;
    int *arr;

public:
    Queue(int size) {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    ~Queue() {
        delete[] arr;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (front == 0 && rear == size - 1) || (front == rear + 1);
    }
    int getSize() {
        return size;
    }
    int getFront() {
        return front;
    }
    int getRear() {
        return rear;
    }
    void Enqueue(int element) {
        if (isFull()) {
            cout << "Queue da day" << endl;
            return;
        }
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % size;
        arr[rear] = element;
    }

    int Dequeue() {
        if (isEmpty()) {
            cout << "Queue rong!" << endl;
            return -1;
        }
        int data = arr[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
        return data;
    }
    
    int updateSize() {
        if (front == -1) {
            return 0;
        }
        if (front <= rear) {
            return rear - front + 1;
        }
        return size - front + rear + 1;
    }
    void deleteElement(int index) {
        if (isEmpty()) {
            cout << "Queue rong!" << endl;
            return;
        }
        if (index < 0 || index >= size) {
            cout << "Vi tri khong hop le" << endl;
            return;
        }
        if (front <= rear) {
            for (int i = index; i < rear; i++) {
                arr[i] = arr[i + 1];
            }
            rear--;
        } else {
            for (int i = index; i < size - 1; i++) {
                arr[i] = arr[i + 1];
            }
            for (int i = 0; i < rear; i++) {
                arr[i] = arr[i + 1];
            }
            rear--;
        }
    }
    void print() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        int i = front;
        if (front <= rear) {
            while (i <= rear) {
                cout << arr[i] << " ";
                i++;
            }
        } else {
            while (i < size) {
                cout << arr[i] << " ";
                i++;
            }
            i = 0;
            while (i <= rear) {
                cout << arr[i] << " ";
                i++;
            }
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter the size of the queue: ";
    cin >> size;
    Queue queue(size);

    int choice;
    do {
        cout << "----- MENU -----" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Cap nhat size cua Queue" << endl;
        cout << "4. Xoa phan tu cua queue" << endl;
        cout << "5. Print Queue" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int element;
                cout << "Nhap phan tu vao Queue: ";
                cin >> element;
                queue.Enqueue(element);
                break;
            }
            case 2: {
                int dequeuedElement = queue.Dequeue();
                if (dequeuedElement != -1) {
                    cout << "Dequeued element: " << dequeuedElement << endl;
                }
                break;
            }
            case 3: {
                int updatedSize = queue.updateSize();
                cout << "Cap nhat size: " << updatedSize << endl;
                break;
            }
            case 4: {
                int index;
                cout << "Nhap phan tu muon xoa: ";
                cin >> index;
                queue.deleteElement(index);
                break;
            }
            case 5: {
                cout << "Queue: ";
                queue.print();
                break;
            }
            case 0: {
                cout  << endl;
                break;
            }
            default: {
                cout << "Lua chon khong hop le!" << endl;
                break;
            }
        }
    } while (choice != 0);

    return 0;
}
