#include<iostream>
#include<queue>
using namespace std;


struct Node{
    int data;
    Node *pLeft;
    Node *pRight;
};



Node *createNode(int data){
    Node *p = new Node;
    if(p == NULL){
        return NULL;
    }
    p->data = data;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}


void insertNode(Node *&root, int x){
    if(root == NULL){
        root = createNode(x);
        return;
    }
    if(x < root->data){
        insertNode(root->pLeft, x);
    }else if(x > root->data){
        insertNode(root->pRight, x);
    }
}

void NLR(Node* root){
    if(root != NULL){
        cout << root->data << " ";
        NLR(root->pLeft);
        NLR(root->pRight);
    }
}

void LNR(Node* root){
    if(root != NULL){
        LNR(root->pLeft);
        cout << root->data << " ";
        LNR(root->pRight);
    }
}

void LRN(Node* root){
    if(root != NULL){
        LRN(root->pLeft);
        LRN(root->pRight);
        cout << root->data << " ";
    }
}


void LevelOrder (Node *Root){
    if ( Root == NULL ) return;
    queue<Node*> q;
    q.push(Root);
    while ( !q.empty() ){
        Node * p = q.front();
        q.pop();
        cout << p->data << " ";
        if ( p->pLeft != NULL ) q.push(p->pLeft);
        if ( p->pRight != NULL ) q.push(p->pRight);
    }
}

int height(Node* root){
    if(root == NULL){
        return 0;
    }
    int leftHeight = height(root->pLeft);
    int rightHeight = height(root->pRight);
    return max(leftHeight, rightHeight) + 1;
}

int countNode(Node* root){
    if(root == NULL){
        return 0;
    }
    return countNode(root->pLeft) + countNode(root->pRight) + 1;
}

int sumNode(Node* root){
    if(root == NULL){
        return 0;
    }
    return sumNode(root->pLeft) + sumNode(root->pRight) + root->data;
}

Node *search(Node* root, int x){
    if(root == NULL){
        return NULL;
    }
    if(root->data == x){
        return root;
    }
    if(x < root->data){
        return search(root->pLeft, x);
    }else{
        return search(root->pRight, x);
    }
}

void remove(Node* root, int x){
    if(root == NULL){
        return;
    }
    if(root->data == x){
        if(root->pLeft == NULL && root->pRight == NULL){
            delete root;
            root = NULL;
        }else if(root->pLeft == NULL){
            Node* temp = root;
            root = root->pRight;
            delete temp;
        }else if(root->pRight == NULL){
            Node* temp = root;
            root = root->pLeft;
            delete temp;
        }else{
            Node* temp = root->pRight;
            while(temp->pLeft != NULL){
                temp = temp->pLeft;
            }
            root->data = temp->data;
            remove(root->pRight, temp->data);
        }
    }else if(x < root->data){
        remove(root->pLeft, x);
    }else{
        remove(root->pRight, x);
    }
}

Node *createBST(int arr[], int n){
    Node *root = NULL;
    for(int i = 0; i < n; i++){
        insertNode(root, arr[i]);
    }
    return root;
}

void removeBST(Node *&root){
    if(root == NULL){
        return;
    }
    removeBST(root->pLeft);
    removeBST(root->pRight);
    delete root;
    root = NULL;
}


int nodeHeight(Node* root, int x){
    if(root == NULL){
        return -1;
    }
    if(root->data == x){
        return 1;
    }
    if(x < root->data){
        return 1 + nodeHeight(root->pLeft, x);
    }else{
        return 1 + nodeHeight(root->pRight, x);
    }
}

int nodeLevel(Node *root){
    if(root == NULL){
        return 0;
    }
    return max(nodeLevel(root->pLeft), nodeLevel(root->pRight)) + 1;
}

int countLeaf(Node* root){
    if(root == NULL){
        return 0;
    }
    if(root->pLeft == NULL && root->pRight == NULL){
        return 1;
    }
    return countLeaf(root->pLeft) + countLeaf(root->pRight);
}