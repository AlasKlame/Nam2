#include<iostream>
#include<fstream>
#include<vector>

using namespace std;


struct SinhVien{
    string name;
    int MSSV;
    float DTB;
};
struct SinhVien typedef SV;


struct Node{  
    SV data;
    Node* left;
    Node* right;
    int height;
};

Node* createNode(SV sv){
    Node* p = new Node;
    p->data= sv;
    p->left = NULL;
    p->right = NULL;
    p->height = 1;
    return p;
}

Node *turnLeft(Node* pRoot){
    Node* pTemp = pRoot->right;
    pRoot->right = pTemp->left;
    pTemp->left = pRoot;
    pRoot->height = max((pRoot->left ? pRoot->left->height : 0), (pRoot->right ? pRoot->right->height : 0)) + 1;
    pTemp->height = max((pTemp->left ? pTemp->left->height : 0), (pTemp->right ? pTemp->right->height : 0)) + 1;

    return pTemp;
}

Node *turnRight(Node* pRoot){
    Node* pTemp = pRoot->left;
    pRoot->left = pTemp->right;
    pTemp->right = pRoot;
    pRoot->height = max((pRoot->left ? pRoot->left->height : 0), (pRoot->right ? pRoot->right->height : 0)) + 1;
    pTemp->height = max((pTemp->left ? pTemp->left->height : 0), (pTemp->right ? pTemp->right->height : 0)) + 1;

    return pTemp;
}


bool balance(Node* pRoot){
    if(pRoot == NULL){
        return true;
    }
    int leftHeight = 0;
    int rightHeight = 0;
    if(pRoot->left != NULL){
        leftHeight = pRoot->left->height;
    }
    if(pRoot->right != NULL){
        rightHeight = pRoot->right->height;
    }
    if(leftHeight - rightHeight > 1 || leftHeight - rightHeight < -1){
        return false;
    }
    return true;
}

void Insert(Node* &pRoot, SV data) {
    if (pRoot == NULL) {
        pRoot = createNode(data);
        return;
    }
    if (data.MSSV < pRoot->data.MSSV) {
        Insert(pRoot->left, data);
    } else if (data.MSSV > pRoot->data.MSSV) {
        Insert(pRoot->right, data);
    } else {
        return;
    }

    pRoot->height = 1 + max(pRoot->left ? pRoot->left->height : 0,
                        pRoot->right ? pRoot->right->height : 0);



    int balance = (pRoot->left ? pRoot->left->height : 0) - 
                  (pRoot->right ? pRoot->right->height : 0);


    if (balance > 1 && data.MSSV < pRoot->left->data.MSSV) {
        pRoot = turnRight(pRoot);
    }

    else if (balance > 1 && data.MSSV > pRoot->left->data.MSSV) {
        pRoot->left = turnLeft(pRoot->left);
        pRoot = turnRight(pRoot);
    }

    
    else if (balance < -1 && data.MSSV > pRoot->right->data.MSSV) {
        pRoot = turnLeft(pRoot);
    }

    else if (balance < -1 && data.MSSV < pRoot->right->data.MSSV) {
        pRoot->right = turnRight(pRoot->right);
        pRoot = turnLeft(pRoot);
    }
}


void readSVFromFile(string fileName, Node* &root){
    ifstream inFile(fileName);
    string line;
    while(getline(inFile, line)){
        SV sv;
        string name; int id; float ave;
        inFile >> id;
        inFile.ignore();
        getline(inFile, name, ',');
        inFile >> ave;

        sv.MSSV = id;
        sv.name = name;
        sv.DTB = ave;
        Insert(root, sv);
    }
    inFile.close();
}


void remove(Node *&root, SV x){
    if(root == NULL){
        return;
    }
    if(x.MSSV < root->data.MSSV){
        remove(root->left, x);
    }else if(x.MSSV > root->data.MSSV){
        remove(root->right, x);
    }else{
        if(root->left == NULL && root->right == NULL){
            delete root;
            root = NULL;
        }else if(root->left == NULL){
            Node *temp = root;
            root = root->right;
            delete temp;
        }else if(root->right == NULL){
            Node *temp = root;
            root = root->left;
            delete temp;
        }else{
            Node *temp = root->right;
            while(temp->left != NULL){
                temp = temp->left;
            }
            root->data = temp->data;
            remove(root->right, temp->data);
        }
    }
    if(root == NULL){
        return;
    }
    int leftHeight = 0;
    int rightHeight = 0;
    if(root->left != NULL){
        leftHeight = root->left->height;
    }
    if(root->right != NULL){
        rightHeight = root->right->height;
    }
    root->height = max(leftHeight, rightHeight) + 1;
    if(leftHeight - rightHeight > 1){
        if(balance(root->left)){
            root = turnRight(root);
        }else{
            root->left = turnLeft(root->left);
            root = turnRight(root);
        }
    }else if(leftHeight - rightHeight < -1){
        if(balance(root->right)){
            root = turnLeft(root);
        }else{
            root->right = turnRight(root->right);
            root = turnLeft(root);
        }
    }
}


void print(Node* pRoot){
    if(pRoot == NULL){
        return;
    }
    
    print(pRoot->left);
    cout << pRoot->data.MSSV << endl;
    cout << pRoot->data.name << endl;
    cout << pRoot->data.DTB << endl;
    print(pRoot->right);
}


int main(){
    SV sv;
    Node* root = nullptr;
    readSVFromFile("data.csv", root);
    print(root);

}