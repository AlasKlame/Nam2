#include <iostream>

using namespace std;

class Queue{
    private:
        int size;
        int front;
        int rear;
        int *arr;
    public:
        Queue(int size){
            this->size = size;
            arr = new int[size];
            front = -1;
            rear = -1;
        }

        ~Queue(){
            delete[] arr;
        }

        void Front(int element){
            if(isFull()){
                cout << "Queue is full" << endl;
                return;
            }
            arr[front++] = element;
        }

        bool isEmpty() {
            return front == -1;
        }

        bool isFull() {
            return (front == 0 && rear == size - 1) || (front == rear + 1);
        }

        int Dequeue(){
            if(isEmpty()){
                return -1;
            }
            int data = arr[front];
            if(front == rear){
                front = rear = -1;
            }else{
                front = (front + 1) % size;
            }
            return data;
        }

        int Enqueue(){
            if(isFull()){
                return -1;
            }
            int data;
            cin >> data;
            if(front == -1){
                front = 0;
            }
            rear = (rear + 1) % size;
            arr[rear] = data;
            return 0;
        }

        void print(){
            if(isEmpty()){
                cout << "Queue is empty" << endl;
                return;
            }
            int i = front;
            if(front <= rear){
                while(i <= rear){
                    cout << arr[i] << " ";
                    i++;
                }
            }else{
                while(i < size){
                    cout << arr[i] << " ";
                    i++;
                }
                i = 0;
                while(i <= rear){
                    cout << arr[i] << " ";
                    i++;
                }
            }
            cout << endl;
        }
};

int main(){
    int n;
    cin >> n;
    Queue queue(n);
    while(queue.isFull() == false){
        int element;
        cin >> element;
        queue.Front(element);
    }
    queue.print();
}