#include<iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};


Node* createNode(int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(Node** top, int data){
    Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}

void pop(Node** top){
    if(*top == NULL){
        cout << "Stack is empty" << endl;
        return;
    }
    Node* temp = *top;
    *top = (*top)->next;
    delete temp;
}

int countNode(Node* top){
    int count = 0;
    Node* temp = top;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

bool isEmpty(Node* top){
    return top == NULL;
}

int main(){
    Node* top = NULL;

    push(&top, 10);
    push(&top, 20);
    push(&top, 30);

    cout << "Number of nodes in the stack: " << countNode(top) << endl;

    if(isEmpty(top)){
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is not empty" << endl;
    }

    pop(&top);
    pop(&top);
    pop(&top);

    if(isEmpty(top)){
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is not empty" << endl;
    }

    return 0;
}