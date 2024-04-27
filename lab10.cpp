#include <iostream>
using namespace std;

class node{
        node* next;
        int data;
public:
        node(){}
        node (int data){
                this->data=data;
                this->next=NULL;

        }

        void insertnode(node* &head, int d);
        bool findnode(node* &head,int d);
        void printlist(node* &head);
        void deletenode(int position, node* &head);
        void insert_at_head(node* &head, int d);
        void insert_at_tail(node* &tail, int d);
        void insert_at_position(node* &head,node* & tail, int position, int d);
            
};


void node::printlist(node * &head){
        node *temp=head;

        while(temp!=NULL){
                cout<<temp->data<<"  ";
                temp=temp->next;
        }
        cout<<endl;
}

void node ::insert_at_head(node* &head,int d){
         node* temp = new node(d);
         temp -> next = head;
         head = temp;

}
void node ::insert_at_tail(node* &tail,int d){
        node* temp=new node(d);
        tail->next=temp;
        tail=temp;
}


void node::insert_at_position(node* &head,node* & tail,int position,int d){
        node* temp=head;
        if (position==1){
                insert_at_head(head,d);
                return;
        }
        int count=0;
        while(count<position-1){
                temp=temp->next;
                count++;}
        if(temp->next==NULL){
                insert_at_tail(tail,d);
                return;}
        node* nodetoinsert=new node(d);
        nodetoinsert->next=temp->next;
        temp->next=nodetoinsert;}







bool node ::findnode(node* &head,int n){
        node * temp=head;
        int curr=0;
        while(temp!=0){
                if(temp->data==n){
                        return true;}
                temp=temp->next;
        }
        return false;
}


void node::deletenode(int position,node* &head){
        if(position==1){
                node* temp=head;
                head=head->next;
                delete temp;
        }

      else
        {
                node* curr=head;
                node* prev=NULL;

                int cnt=1;

                while (cnt<position){
                        prev=curr;
                        curr=curr -> next;
                        cnt++;
                }
                prev->next=curr->next;

                delete curr;
        }
}


int main() {
  node *head =new node(1);

    // Inserting nodes
    head->insert_at_head(head, 10);
        // head->insert_at_tail(tail, 20);
        // head->insert_at_position(head, tail, 2, 15); // Inserting 15 at position 2

    // Printing the list
    head->printlist(head);

    

    return 0;
}
                