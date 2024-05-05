#include<iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* createNode(int val){
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}


void endQueue(Node** front, Node** rear, int val){
    Node* newNode = createNode(val);
    if(*front == NULL){
        *front = *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
}


void deQueue(Node** front, Node** rear){
    if(*front == NULL){
        cout << "Queue is empty" << endl;
        return;
    }
    Node* temp = *front;
    *front = (*front)->next;
    delete temp;
}
int countNode(Node* front){
    int count = 0;
    Node* temp = front;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

bool isEmpty(Node* front){
    return front == NULL;
}

int main(){
    Node* front = NULL;
    Node* rear = NULL;

    endQueue(&front, &rear, 1);
    endQueue(&front, &rear, 2);
    endQueue(&front, &rear, 3);

    cout << "Number of nodes in the queue: " << countNode(front) << endl;

    deQueue(&front, &rear);
    deQueue(&front, &rear);

    cout << "Number of nodes in the queue: " << countNode(front) << endl;

    if (isEmpty(front)) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue is not empty" << endl;
    }

    return 0;
}