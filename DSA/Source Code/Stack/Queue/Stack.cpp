#include<iostream>

using namespace std;

struct node{
    int data;
    node* next;
};

void printLastElement(node* head){
    node* tmp = head;
    while(tmp!= nullptr){
        tmp = tmp->next;
    }
    cout << tmp->data;
}

 
node* createNewNode(int x){
    node* tmp = new node;
    tmp->data = x;
    tmp->next = nullptr;
    return tmp;
}

node* addElement(node* head, int x){
    
}