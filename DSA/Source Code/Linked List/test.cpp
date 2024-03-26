#include <iostream>


using namespace std;



struct toado{
    float x;
    float y;
};

struct node{
    node* next;
    toado *data;
};


node* print(node* head){
    node* tmp = head;
    while(tmp != nullptr){
        if(tmp->data->y == 3* tmp->data->x + 2){
            cout << tmp->data->x << " " << tmp->data->y << endl;
        }
        tmp = tmp->next;
    }
    return head;
}



int findNfromEnd(node*head, int n){
    if(head == 0 || head == nullptr){
        return -1;
    }

    node* main_ptr = head;
    node* ref_ptr = head;
    
    for(int i = 0; i < n-1 ; i++){
        if(ref_ptr == nullptr){
            return -1;
        }
        ref_ptr = ref_ptr->next;
    }
    
    while(ref_ptr->next != nullptr){
        main_ptr = main_ptr->next;
        ref_ptr = ref_ptr->next;
    }
    return main_ptr->data->x;
    
}