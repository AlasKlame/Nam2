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


void removePos(List*& L, int pos){
    if(L->head == nullptr){
        return;
    }
    if(pos == 0){
        removeHead(L);
        return;
    }
    Node* temp = L->head;
    for(int i = 0; i < pos - 1; i++){
        if(temp == nullptr){
            return;
        }
        temp = temp->next;
    }
    if(temp == nullptr || temp->next == nullptr){
        return;
    }
    Node* del = temp->next;
    temp->next = temp->next->next;
    delete del;
}

void removeAll(List*& L){
    while(L->head != nullptr){
        removeHead(L);
    }
}

void removeBefore(List*& L, int data){
    if(L->head == nullptr){
        return;
    }
    if(L->head->data == data){
        return;
    }
    if(L->head->next->data == data){
        removeHead(L);
        return;
    }
    Node* temp = L->head;
    while(temp->next->next != nullptr){
        if(temp->next->next->data == data){
            Node* del = temp->next;
            temp->next = temp->next->next;
            delete del;
            return;
        }
        temp = temp->next;
    }
}


void removeAfter(List*& L, int data){
    if(L->head == nullptr){
        return;
    }
    Node* temp = L->head;
    while(temp != nullptr){
        if(temp->data == data){
            if(temp->next == nullptr){
                return;
            }
            Node* del = temp->next;
            temp->next = temp->next->next;
            delete del;
            return;
        }
        temp = temp->next;
    }
}



void printList(List* L){
    Node* temp = L->head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int countElements(List* L){
    Node* temp = L->head;
    int count = 0;
    while(temp != nullptr){
        count++;
        temp = temp->next;
    }
    return count;
}


List reverseList(List* L){
    List reversedList;
    reversedList.head = nullptr;
    reversedList.tail = nullptr;
    Node* temp = L->head;
    while(temp != nullptr){
        Node* newNode = createNode(temp->data);
        addHead(&reversedList, newNode);
        temp = temp->next;
    }
    return reversedList;
}

void removeDuplicates(List*& L){
    Node* temp = L->head;
    while(temp != nullptr){
        Node* temp2 = temp;
        while(temp2->next != nullptr){
            if(temp2->next->data == temp->data){
                Node* del = temp2->next;
                temp2->next = temp2->next->next;
                delete del;
            }
            else{
                temp2 = temp2->next;
            }
        }
        temp = temp->next;
    }
}

bool removeElement(List*& L, int val){
    if(L->head == nullptr){
        return false;
    }
    if(L->head->data == val){
        removeHead(L);
        return true;
    }
    Node* temp = L->head;
    while(temp->next != nullptr){
        if(temp->next->data == val){
            Node* del = temp->next;
            temp->next = temp->next->next;
            delete del;
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main(){
    List* myList = nullptr;
    int choice;
    do {
        cout << "Menu:" << endl;
        cout << "1. Create a new list" << endl;
        cout << "2. Add an element to the head" << endl;
        cout << "3. Add an element to the tail" << endl;
        cout << "4. Add an element at a specific position" << endl;
        cout << "5. Add an element before a specific value" << endl;
        cout << "6. Add an element after a specific value" << endl;
        cout << "7. Remove the head element" << endl;
        cout << "8. Remove the tail element" << endl;
        cout << "9. Remove an element at a specific position" << endl;
        cout << "11. Remove an element before a specific value" << endl;
        cout << "12. Remove an element after a specific value" << endl;
        cout << "13. Print the list" << endl;
        cout << "14. Count the number of elements in the list" << endl;
        cout << "15. Reverse the list" << endl;
        cout << "16. Remove duplicates from the list" << endl;
        cout << "17. Remove a specific element from the list" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int data;
                cout << "Enter the data for the first element: ";
                cin >> data;
                Node* newNode = createNode(data);
                myList = createList(newNode);
                cout << "List created successfully!" << endl;
                break;
            }
            case 2: {
                int data;
                cout << "Enter the data for the new element: ";
                cin >> data;
                Node* newNode = createNode(data);
                addHead(myList, newNode);
                cout << "Element added to the head!" << endl;
                break;
            }
            case 3: {
                int data;
                cout << "Enter the data for the new element: ";
                cin >> data;
                Node* newNode = createNode(data);
                addTail(myList, newNode);
                cout << "Element added to the tail!" << endl;
                break;
            }
            case 4: {
                int data, pos;
                cout << "Enter the data for the new element: ";
                cin >> data;
                cout << "Enter the position to insert the element: ";
                cin >> pos;
                if (addPos(myList, data, pos)) {
                    cout << "Element added at position " << pos << "!" << endl;
                } else {
                    cout << "Invalid position!" << endl;
                }
                break;
            }
            case 5: {
                int data, val;
                cout << "Enter the value to insert the new element before: ";
                cin >> data;
                cout << "Enter the data for the new element: ";
                cin >> val;
                if (addBefore(myList, data, val)) {
                    cout << "Element added before " << data << "!" << endl;
                } else {
                    cout << "Value not found in the list!" << endl;
                }
                break;
            }
            case 6: {
                int data, val;
                cout << "Enter the value to insert the new element after: ";
                cin >> data;
                cout << "Enter the data for the new element: ";
                cin >> val;
                if (addAfter(myList, data, val)) {
                    cout << "Element added after " << data << "!" << endl;
                } else {
                    cout << "Value not found in the list!" << endl;
                }
                break;
            }
            case 7: {
                removeHead(myList);
                cout << "Head element removed!" << endl;
                break;
            }
            case 8: {
                removeTail(myList);
                cout << "Tail element removed!" << endl;
                break;
            }
            case 9: {
                int pos;
                cout << "Enter the position of the element to remove: ";
                cin >> pos;
                removePos(myList, pos);
                cout << "Element at position " << pos << " removed!" << endl;
                break;
            }
            case 11: {
                int data;
                cout << "Enter the value to remove the element before: ";
                cin >> data;
                removeBefore(myList, data);
                cout << "Element before " << data << " removed!" << endl;
                break;
            }
            case 12: {
                int data;
                cout << "Enter the value to remove the element after: ";
                cin >> data;
                removeAfter(myList, data);
                cout << "Element after " << data << " removed!" << endl;
                break;
            }
            case 13: {
                cout << "List: ";
                printList(myList);
                break;
            }
            case 14: {
                int count = countElements(myList);
                cout << "Number of elements in the list: " << count << endl;
                break;
            }
            case 15: {
                List reversedList = reverseList(myList);
                cout << "Reversed list: ";
                printList(&reversedList);
                break;
            }
            case 16: {
                removeDuplicates(myList);
                cout << "Duplicates removed from the list!" << endl;
                break;
            }
            case 17: {
                int val;
                cout << "Enter the value to remove from the list: ";
                cin >> val;
                if (removeElement(myList, val)) {
                    cout << "Element " << val << " removed!" << endl;
                } else {
                    cout << "Element not found in the list!" << endl;
                }
                break;
            }
            case 0: {
                removeAll(myList);
                cout << "List removed!" << endl;
                cout << "Exiting..." << endl;
                break;
            }
            default: {
                cout << "Invalid choice!" << endl;
                break;
            }
        }
    } while (choice != 0);

    return 0;
}