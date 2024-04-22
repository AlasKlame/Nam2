#include<iostream>

using namespace std;


struct Node{
    int key ;
    Node * pLeft ;
    Node * pRight ;
    int height ;
};

Node* createNode(int data){
    Node* p = new Node;
    if(p == NULL){
        cout << "Memory allocation failed!" << endl;
        return NULL;
    }
    p->key = data;
    p->pLeft = NULL;
    p->pRight = NULL;
    p->height = 1;
    return p;
}



Node *turnLeft(Node* pRoot){
    Node* pTemp = pRoot->pRight;
    pRoot->pRight = pTemp->pLeft;
    pTemp->pLeft = pRoot;
    pRoot->height = max(pRoot->pLeft->height, pRoot->pRight->height) + 1;
    pTemp->height = max(pTemp->pLeft->height, pTemp->pRight->height) + 1;
    return pTemp;
}

Node *turnRight(Node* pRoot){
    Node* pTemp = pRoot->pLeft;
    pRoot->pLeft = pTemp->pRight;
    pTemp->pRight = pRoot;
    pRoot->height = max(pRoot->pLeft->height, pRoot->pRight->height) + 1;
    pTemp->height = max(pTemp->pLeft->height, pTemp->pRight->height) + 1;
    return pTemp;
}

bool balance(Node* pRoot){
    if(pRoot == NULL){
        return true;
    }
    int leftHeight = 0;
    int rightHeight = 0;
    if(pRoot->pLeft != NULL){
        leftHeight = pRoot->pLeft->height;
    }
    if(pRoot->pRight != NULL){
        rightHeight = pRoot->pRight->height;
    }
    if(leftHeight - rightHeight > 1 || leftHeight - rightHeight < -1){
        return false;
    }
    return true;
}

void Insert(Node* &pRoot, int data) {
    if (pRoot == NULL) {
        pRoot = createNode(data);
        return;
    }
    if (data < pRoot->key) {
        Insert(pRoot->pLeft, data);
    } else if (data > pRoot->key) {
        Insert(pRoot->pRight, data);
    } else {
        // Handle duplicate key scenario if needed
        return;
    }

    // Update the height of the ancestor node
    pRoot->height = max(pRoot->pLeft->height, pRoot->pRight->height) + 1;


    // Get the balance factor to check whether this node became unbalanced
    int balance = (pRoot->pLeft ? pRoot->pLeft->height : 0) - 
                  (pRoot->pRight ? pRoot->pRight->height : 0);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && data < pRoot->pLeft->key) {
        pRoot = turnRight(pRoot);
    }

    // Left Right Case
    else if (balance > 1 && data > pRoot->pLeft->key) {
        pRoot->pLeft = turnLeft(pRoot->pLeft);
        pRoot = turnRight(pRoot);
    }

    // Right Right Case
    else if (balance < -1 && data > pRoot->pRight->key) {
        pRoot = turnLeft(pRoot);
    }

    // Right Left Case
    else if (balance < -1 && data < pRoot->pRight->key) {
        pRoot->pRight = turnRight(pRoot->pRight);
        pRoot = turnLeft(pRoot);
    }
}


void remove(Node *&root, int x){
    if(root == NULL){
        return;
    }
    if(x < root->key){
        remove(root->pLeft, x);
    }else if(x > root->key){
        remove(root->pRight, x);
    }else{
        if(root->pLeft == NULL && root->pRight == NULL){
            delete root;
            root = NULL;
        }else if(root->pLeft == NULL){
            Node *temp = root;
            root = root->pRight;
            delete temp;
        }else if(root->pRight == NULL){
            Node *temp = root;
            root = root->pLeft;
            delete temp;
        }else{
            Node *temp = root->pRight;
            while(temp->pLeft != NULL){
                temp = temp->pLeft;
            }
            root->key = temp->key;
            remove(root->pRight, temp->key);
        }
    }
    if(root == NULL){
        return;
    }
    int leftHeight = 0;
    int rightHeight = 0;
    if(root->pLeft != NULL){
        leftHeight = root->pLeft->height;
    }
    if(root->pRight != NULL){
        rightHeight = root->pRight->height;
    }
    root->height = max(leftHeight, rightHeight) + 1;
    if(leftHeight - rightHeight > 1){
        if(balance(root->pLeft)){
            root = turnRight(root);
        }else{
            root->pLeft = turnLeft(root->pLeft);
            root = turnRight(root);
        }
    }else if(leftHeight - rightHeight < -1){
        if(balance(root->pRight)){
            root = turnLeft(root);
        }else{
            root->pRight = turnRight(root->pRight);
            root = turnLeft(root);
        }
    }
}


bool isAVL(Node* pRoot){
    if(pRoot == NULL){
        return true;
    }
    if(!balance(pRoot)){
        return false;
    }
    return isAVL(pRoot->pLeft) && isAVL(pRoot->pRight);
}

void print(Node* pRoot){
    if(pRoot == NULL){
        return;
    }
    cout << pRoot->key << " ";
    print(pRoot->pLeft);
    print(pRoot->pRight);
}

void deleteTree(Node* &pRoot){
    if(pRoot == NULL){
        return;
    }
    deleteTree(pRoot->pLeft);
    deleteTree(pRoot->pRight);
    delete pRoot;
    pRoot = NULL;
}

int main(){
    Node* pRoot = NULL;
    Insert(pRoot, 10);
    Insert(pRoot, 20);
    Insert(pRoot, 30);
    Insert(pRoot, 15);
    Insert(pRoot, 25);
    Insert(pRoot, 5);
    Insert(pRoot, 35);
    Insert(pRoot, 40);
    Insert(pRoot, 45);
    Insert(pRoot, 50);
    Insert(pRoot, 55);

    print(pRoot);
    deleteTree(pRoot);
}