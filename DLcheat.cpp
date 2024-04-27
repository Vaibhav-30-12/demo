#include<iostream>

using namespace std;

class node{
    public:
    int data;
    node* prev;
    node* next;

    //constructor 
    node(int d){
        this->data=d;
        this->prev=nullptr;
        this->next=nullptr;
    }
    ~node(){

        int value= this->data; 
        if(next!=nullptr){
            delete next;
            next= nullptr;
        }
        cout<<" memory free for node with data"<< value<<endl;
    }

};
// gives length of linked list
int getlength(node* head){
    int len=0;
    node* temp= head;
    while (temp!= nullptr)
    {    len++;
        temp= temp->next;
    
    }
    return len;
    
}
//traversing a linked list
void print(node* head){
    node* temp= head;
    while ( temp!= nullptr){
        cout<< temp->data<<"    ";
        temp=temp->next;
    }
    cout<<endl;
}



void insertathead(node* & tail,node* & head, int d){

    if (head==nullptr){
        node* temp= new node(d);
        head= temp;
        tail= temp;
    }
    else{    node* temp= new node(d);
    temp->next= head;
    head->prev= temp;
    head= temp;
}
}
void insertattail(node* & head,node* & tail, int d){
    
    if (tail==nullptr){
        node* temp= new node(d);
        head= temp;
        tail= temp;
    }
    node* temp= new node(d);
    tail->next= temp;
    temp->prev= tail;
    tail=temp;
}
void insertatposition(node* & head,node* &tail, int position, int d){
    if (position==1){
        insertathead(tail,head,d);
        return;
}
    node* temp= head;
    int cnt=1;
    while(cnt<position-1){
        temp= temp->next;
        cnt++;
    }
    //inserting at last position
    if (temp->next==nullptr){
        insertattail(tail,head,d);
        return;
    }

    // creating a node for d
    node* nodetoinsert= new node(d);
    nodetoinsert->next= temp->next; 
    temp->next->prev=nodetoinsert;
    temp->next= nodetoinsert;
    nodetoinsert->prev= temp;

}




void deletenode(int position, node*& head){
    if (position==1){// deleting the first or start node
    node* temp= head;
    temp->next->prev=nullptr;
    head= temp->next;
    temp->next=nullptr;
    delete temp;
    }
    else{
        node* curr= head;
        node* prev= nullptr;
        int cnt=1;
        while(cnt<position){
            prev= curr;
            curr= curr->next;
            cnt++;

        }
       
       curr->prev= nullptr;
       prev->next= curr->next;
       curr->next= nullptr;
        delete curr;
        
        }



}
int main(){
    node * node1= new node(10);
    node*tail= node1;
    node* head= node1;

    print( head);
    //cout<< getlength(head)<<endl;

    insertathead(tail,head,11);
    print(head);

    insertathead(tail,head,12);
    print(head);

    insertathead(tail,head,13);
    print(head);
    insertattail(head,tail,19);
    print(head);

    insertatposition(head,tail,2,100);
    print(head);
    deletenode(1, head);
    print(head);
    deletenode(2,head);
    print(head);
    deletenode(4,head);
    print(head);
}