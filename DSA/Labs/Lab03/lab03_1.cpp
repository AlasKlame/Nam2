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


int countLess(Node* root, int x){
    if(root == NULL){
        return 0;
    }
    if(root->data < x){
        return 1 + countLess(root->pLeft, x) + countLess(root->pRight, x);
    }else if(root->data == x){
        return 1 + countLess(root->pLeft, x);
    }else{
        return countLess(root->pLeft, x);
    }
}

int countGreater(Node* root, int x){
    if(root == NULL){
        return 0;
    }
    if(root->data > x){
        return 1 + countGreater(root->pLeft, x) + countGreater(root->pRight, x);
    }
    else if(root->data == x){
        return 1 + countGreater(root->pRight, x);
    }
    else{
        return countGreater(root->pRight, x);
    }
}

bool isBST(Node* root, int min, int max){
    if(root == NULL ){
        return true;
    }
    if(root->data > max || root->data < min){
        return false;
    }
    bool leftValid = isBST(root->pLeft, min, root->data) ;
    bool rightValid = isBST(root->pRight, root->data, max);
    return leftValid && rightValid;
}


int minNode(Node* root){
    if(root == NULL){
        return 0;
    }
    if(root->pLeft == NULL){
        return root->data;
    }
    return minNode(root->pLeft);
}

int maxNode(Node* root){
    if(root == NULL){
        return 0;
    }
    if(root->pRight == NULL){
        return root->data;
    }
    return maxNode(root->pRight);
}

bool isFullBST(Node* root){
    if(root == NULL){
        return true;
    }
    if(root->pLeft == NULL && root->pRight == NULL){
        return true;
    }
    if((root->pLeft == NULL && root->pRight != NULL) || (root->pLeft != NULL && root->pRight != NULL)){
        return false;
    }
    return isFullBST(root->pLeft) && isFullBST(root->pRight);
}


int main(){
    Node *root = NULL;
    int arr[] = {5, 3, 7, 2, 4, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    root = createBST(arr, n);
    
    int x = 5;
    int min = minNode(root);
    cout << "Min of BST: " << min << endl;
    int max = maxNode(root);
    cout << "Max of BST: " << max << endl;

    if(isBST(root, min, max)){
        cout << "true" <<endl;
    }
    else{
        cout << "false" << endl;
    }
    if(isFullBST(root)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }

    int lessCount = countLess(root, x);
    cout << "Number of nodes less than " << x << ": " << lessCount << endl;
    
    int greaterCount = countGreater(root, x);
    cout << "Number of nodes greater than " << x << ": " << greaterCount << endl;
    
    removeBST(root);
    
    return 0;
}