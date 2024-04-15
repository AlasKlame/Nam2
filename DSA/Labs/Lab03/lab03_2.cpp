#include<iostream>

using namespace std;


struct Node{
    int key;
    Node* pLeft;
    Node* pRight;
    int height;
};


Node* createNode(int data){
    Node* newNode = new Node;
    newNode->key = data;
    newNode->pLeft = newNode->pRight = NULL;
    newNode->height = 1;
    return newNode;
}

Node* turnLeft(Node* root){
    Node* p = root->pRight;
    root->pRight = p->pLeft;
    p->pLeft = root;
    return p;

}

Node* turnRight(Node* root){
    Node* p = root->pLeft;
    root->pLeft = p->pRight;
    p->pRight = root;
    return p;
}


void Insert(Node* root, int data){
    if(root == NULL){
        root = createNode(data);
        return;
    }
    if(data < root->key){
        Insert(root->pLeft, data);
    }else{
        Insert(root->pRight, data);
    }
    root->height = max(root->pLeft->height, root->pRight->height) + 1;
    int balance = root->pLeft->height - root->pRight->height;
    if(balance > 1){
        if(data < root->pLeft->key){
            root = turnRight(root);
        }else{
            root->pLeft = turnLeft(root->pLeft);
            root = turnRight(root);
        }
    }else if(balance < -1){
        if(data > root->pRight->key){
            root = turnLeft(root);
        }else{
            root->pRight = turnRight(root->pRight);
            root = turnLeft(root);
        }
    }
}

void Remove(Node* &root, int x){
    if(root == NULL){
        return;
    }
    if(x < root->key){
        Remove(root->pLeft, x);
    }else if(x > root->key){
        Remove(root->pRight, x);
    }else{
        if(root->pLeft == NULL && root->pRight == NULL){
            delete root;
            root = NULL;
        }else if(root->pLeft == NULL){
            Node* p = root;
            root = root->pRight;
            delete p;
        }else if(root->pRight == NULL){
            Node* p = root;
            root = root->pLeft;
            delete p;
        }else{
            Node* p = root->pRight;
            while(p->pLeft != NULL){
                p = p->pLeft;
            }
            root->key = p->key;
            Remove(root->pRight, p->key);
        }
    }
    if(root == NULL){
        return;
    }
    root->height = max(root->pLeft->height, root->pRight->height) + 1;
    int balance = root->pLeft->height - root->pRight->height;
    if(balance > 1){
        if(root->pLeft->pLeft->height >= root->pLeft->pRight->height){
            root = turnRight(root);
        }else{
            root->pLeft = turnLeft(root->pLeft);
            root = turnRight(root);
        }
    }else if(balance < -1){
        if(root->pRight->pRight->height >= root->pRight->pLeft->height){
            root = turnLeft(root);
        }else{
            root->pRight = turnRight(root->pRight);
            root = turnLeft(root);
        }
    }
}

bool isAVL(Node* root){
    if(root == NULL){
        return true;
    }
    if(abs(root->pLeft->height - root->pRight->height) > 1){
        return false;
    }
    return isAVL(root->pLeft) && isAVL(root->pRight);
}

void printAVL(Node* root){
    if(root == NULL){
        return;
    }
    cout << root->key << " ";
    printAVL(root->pLeft);
    
    printAVL(root->pRight);

}

int main(){
    Node* root = NULL;
    Insert(root, 10);
    Insert(root, 20);
    Insert(root, 30);
    Insert(root, 40);
    Insert(root, 50);
    Insert(root, 25);
    Insert(root, 15);
    Insert(root, 5);
    
    printAVL(root);
}