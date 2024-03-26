#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

struct List{    
    Node* head;
    Node* tail;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

List* createList(Node* node) {
    List* list = new List;
    list->head = node;
    list->tail = node;
    return list;
}

bool addHead(List* list, Node* node) {
    if (list->head == nullptr) {
        list->head = node;
        list->tail = node;
        return true;
    }
    node->next = list->head;
    list->head = node;
    return true;
}

bool addTail(List* list, Node* node) {
    if (list->head == nullptr) {
        list->head = node;
        list->tail = node;
        return true;
    }
    list->tail->next = node;
    list->tail = node;
    return true;
}

bool addPos(List*& L, int val, int pos){
    Node* newNode = createNode(val);
    if(pos == 0){
        addHead(L, newNode);
        return true;
    }
    Node* temp = L->head;
    for(int i = 0; i < pos - 1; i++){
        if(temp == nullptr){
            return false;
        }
        temp = temp->next;
    }
    if(temp == nullptr){
        return false;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return true;
}

bool addBefore(List*& L, int data, int val){
    Node* newNode = createNode(val);
    if(L->head == nullptr){
        return false;
    }
    if(L->head->data == data){
        addHead(L, newNode);
        return true;
    }
    Node* temp = L->head;
    while(temp->next != nullptr){
        if(temp->next->data == data){
            newNode->next = temp->next;
            temp->next = newNode;
            return true;
        }
        temp = temp->next;
    }
    return false;
}

bool addAfter(List*& L, int data, int val){
    Node* newNode = createNode(val);
    if(L->head == nullptr){
        return false;
    }
    Node* temp = L->head;
    while(temp != nullptr){
        if(temp->data == data){
            newNode->next = temp->next;
            temp->next = newNode;
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void removeHead(List*& L){
    if(L->head == nullptr){
        return;
    }
    Node* temp = L->head;
    L->head = L->head->next;
    delete temp;
}

void removeTail(List*& L){
    if(L->head == nullptr){
        return;
    }
    if(L->head->next == nullptr){
        delete L->head;
        L->head = nullptr;
        return;
    }
    Node* temp = L->head;
    while(temp->next->next != nullptr){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}