#include<iostream>


using namespace std;


class node{public:
    int data;
    node* prev;
    node* next;
       node(int d){
        this->data=d;
        this->next=NULL;
        this->prev=NULL;

    }


};

class Deque{
    node* front;
    node* rear;
    int Size;
    public:
    Deque()
    {
        front=rear=nullptr;
        Size=0;
    }



       void insertFront(int data);
    void insertRear(int data);
    void deleteFront();
    void deleteRear();
    int getFront();
    int getRear();
    int size();
    bool isEmpty();
    void erase();
    void print();
};


int Deque::size(){
    return Size;
}
bool Deque:: isEmpty()
{
    return (front==nullptr);
}


void Deque:: insertFront(int data){
    node * newnode= new node(data);
    if (newnode==nullptr){
        cout<<"overflow "<<endl;
    }
    else{
        if(front==nullptr){
            rear=front=newnode;
        }
        else{
            newnode->next=front;
            front->prev=newnode;
            front=newnode;
        }
        Size++;
         }

}

void Deque::insertRear(int data)
{
    node* newnode=new node(data);
    if(newnode==nullptr){
        cout<<"overflowwwww.."<<endl;
    }
    else{
        if(rear==nullptr){
            front=rear= newnode;
        }
        else{
            newnode->prev=rear;
            rear->next=newnode;
            rear=newnode;
        }
        Size++;
    }
}

void Deque::deleteFront(){
    if(isEmpty()){
        cout<<"underflowww..."<<endl;
    }
    else{
        node* temp=front;
        front= front->next;
        if(front==nullptr){
            rear=nullptr;
        }
        else{
            front->prev=nullptr;
            free(temp);
        }
        Size--;
    }
}

void Deque:: deleteRear()
{
    if(isEmpty()){
        cout<<"underflow  ... "<<endl;
    }

    else{
        node* temp=rear;
        rear=rear->prev;
        if(rear==nullptr){
            front=nullptr;
        }

        else{
            rear->next=nullptr;
            
        }
        free(temp);
        Size--;
    }
}



int Deque::getFront()
{
    if(isEmpty()){
        return -1;
        }
    return front->data;
}

int Deque::getRear()
{
    if(isEmpty()){
        return -1;
    }
    return rear->data;
}


void Deque::erase()
{
    rear=nullptr;
    while(front!=nullptr){
        node* temp=front;
        front=front->next;
        free(temp);
    }

    Size=0;
}

void Deque:: print()
{node* temp= front;
    while(temp!=nullptr){
        cout<<temp->data<<endl;
        temp= temp->next;
    }
}



int main() {
    Deque dq;

    cout << "Inserting elements at front...\n";
    dq.insertFront(10);
    dq.insertFront(20);
    dq.insertFront(30);
    dq.print(); // Should print 30, 20, 10

    cout << "\nInserting elements at rear...\n";
    dq.insertRear(40);
    dq.insertRear(50);
    dq.insertRear(60);
    dq.print(); // Should print 30, 20, 10, 40, 50, 60

    cout << "\nSize of deque: " << dq.size() << endl;

    cout << "\nDeleting element from front...\n";
    dq.deleteFront();
    dq.print(); // Should print 20, 10, 40, 50, 60

    cout << "\nDeleting element from rear...\n";
    dq.deleteRear();
    dq.print(); // Should print 20, 10, 40, 50

    cout << "\nFront element: " << dq.getFront() << endl; // Should print 20
    cout << "Rear element: " << dq.getRear() << endl; // Should print 50

    cout << "\nClearing deque...\n";
    dq.erase();
    dq.print(); // Should not print anything as deque is cleared

    cout << "\nSize of deque after clearing: " << dq.size() << endl; // Should print 0

    return 0;
}

