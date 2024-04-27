#include<iostream>

using namespace std;

class node{
    public:
    node* prev;
    node* next;
    int data;

    node(int data){
        this->data=data;
        this->prev=nullptr;
        this->next=nullptr;
    }
};

node* sortedinsert(node* head,int x){
    node* newnode=new node(x);

    if(head==nullptr){return newnode;}

    if(x<head->data){
        newnode->next=head;
        head->prev=newnode;
        return newnode;

    }

    node* current=head;


    while(current->next!=nullptr && current->next->data<x){current=current->next;
    }

    newnode->next=current->next;
    current->next->prev=newnode;
    current->next=newnode;
    newnode->prev=current;
    return head;

}


void printList(node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}