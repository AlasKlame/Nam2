#include<iostream>

using  namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

int sum(Node* root){
    if(root == NULL){
        return 0;
    }
    return sum(root->left) + root->data + sum(root->right);
}

int sumofLeaf(Node* root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return root->data;
    }
    return sumofLeaf(root->left) + sumofLeaf(root->right);

}

bool isLeaf(Node* root){
    if(root == NULL){
        return false;
    }
    if(root->left == NULL && root->right == NULL){
        return true;
    }
    return false;

}

int sumofEvenLeaf(Node* root){
    if(root == NULL){
        return 0;
    }
    if(isLeaf(root) && root->data % 2 == 0){
        return root->data;
    }
    return sumofEvenLeaf(root->left) + sumofEvenLeaf(root->right);

}

Node* createNode(int data){
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void addNode(Node* &root, int data){
    if(root == NULL){
        root = createNode(data);
        return;
    }
    if(data < root->data){
        addNode(root->left, data);
    }else{
        addNode(root->right, data);
    }
}

void printNode(Node* root){
    if(root == NULL){
        return;
    }
    printNode(root->left);
    cout << root->data << " ";
    printNode(root->right);
}

int main(){
    Node* root = NULL;
    addNode(root, 5);
    addNode(root, 3);
    addNode(root, 7);
    addNode(root, 2);
    addNode(root, 4);
    addNode(root, 6);
    addNode(root, 8);
    printNode(root);
    cout << endl;
    cout << sum(root);
    cout << endl;
    cout << sumofEvenLeaf(root);
    return 0;
}