#include<iostream>

using namespace std;

struct DNode {
    int data;
    DNode* pNext;
    DNode* pPrev;
};

struct DList {
    DNode* pHead;
    DNode* pTail;
};



DNode *createDNode(int data) {
    DNode *p = new DNode;
    if (p == NULL) {
        return NULL;
    }
    p->data = data;
    p->pNext = NULL;
    p->pPrev = NULL;
    return p;
}


DList *createList(DNode *pNode){
    DList *pList = new DList;
    if (pList == NULL) {
        return NULL;
    }
    pList->pHead = pNode;
    pList->pTail = pNode;
    return pList;
}

bool addHead(DList*& L, int data){
    DNode *p = createDNode(data);
    if (p == NULL) {
        return false;
    }
    if (L->pHead == NULL) {
        L->pHead = p;
        L->pTail = p;
    } else {
        p->pNext = L->pHead;
        L->pHead->pPrev = p;
        L->pHead = p;
    }
    return true;
}

bool addTail(DList*& L, int data){
    DNode *p = createDNode(data);
    if (p == NULL) {
        return false;
    }
    if (L->pHead == NULL) {
        L->pHead = p;
        L->pTail = p;
    } else {
        L->pTail->pNext = p;
        p->pPrev = L->pTail;
        L->pTail = p;
    }
    return true;
}


bool addPos(DList*& L, int data, int pos){
    if (pos < 0) {
        return false;
    }
    if (pos == 0) {
        return addHead(L, data);
    }
    DNode *p = L->pHead;
    int k = 0;
    while (p != NULL && k != pos) {
        p = p->pNext;
        k++;
    }
    if (k != pos) {
        return false;
    }
    if (p == NULL) {
        return addTail(L, data);
    }
    DNode *q = createDNode(data);
    if (q == NULL) {
        return false;
    }
    q->pNext = p;
    q->pPrev = p->pPrev;
    p->pPrev->pNext = q;
    p->pPrev = q;
    return true;
}


bool addBefore(DList *&L, int data, int x){
    DNode *p = L->pHead;
    while (p != NULL && p->data != x) {
        p = p->pNext;
    }
    if (p == NULL) {
        return false;
    }
    DNode *q = createDNode(data);
    if (q == NULL) {
        return false;
    }
    q->pNext = p;
    q->pPrev = p->pPrev;
    p->pPrev->pNext = q;
    p->pPrev = q;
    return true;
}

bool addAfter(DList *&L, int data, int x){
    DNode *p = L->pHead;
    while (p != NULL && p->data != x) {
        p = p->pNext;
    }
    if (p == NULL) {
        return false;
    }
    DNode *q = createDNode(data);
    if (q == NULL) {
        return false;
    }
    q->pNext = p->pNext;
    q->pPrev = p;
    p->pNext->pPrev = q;
    p->pNext = q;
    return true;
}

void removeHead(DList *&L){
    if (L->pHead == NULL) {
        return;
    }
    DNode *p = L->pHead;
    L->pHead = L->pHead->pNext;
    if (L->pHead == NULL) {
        L->pTail = NULL;
    } else {
        L->pHead->pPrev = NULL;
    }
    delete p;
}

void removeTail(DList *&L){
    if (L->pHead == NULL) {
        return;
    }
    DNode *p = L->pTail;
    L->pTail = L->pTail->pPrev;
    if (L->pTail == NULL) {
        L->pHead = NULL;
    } else {
        L->pTail->pNext = NULL;
    }
    delete p;
}

void removePos(DList *&L, int pos){
    if (pos < 0) {
        return;
    }
    if (pos == 0) {
        removeHead(L);
        return;
    }
    DNode *p = L->pHead;
    int k = 0;
    while (p != NULL && k != pos) {
        p = p->pNext;
        k++;
    }
    if (p == NULL) {
        return;
    }
    if (p == L->pTail) {
        removeTail(L);
        return;
    }
    p->pPrev->pNext = p->pNext;
    p->pNext->pPrev = p->pPrev;
    delete p;
}

void removeAll(DList *&L){
    while (L->pHead != NULL) {
        removeHead(L);
    }
}


void removeBefore(DList *&L, int x){
    DNode *p = L->pHead;
    while (p != NULL && p->data != x) {
        p = p->pNext;
    }
    if (p == NULL || p->pPrev == NULL) {
        return;
    }
    DNode *q = p->pPrev;
    if (q == L->pHead) {
        removeHead(L);
        return;
    }
    q->pPrev->pNext = p;
    p->pPrev = q->pPrev;
    delete q;
}

void removeAfter(DList *L, int x){
    DNode *p = L->pHead;
    while (p != NULL && p->data != x) {
        p = p->pNext;
    }
    if (p == NULL || p->pNext == NULL) {
        return;
    }
    DNode *q = p->pNext;
    if (q == L->pTail) {
        removeTail(L);
        return;
    }
    p->pNext = q->pNext;
    q->pNext->pPrev = p;
    delete q;
}

