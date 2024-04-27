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
 };



 void insertnode(node* & tail, int element, int d){
   
    // empty list
    if(tail== nullptr){
        node* newnode=new node(d);
        tail= newnode;
        newnode->next=newnode;

    }
     // assuming that the element is present in the list
     //non empty list
     else{
        node* curr= tail;

        while(curr->data!=element){
            curr= curr->next;
            }

            //element found ->curr is reprsenting elemnt wala node
            node* temp= new node(d);
            temp->next= curr->next;
            curr->next=temp;
     }
     } 
 
void print(node* tail){
    node* temp= tail;
       if(tail == NULL) {
        cout << "List is Empty "<< endl;
        return ;
    }
    do{
        cout<<tail->data<<" ";
        tail= tail->next;
        
    }
    while(tail!= temp);
    cout<<endl;
}


void deletenode(node* & tail, int value){
  

    if(tail== nullptr){//empty list
        cout<<" list is empty , please check again.."<<endl;
        return;
    }
    else{
        node* prev= tail;
        node* curr= prev ->next;
        while(curr->data!=value){
            prev= curr;
            curr= curr->next;
        }


        prev->next= curr->next;
        if(tail== curr){
            tail=prev; 
        }
        curr->next= nullptr;
        delete curr;



    }
}
 int main()
 {
   node* tail = NULL;

   insertnode(tail, 5, 3);
    print(tail);

   insertnode(tail, 3, 5);
   print(tail);
    insertnode(tail, 5, 7);
    print(tail);
    deletenode(tail,3);
    print(tail);
    }