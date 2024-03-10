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
        int updateSize(){
            return top + 1;
        }
        void print(){
            for(int i = 0; i <= top; i++){
                cout << arr[i] << " ";
            }
        
        }

};

int main(){
    int size;
    cout << "Nhap kich thuoc stack: ";
    cin >> size;
    Stack stack(size);
    {
        int choice;
        do{
            cout << "1. Them phan tu vao stack" << endl;
            cout << "2. Xoa phan tu khoi stack" << endl;
            cout << "3. Lay phan tu o dau stack" << endl;
            cout << "4. Kiem tra stack rong" << endl;
            cout << "5. Kiem tra stack day" << endl;
            cout << "6. Lay kich thuoc stack" << endl;
            cout << "7. In stack" << endl;
            cout << "8. Thoat" << endl;
            cout << "Nhap lua chon: ";
            cin >> choice;
            switch(choice){
                case 1:
                    int element;
                    cout << "Nhap phan tu can them: ";
                    cin >> element;
                    stack.push(element);
                    break;
                case 2:
                    stack.pop();
                    break;
                case 3:
                    cout << "Phan tu o dau stack: " << stack.peek() << endl;
                    break;
                case 4:
                    if(stack.isEmpty()){
                        cout << "Stack rong" << endl;
                    }else{
                        cout << "Stack khong rong" << endl;
                    }
                    break;
                case 5:
                    if(stack.isFull()){
                        cout << "Stack day" << endl;
                    }else{
                        cout << "Stack chua day" << endl;
                    }
                    break;
                case 6:
                    cout << "Kich thuoc stack: " << stack.updateSize() << endl;
                    break;
                case 7:
                    stack.print();
                    cout << endl;
                    break;
                case 8:
                    cout << "Tam biet" << endl;
                    break;
                default:
                    cout << "Lua chon khong hop le" << endl;
                    break;
            }
        }while(choice != 8);
    }
    return 0;
}