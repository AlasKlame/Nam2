#include<iostream>
#include<fstream>
using namespace std;

int countSizeofFile(ifstream &inputFile){
    int size = 0;
    int temp;
    while(inputFile >> temp){
        size++;
    }
    inputFile.clear();
    inputFile.seekg(0, ios::beg);
    return size;
}

int* input(ifstream &inputFile, int size){
    
    int *arr = new int[size];
    for(int i = 0; i < size; i++){
        inputFile >> arr[i];
        
    }
    return arr;
    
}

void output(int *arr, int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
}



void deletePos(int arr[], int &size, int pos){
    for(int i = pos; i < size - 1; i++){
        arr[i] = arr[i + 1];
    }
    size--;
}

void insert(int arr[], int &size, int pos, int value){
    for(int i = size; i > pos; i--){
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    size++;
}






int main(){
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if(!inputFile.is_open()){
        cout << "Cannot open file" << endl;
        return 0;
    }
    int size = countSizeofFile(inputFile);
    int *a = input(inputFile, size);
    int memory = 0;

    int choice;
    do{
        cout << "------------------------" << endl;
        cout << "Cac lenh xu ly du lieu: " << endl;
        cout << "1. Xoa phan tu tai vi tri pos" << endl;
        cout << "2. Them phan tu tai vi tri pos" << endl;
        cout << "________________________" << endl;
        cout << "Cac lenh chuc nang" << endl;
        cout << "3. Undo" << endl;
        cout << "4. Redo" << endl;
        cout << "5. Save" << endl;
        cout << "6. Reset" << endl;
        cout << "7. Quit" << endl;
        cout << "------------------------" << endl;
        cout << "Nhap lua chon: " << endl;
        cin >> choice;
        memory = choice;
        switch(choice)
        {
            case 1:{
                int pos;
                cout << "Nhap vi tri can xoa: ";
                cin >> pos;
                deletePos(a, size, pos);
                output(a, size);
                cout << endl;
                break;
            } ;
            case 2:{
                int pos, value;
                cout << "Nhap vi tri can them: ";
                cin >> pos;
                cout << "Nhap gia tri can them: ";
                cin >> value;
                insert(a, size, pos, value);
                output(a, size);
                cout << endl;
                break;
            } 
            case 3:
                
                for(int i = 0; i < size; i++){
                    outputFile << a[i] << " ";
                }
                cout << "Da luu file" << endl;
                break;
            default:
                break;

        }
            

    }while(choice != 7);
    

}