#include<iostream>
#include<fstream>
using namespace std;

int countSizeofFile(ifstream &inputFile){
    int size = 0;
    int temp;
    while(inputFile >> temp){
        size++;
    }
    return size;
}

void input(ifstream &inputFile, int arr[], int &size){
    
    for(int i = 0; i < size; i++){
        inputFile >> arr[i];
    }
}

void output(ofstream &outputFile, int arr[], int &size){
    for(int i = 0; i < size; i++){
        outputFile << arr[i] << " ";
    }
}



int main(){
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");
    int *arr;
    if(!inputFile.is_open()){
        cout << "Cannot open file" << endl;
        return 0;
    }

    int size = countSizeofFile(inputFile);
    arr = new int[size];
    input(inputFile, arr, size);
    output(outputFile, arr, size);
    
    

}