void printList(DList *L){
    DNode *p = L->pHead;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->pNext;
    }
    cout << endl;
}


int countElements(DList *L){
    DNode *p = L->pHead;
    int count = 0;
    while (p != NULL) {
        count++;
        p = p->pNext;
    }
    return count;
}

DList *reverseList(DList *L){
    DList *pList = createList(NULL);
    DNode *p = L->pTail;
    while (p != NULL) {
        addTail(pList, p->data);
        p = p->pPrev;
    }
    return pList;
}

void removeDuplicate(DList *&L){
    DNode *p = L->pHead;
    while (p != NULL) {
        DNode *q = p->pNext;
        while (q != NULL) {
            if (q->data == p->data) {
                DNode *t = q;
                q = q->pNext;
                if (t == L->pTail) {
                    removeTail(L);
                } else {
                    t->pPrev->pNext = t->pNext;
                    t->pNext->pPrev = t->pPrev;
                    delete t;
                }
            } else {
                q = q->pNext;
            }
        }
        p = p->pNext;
    }
}

bool removeElement(DList *&L, int val){
    DNode *p = L->pHead;
    while (p != NULL && p->data != val) {
        p = p->pNext;
    }
    if (p == NULL) {
        return false;
    }
    if (p == L->pHead) {
        removeHead(L);
    } else if (p == L->pTail) {
        removeTail(L);
    } else {
        p->pPrev->pNext = p->pNext;
        p->pNext->pPrev = p->pPrev;
        delete p;
    }
    return true;
}


int main(){
    DList *list = createList(NULL);
    int choice;
    do {
        cout << "Menu:" << endl;
        cout << "1. Add element to the head" << endl;
        cout << "2. Add element to the tail" << endl;
        cout << "3. Add element at a specific position" << endl;
        cout << "4. Add element before a specific value" << endl;
        cout << "5. Add element after a specific value" << endl;
        cout << "6. Remove element from the head" << endl;
        cout << "7. Remove element from the tail" << endl;
        cout << "8. Remove element at a specific position" << endl;
        cout << "9. Remove element before a specific value" << endl;
        cout << "10. Remove element after a specific value" << endl;
        cout << "11. Print the list" << endl;
        cout << "12. Count the number of elements in the list" << endl;
        cout << "13. Reverse the list" << endl;
        cout << "14. Remove duplicate elements from the list" << endl;
        cout << "15. Remove a specific element from the list" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int data;
                cout << "Enter the element to add: ";
                cin >> data;
                addHead(list, data);
                break;
            }
            case 2: {
                int data;
                cout << "Enter the element to add: ";
                cin >> data;
                addTail(list, data);
                break;
            }
            case 3: {
                int data, pos;
                cout << "Enter the element to add: ";
                cin >> data;
                cout << "Enter the position to add: ";
                cin >> pos;
                addPos(list, data, pos);
                break;
            }
            case 4: {
                int data, value;
                cout << "Enter the element to add: ";
                cin >> data;
                cout << "Enter the value to add before: ";
                cin >> value;
                addBefore(list, data, value);
                break;
            }
            case 5: {
                int data, value;
                cout << "Enter the element to add: ";
                cin >> data;
                cout << "Enter the value to add after: ";
                cin >> value;
                addAfter(list, data, value);
                break;
            }
            case 6: {
                removeHead(list);
                break;
            }
            case 7: {
                removeTail(list);
                break;
            }
            case 8: {
                int pos;
                cout << "Enter the position to remove: ";
                cin >> pos;
                removePos(list, pos);
                break;
            }
            case 9: {
                int value;
                cout << "Enter the value to remove before: ";
                cin >> value;
                removeBefore(list, value);
                break;
            }
            case 10: {
                int value;
                cout << "Enter the value to remove after: ";
                cin >> value;
                removeAfter(list, value);
                break;
            }
            case 11: {
                printList(list);
                break;
            }
            case 12: {
                int count = countElements(list);
                cout << "Number of elements in the list: " << count << endl;
                break;
            }
            case 13: {
                DList *reversed = reverseList(list);
                cout << "Reversed list: ";
                printList(reversed);
                removeAll(reversed);
                delete reversed;
                break;
            }
            case 14: {
                removeDuplicate(list);
                break;
            }
            case 15: {
                int value;
                cout << "Enter the value to remove: ";
                cin >> value;
                bool removed = removeElement(list, value);
                if (removed) {
                    cout << "Element removed successfully" << endl;
                } else {
                    cout << "Element not found in the list" << endl;
                }
                break;
            
            }
            case 0: {
                removeAll(list);
                delete list;
                break;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    } while (choice != 0);

    return 0;
}

