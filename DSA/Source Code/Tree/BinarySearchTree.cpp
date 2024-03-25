#include<iostream>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};


Node* find(Node* root, int x){
    if(root == NULL){
        return NULL;
    }
    if(root->data == x){
        return root;
    }
    if(root->data < x){
        return find(root->right, x);
    }
    return find(root->left, x);
}

Node* addKeytoTree(Node* root, int key){
    if(root == nullptr){
        Node* newRoot = new Node;
        newRoot->data = key;
        newRoot->left = nullptr;
        newRoot->right = nullptr;
        return newRoot;
    }
    if(root->data == key){
        return root;
    }
    if(root->data < key){
        return addKeytoTree(root->right, key);
    }
    if(root->data > key){
        return addKeytoTree(root->left, key);
    }
    
}

bool isBST(Node* root, int min, int max){
    if(root == nullptr){
        return true;
    }
    if(root->data <= min || root->data >= max){
        return false;
    }
    bool leftValid = isBST(root->left, min, root->data);
    bool rightValid = isBST(root->right, root->data, max);
    return leftValid && rightValid;
}

Node* findMin(Node* root){
    if(root == nullptr){
        return nullptr;
    }
    if(root->left == nullptr){
        return root;
    }
    return findMin(root->left);
}

Node* turnLeft(Node* root){
    Node* b = root->right;
    Node* t = b->left;
    root->right = t;
    b->left = root;
    return b;
}

Node* turnRight(Node* root){
    Node* b = root->left;
    Node* t = b->right;
    root->left = t;
    b->right = root;
    return b;
}

Node* removeNode(Node* root, int key){
    if(root == nullptr){
        return nullptr;
    }
    if(root->data < key){
        root->right = removeNode(root->right, key);
    }
    else if(root->data > key){
        root->left = removeNode(root->left, key);
    }
    else{
        if(root->left == nullptr){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == nullptr){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else{
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = removeNode(root->right, temp->data);
        }
    }
    return root;
}