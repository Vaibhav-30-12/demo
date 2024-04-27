#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* prev;
    node* next;

    node(int d){
        this->data=d;
        this->next=NULL;
        this->prev=NULL;

    }

};
void print(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<< " ";
        temp=temp=temp->next; 
    }
    cout<<endl;
}

int getlength(node* head){
    int len=0;
    node*temp=head;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }

    return len;
}
void insertathead(node* &tail,node* &head,int data){
    if(head==nullptr){
        node* temp=new node(data);// for empty list
        head=temp;
        tail=temp;

    }
    else{

    
    node* temp= new node(data);
    temp->next= head;
    head ->prev=temp;
    head= temp;
    }
}
void insertattail( node* &tail,node* &head,int d){
      if(tail==nullptr){
        node* temp=new node(d);// for empty list
        tail=temp;
        head=temp; 

    }
    else{
    node* temp= new node(d);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}}

void insertatposition(node* &tail,node* &head,int position,int d){
    if (position==1){
        insertathead(tail,head,d);
        return;
    }
    node* temp= head;
    int cnt=1;
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }

    if(temp->next==NULL){
        insertattail(tail,head,d);
        return;
    }
    node* nodetoinsert= new node(d);
    nodetoinsert->next=temp->next;
    temp->next->prev=nodetoinsert;
    temp->next=nodetoinsert;
    nodetoinsert->prev=temp;


}



int main(){
    node* node1=new node(10);
    node* head=node1;
    node* tail=node1;
     
    print(head);
    cout<<getlength(head)<<endl;

    insertathead(tail,head,11);
    print(head);
    insertathead(tail,head,12);
    print(head);
    insertathead(tail,head,13);
    print(head);
    insertattail(tail,head,9);
    print(head);
    cout<<getlength(head)<<endl;

    insertatposition(tail,head,3,100);
    print(head);
    insertatposition(tail,head,1,101);
    insertatposition(tail,head,8,69);
    print(head);
    
    return 0;}