#include<iostream>

using  namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;    
};





void Preorder(Node* root){
    if(root == nullptr){
        return;
    }
    else{
        cout << root->data << " ";
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Inorder(Node* root){
    if(root == nullptr){
        return;
    }
    else{
        Inorder(root->left);
        cout << root->data << " ";
        Inorder(root->right);
    }
}

void Postorder(Node* root){
    if(root == nullptr){
        return;
    }
    else{
        Postorder(root->left);
        Postorder(root->right);
        cout << root->data << " ";
    }
}

void PrintLeaf(Node* root){
    if(root != nullptr){return;}
    if(!(root->left) && !(root->right)){
        cout << root->data << endl;
    }
    PrintLeaf(root->left);
    PrintLeaf(root->right);
}

void printOneSub(Node* root){
    if(root == nullptr){
        return ;
    }
    else{
        if(root->left && !(root->right) || !(root->left->right) || !(root->left) && (root->right)){
            cout << root->data << endl;
        }
    }
    printOneSub(root->left);
    printOneSub(root->right);
}

int countNode(Node* root) {
    if(root == nullptr) {
        return 0; 
    }
    int count = 1; 
    if(root->left != nullptr) {
        count += countNode(root->left); 
    }
    if(root->right != nullptr) {
        count += countNode(root->right);
    }
    return count;
}

int height(Node* root){
    if(root == nullptr){
        return 0;
    }
    int a = height(root->left);
    int b = height(root->right);
    return max(a, b) + 1;
}

int findBrother(Node* root, Node* parent, int x){
    if(root == nullptr){
        return -1;
    }
    if(root->data == x){
        if(parent == nullptr){
            return 1;
        }
        else{
            return parent->data;
        }
    }
    int left_result = findBrother(root->left,root,x);
    if(left_result != -1){
        return left_result;
    }
    findBrother(root->right,root,x);
}

int level(Node* root, int d = 0){
    if(root == nullptr){
        return d;
    }
    int lf_height = level(root->left,d+1);
    int r_height = level(root->right,d+1);
    return max(lf_height,r_height);
}

bool isFullTree(Node* root){
    if(root == nullptr){
        return true;
    }
    if(root->left == nullptr && root->right == nullptr){
        return true;
    }
    if(root->left != nullptr && root->right != nullptr){
        return isFullTree(root->left) && isFullTree(root->right);
    }
    return false;

}

bool isPerfectTree(Node* root, int d, int level){
    if(root == nullptr){
        return true;
    }
    if(root->left == nullptr && root->right == nullptr){
        return d == level;
    }
    if(root->left == nullptr || root->right == nullptr){
        return false;
    }
    return isPerfectTree(root->left,d+1,level) && isPerfectTree(root->right,d+1,level);
}
void insertNode(Node* &root, int x){
    if(root == nullptr){
        root = new Node;
        root->data = x;
        root->left = nullptr;
        root->right = nullptr;
    }
    else{
        if(x < root->data){
            insertNode(root->left, x);
        }
        else if(x > root->data){
            insertNode(root->right, x);
        }
    }
}

void inputElement(Node* &root){
    int x, n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        insertNode(root, x);
    }
    cin.clear();
}


int main(){
    Node* root = nullptr;
    inputElement(root);
    cout << "Sau khi nhap xong:" << endl;
    int height_1 = height(root);
    cout << height_1 << endl;

    return 0;
}
