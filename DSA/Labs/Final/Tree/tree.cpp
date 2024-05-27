#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;


struct SinhVien{
    string MSSV;
    string HoTen;
    float DTB;
};
struct SinhVien typedef SV;

struct Node{
    SinhVien data;
    Node* left;
    Node* right;  
}; 

bool sosanhMSSV(SV sv1, SV sv2){
    return sv1.MSSV < sv2.MSSV;
}


Node* createNode(SV sv){
    Node* tmp = new Node;
    tmp->data = sv;
    tmp->left = tmp->right = NULL;
    return tmp;
}

void addNode(Node* &root, SV &data){
    if(root == nullptr){
        root = createNode(data);
        return;
    }
    if(sosanhMSSV(data, root->data)){
        addNode(root->left, data);
    }
    else{
        addNode(root->right, data);
    }
}

void ReadDataSV(string fileName, Node* &root){
    ifstream inFile(fileName);
    string line;
    while(getline(inFile, line)){
        SV sv;
        string name, id; float ave;
        getline(inFile, id, ',');
        getline(inFile, name, ',');
        inFile >> ave;
        
        sv.HoTen = name;
        sv.MSSV = id;
        sv.DTB = ave;
        addNode(root, sv);
    }
    inFile.close();
}

void ReadDataSV_1(string fileName, Node* &root){
    ifstream inFile(fileName);
    string line;
    while(getline(inFile, line)){
        SV sv;
        string name, id; float ave;
        stringstream ss(line);
        ss >> name ;
        ss >> id;
        ss >> ave;
        sv.HoTen = name;
        sv.MSSV = id;
        sv.DTB = ave;
        addNode(root, sv);
    }
    inFile.close();
}

void printSinhVien(SV sv){
    cout << sv.MSSV << endl;
    cout << sv.HoTen << endl;
    cout << sv.DTB << endl;
}

void printNode(Node* node) {
    if (node != nullptr) {
        cout << "MSSV: " << node->data.MSSV << endl;
        cout << "Họ tên: " << node->data.HoTen << endl;
        cout << "Điểm trung bình: " << node->data.DTB << endl;
        cout << "---------------------" << endl;

        printNode(node->left);
        printNode(node->right);
    }
}

void remove(Node* &root, SV &sv){
    if(root == NULL){
        return;
    }
    if(root->data.MSSV == sv.MSSV){
        if(root->left == NULL && root->right == NULL){
            delete root;
            root = NULL;
        }else if(root->left == NULL){
            Node* temp = root;
            root = root->right;
            delete temp;
        }else if(root->right == NULL){
            Node* temp = root;
            root = root->left;
            delete temp;
        }else{
            Node* temp = root->right;
            while(temp->left != NULL){
                temp = temp->left;
            }
            root->data = temp->data;
            remove(root->right, temp->data);
        }
    }else if(sv.MSSV < root->data.MSSV){
        remove(root->left, sv);
    }else if(sv.MSSV > root->data.MSSV){
        remove(root->right, sv);
    }
    else{
        cout << "KHONG TIM THAY SINH VIEN ";
    }
}


void searchSV(Node* &root, SV &sv){
    if(root == nullptr){
        return;
    }
    if(sv.MSSV == root->data.MSSV){
        cout << "MSSV: " << root->data.MSSV << endl;
        cout << "Họ tên: " << root->data.HoTen << endl;
        cout << "Điểm trung bình: " << root->data.DTB << endl;
        cout << "---------------------" << endl;
    }
    else if(sv.MSSV < root->data.MSSV){
        searchSV(root->left, sv); 
    }
    else if(sv.MSSV > root->data.MSSV){
        searchSV(root->right, sv);
    }
}

void inOrderTrans(Node* root, vector<SV> &List){
    if(root != nullptr){
        inOrderTrans(root->left, List);
        List.push_back(root->data);
        inOrderTrans(root->right, List);
    }
}

bool compareDTB(SV sv1, SV sv2){
    return sv1.DTB > sv2.DTB;
}

bool compareMSSV(SV sv1, SV sv2){
    return sv1.MSSV < sv2.MSSV;
}

int partition(vector<SinhVien>& svList, int low, int high) {
    float pivot = svList[high].DTB;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (compareMSSV(svList[j], svList[high])) {
            i++;
            swap(svList[i], svList[j]);
        }
    }
    swap(svList[i + 1], svList[high]);
    return (i + 1);
}

void quickSort(vector<SinhVien>& svList, int low, int high) {
    if (low < high) {
        int pi = partition(svList, low, high);
        quickSort(svList, low, pi - 1);
        quickSort(svList, pi + 1, high);
    }
}
int main(){
    SV sv;
    Node* root = nullptr;
    ReadDataSV("data.csv", root);
    
    int choice;

    do{
        cout << "1: Xoa 1 sinh vien theo mssv" << endl;
        cout << "2: Tim sinh vien theo mssv " << endl;
        cout << "3: Sap xep xinh vien" << endl;
        cout << "4: Inra thong tin sinh vien" << endl;
        cout << " Nhap lua chon di bro: " <<endl;
        cin >> choice;
        switch (choice){
            case 1:{
                cout << "Nhap thong tin mssv can xoa: ";
                string mssv;
                SV sv1;
                cin >> mssv;
                sv1.MSSV = mssv;
                remove(root, sv1);
                printNode(root);
                break;
            }
            case 2:{
                cout << "Nhap thong tin mssv can TIM: ";
                string mssv;
                SV sv1;
                cin >> mssv;
                sv1.MSSV = mssv;
                searchSV(root, sv1);
                break;
            }
            case 3:{
                vector<SV> list;
                inOrderTrans(root, list);
                quickSort(list,0, list.size() - 1);
                for(int i = 0; i < list.size(); i++){
                    cout << list[i].DTB << endl;
                    cout << list[i].MSSV << endl;
                    cout << list[i].HoTen << endl;
                }
                break;
            }
            case 4:{
                vector<SV> list;
                inOrderTrans(root, list);
                quickSort(list,0, list.size() - 1);
                for(int i = 0; i < list.size(); i++){
                    cout << "-------------------" << endl;
                    cout << list[i].MSSV << endl;
                    cout << list[i].HoTen << endl;
                    cout << list[i].DTB << endl;
                }
                break;
            }
        }
    }while(choice != 5);

}