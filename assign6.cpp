#include<iostream>

using namespace std;

class node{
    public:
    int data;
    node* next;

};

node* removeDuplicates(node* head){
    
    if(head==nullptr){
        return head;
    }
    node* current=head;
    while(current->next!=nullptr){
        if(current->data==current->next->data){
            node* temp=current->next;
            current->next=current->next->next;
            delete temp;
        }
        else{
            current=current->next;
        }

    }
    return head;

}
int getnfromlast(node* head,int n){
    if (head==nullptr){
        return -1;
    }
    node* slow=head;
    node* fast=head;
    for(int i=0;i<n;i++){
        if(fast==nullptr){
            return -1;
        }
        fast=fast->next;
    }
    while(fast!=nullptr){
        fast=fast->next;
        slow=slow->next;
    }
    return slow->data;
}
