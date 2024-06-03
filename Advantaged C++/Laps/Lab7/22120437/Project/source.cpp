#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>

using namespace std;


vector<int> readFileToArray(string fileName){
    ifstream inFile(fileName);
    vector<int> arr;

    string line;
    while(getline(inFile, line)){
        int tmp;
        stringstream ss(line);
        while(ss >> tmp){
            arr.push_back(tmp);
        }
    }
    inFile.close();
    return arr;
}

void deleteX(vector<int> &arr, int x){
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == x){
            arr.erase(arr.begin() + i);
            i--;
        }
    }
}

void reverseArray(vector<int> &arr){
    for(int i = 0; i < arr.size() / 2; i++){
        swap(arr[i], arr[arr.size() - i - 1]);
    }
}

void insertX(vector<int> &arr, int x) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != x) {
        arr.insert(arr.begin() + i, x);  
        i++;
        }
    }
    if (arr.back() != x) {
        arr.push_back(x); 
    }
}

void sortArray(vector<int> &arr){
    for(int i = 0; i < arr.size() - 1; i++){
        for(int j = i + 1; j < arr.size(); j++){
            if(arr[i] > arr[j]){
                swap(arr[i], arr[j]);
            }
        }
    }
}

bool checkArrayEmpty(vector<int> arr){
    return arr.size() == 0;
}


int main(){
    string fileName = "input.txt";
    ofstream outFile("output.txt");
    vector<int> arr = readFileToArray(fileName);

    if(!checkArrayEmpty(arr)){
        for(int i = 0; i < arr.size(); i++){
            outFile << arr[i] << " ";
        }
        outFile << endl;

        int x;
        cout  << "\nNhap x: ";
        cin >> x;
        

        insertX(arr, x);
        for(int i = 0; i < arr.size(); i++){
            outFile << arr[i] << " ";
        }
        outFile << endl;

        deleteX(arr, x);
        for(int i = 0; i < arr.size(); i++){
            outFile << arr[i] << " ";
        }
        outFile << endl;

        reverseArray(arr);
        for(int i = 0; i < arr.size(); i++){
            outFile << arr[i] << " ";
        }
        outFile << endl;

        sortArray(arr);
        for(int i = 0; i < arr.size(); i++){
            outFile << arr[i] << " ";
        }
    }
    else{
        outFile << "Mang rong!";
    }


}