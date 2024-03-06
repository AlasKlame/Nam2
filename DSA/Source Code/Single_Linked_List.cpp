#include<iostream>

using namespace std;


struct sinhvien{
    char name[50];
    int age;
    char gender[50];
    int code;
    float gpa;
};

struct node{
    node* next;
    sinhvien *data;
};



node* createNewNode(sinhvien* x){
    node* tmp = new node;
    tmp->data = x;
    tmp->next = nullptr;
    return tmp;
}


sinhvien *CreateSinhVien(){
    sinhvien *sv = new sinhvien;
    cin.ignore();
    cout << "Nhap ten: ";
    cin.getline(sv->name, 50);
    cout << "Nhap tuoi: ";
    cin >> sv->age;
    cin.ignore();
    cout << "Nhap gioi tinh: ";
    cin.getline(sv->gender, 50);
    cout << "Nhap ma so sinh vien: ";
    cin >> sv->code;
    cout << "Nhap diem trung binh: ";
    cin >> sv->gpa;
    return sv;
}

node* addElement(node* head, sinhvien* x){
    node* tmp = createNewNode(x);
    head->next = tmp;
    return tmp;
}

node* addNodeAtHead(node* head, sinhvien* x){
    node* tmp = createNewNode(x);
    if(head == nullptr){
        head = tmp;
    }else{
        tmp->next = head;
        head = tmp;
    }
    return head;
}


node* addNodeAtK(node* head, sinhvien* x, int k){
    node* tmp = createNewNode(x);
    if(k == 0){
        tmp->next = head;
        head = tmp;
    }else{
        node* p = head;
        for(int i = 0; i < k-1; i++){
            p = p->next;
        }
        tmp->next = p->next;
        p->next = tmp;
    }
    return head;
}

node* addAtTail(node* head,sinhvien* x){
    node* tmp = createNewNode(x);
    if(head == nullptr){
        head = tmp;
    }else{
        node* p = head;
        while(p->next != nullptr){
            p = p->next;
        }
        p->next = tmp;
    }
    return head;
}

node* sortGPA(node* head) {
    node* p = head;
    while (p != nullptr) {
        node* q = p->next;
        while (q != nullptr) {
            if (p->data->gpa < q->data->gpa) {
                sinhvien* tmp = p->data;
                p->data = q->data;
                q->data = tmp;
            }
            q = q->next;
        }
        p = p->next;
    }
    return head;
}

node* sortName(node* head){
    node* p = head;
    while(p != nullptr){
        node* q = p->next;
        while(q != nullptr){{
            if(q->data->name < p->data->name){
                sinhvien* tmp = p->data;
                p->data = q->data;
                q->data = tmp;
            }
        }
            q = q->next;
        }
        p = p->next;
    }
    return head;
}

void printList(node *l){
	node *p = l;
	while (p != NULL){
		cout << "Ten: " << p->data->name << endl;
        cout << "Tuoi: " << p->data->age << endl;
        cout << "Gioi tinh: " << p->data->gender << endl;
        cout << "Ma so sinh vien: " << p->data->code << endl;
        cout << "Diem trung binh: " << p->data->gpa << endl;
        p = p->next;
    }
    cout << endl;
}

int main(){
    int n;
    cin >> n;

    
    node* head = nullptr;
    node* tmp = head;
    for (int i = 0; i < n; i++) {
        sinhvien* sv = CreateSinhVien();
        if (i == 0) {
            head = createNewNode(sv);
            tmp = head;
        }
        else {
            tmp = addElement(tmp, sv);
        }
    }
    
    head = sortGPA(head);
    printList(head);

    return 0;
}