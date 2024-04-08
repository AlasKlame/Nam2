#include<iostream>
using namespace std;

struct Sach {
    char id[50];
    char name[50];
    int year;
    float cost;
    float discount  ;
};

// Cấu trúc Node
struct Node{
    Sach data;
    Node* next;
};


Sach input(){
    Sach s;
    cin.ignore();
    cin.getline(s.id, 50);
    cin.getline(s.name, 50);
    cin >> s.year;
    cin >> s.cost;
    cin >> s.discount;
    s.discount = s.discount / 100;
    return s;
}

Node* createNode(Sach data){
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}
void addNode(Node* &head, Sach data){
    if(head == nullptr){
        head = createNode(data); 
        return;
    }
    Node* newNode = createNode(data);
    Node* tmp = head;
    while(tmp->next != nullptr){
        tmp = tmp->next;
    }
    tmp->next = newNode;
}

int count(Node* head){
    if(head == nullptr){
        return 0;
    }
    Node* tmp = head;
    int count = 0;
    while(tmp != nullptr){
        float costAfterDiscount = tmp->data.cost - tmp->data.discount * tmp->data.cost;
        if(costAfterDiscount <= 50000){ 
            count++;
        }
        tmp = tmp->next;
    }
    return count;
}

void print(Node* head){
    if(head == nullptr){
        cout << "Danh sach rong" << endl;
        return;
    }
    Node* tmp = head;
    while(tmp != nullptr){
        float costAfterDiscount = tmp->data.cost - tmp->data.discount * tmp->data.cost;
        cout << "ID: " << tmp->data.id << endl;
        cout << "Ten: " << tmp->data.name << endl;
        cout << "Nam xuat ban: " << tmp->data.year << endl;
        cout << "Gia: " << tmp->data.cost << endl;
        cout << "Giam gia: " << tmp->data.discount << endl;
        cout << "Gia gia: " << costAfterDiscount << endl;
        tmp = tmp->next;
    }
}

int main() {
    Sach s;
    Node* l = nullptr;
    int n;

    freopen("input.txt", "r", stdin);

   
    
    cin >> n;

    for (int i = 0; i < n; i++) {
        s = input();
        addNode(l, s);
    }

    freopen("output.txt", "w", stdout);

    print(l);

    fclose(stdin);
    return 0;
}
