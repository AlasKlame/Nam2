#include<iostream>

using namespace std;

class DynamicArray{
    private:
        int size;
        int *arr;
    public:

        DynamicArray(int size){
            this->size = size;;
            arr = new int[size];
        }

        ~DynamicArray(){
            delete[] arr;
        }

        void input(){
            for(int i=0; i<size; i++){
                cin >> arr[i];
            }
        }

        void output(){
            for(int i=0; i<size; i++){
                cout << arr[i] << " ";
            }
        }

        void sort(){

            for(int i=0; i< size - 1; i++){
                for(int j = 0; j < size - i - 1; j++){
                    if(arr[j] > arr[j+1]){
                        int tmp = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = tmp;
                    }
                }
            }
        }

        int secondElement(){
            return arr[size-2];
        }
};



int main(){
    int n;
    cin >> n;
    DynamicArray array(n);
    array.input();
    array.sort();
    array.output();
    cout << "Phan tu lon thu 2 la \n" << array.secondElement() << endl;
    return 0;


}

    

