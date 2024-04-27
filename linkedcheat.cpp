# include<iostream>
 
using namespace std;
 class node{
    public:
    int data;
    node* next;
 //constructor
node(int data){
    this->data=data;
    this->next=nullptr;
}
//destructor
~node(){
    int value=this->data;
    if(this->next!=nullptr){
        delete next;
        this-> next=nullptr;
    }
    cout<<" memory is free for node with data "<< value<<endl;

}
}
;


int getlength(node*head){
    int len=0;
    while(head!=nullptr){
        len++;
        head=head->next;
    }
    return len;  
}

node* findmiddlenode(node* head){
    int length= getlength(head);
    int ans= (length/2);
    node* temp=head;
    int cnt=0;
    while(cnt<ans){
        temp= temp->next;
        cnt++;
    }
    return temp;
}

node* middle2(node* head){
    if (head==nullptr){
        return nullptr;
    }
    if(head->next==nullptr){
        return nullptr;
    }
    if(head->next->next==nullptr){
        return head->next;
    }

    node* slow= head;
    node* fast= head->next;
    while(fast!= nullptr){
        fast= fast->next;
        if(fast->next!=nullptr){
            fast= fast->next;
        }
        slow= slow->next;
    }
    return slow;
}



node* reverselinked1(node * head){//iteravtive solution 1
//TC=O(n)
//SC=O(1)
    if (head==nullptr || head->next==nullptr){
        return head;// empty list  and single node ka case h ye smjhe na tum
    }

    node* prev= nullptr;
    node* curr= head;
    node* forward=nullptr;
    while(curr!=nullptr){
        forward= curr->next;
        curr->next=prev;
        prev= curr;
        curr= forward;
    }
    return prev;
}
//reccursive solution

void reverse(node* & head,node* curr,node* prev ){
    // base case
    if(curr==NULL){
        head=prev;
        return;
    }

    node* forward =curr->next;
    reverse(head, forward,curr);
    curr->next=prev;
    
    }
//it will return head of reversed list

    node* reverse3(node * head){
        if(head==nullptr|| head->next==nullptr){
            return head;
        }
        node* chotahead= reverse3(head->next);
    head->next->next=head;
    head->next= nullptr;
    return chotahead;
    }
    


void insertathead(node* &head,int d){// reference so that changes made get implemented in real

    //new node create 
    node* temp=new node(d);
    temp->next=head;
    head= temp;
}
void insertattail(node* &tail,int d){
    node* temp= new node(d);
    tail-> next= temp;
    tail= temp;

}
void insertatposition(node* & head,node* &tail, int position, int d){
    if (position==1){
        insertathead(head,d);
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
        insertattail(tail,d);
        return;
    }

    // creating a node for d
    node* nodetoinsert= new node(d);
    nodetoinsert->next= temp->next; 
    temp->next= nodetoinsert;

}
 
 void print(node* & head){
    node* temp= head;
    while ( temp!=NULL){
        cout<< temp->data<<"  ";
        temp= temp->next;
            }
            cout<<endl;
 }


void deletenode(int position, node*& head){
    if (position==1){// deleting the first or start node
    node* temp= head;
    head= head->next;
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
        prev->next=curr->next;
        curr->next=nullptr;
        delete curr;
        
        }



}


 int main(){
    
    node* node1= new node(10);
    
    cout<<node1->data<<endl;
   cout<<node1->next<<endl;

    //head pointefd to node 1
    node* head = node1;
    node* tail= node1;
    print(head);

    insertattail(tail,12);
    insertatposition(head,tail,2,13);
    insertatposition(head,tail,1,9);
     print(head);
     head=reverselinked1(head);
     print(head);
   deletenode(1,head);
   print(head);
    
 }