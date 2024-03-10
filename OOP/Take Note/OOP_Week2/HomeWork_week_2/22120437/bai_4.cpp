#include<iostream>

using namespace std;

class Stack{    //LIFO
    private:
        int size;
        int top;
        int *arr;
    public:
        Stack(int size){
            this->size = size;
            arr = new int[size];
            top = -1;
        }

        ~Stack(){
            delete[] arr;
        }

        bool isEmpty(){
            return top == -1;
        }

        bool isFull(){
            return top == size - 1;
        
        }

        void push(int element){
            if(isFull()){
                cout << "Stack is full" << endl;
                return;
            }
            arr[++top] = element;
        
        }

        int pop(){
            if(isEmpty()){
                cout << "Stack is empty" << endl;
                return -1;
            }
            return arr[top--];
        }

        int peek(){
            if(isEmpty()){
                cout << "Stack is empty" << endl;
                return -1;
            }
            return arr[top];
        }
        void print(){
            for(int i = 0; i <= top; i++){
                cout << arr[i] << " ";
            }
        
        }

};

int main(){
    int n;
    cin >> n;
    Stack stack(n);
    while(stack.isFull() == false){
        int element;
        cin >> element;
        stack.push(element);
    }
    cout << "Stack sau khi push" << endl;
    stack.print();
    cout << endl;
    cout << "xem phan tu dau tien " << stack.peek() << endl;
    cout << "Lay phan tu dau tien va xoa ra khoi stack: " <<  stack.pop() << endl;
    cout << "stack sau khi lay phan tu dau tien: ";
    stack.print();
    return 0;
}