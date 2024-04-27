#include<iostream>
using namespace std;

class qnode{
public:
    int data;
    qnode* next;
    qnode(int d){
        data= d;
        next= nullptr;
    }
};

class queue{
public:
    qnode * front;
    qnode *rear;
    queue(){
        front= rear= nullptr;
    }

    void enqueue(int x){
        qnode* temp= new qnode(x);
        if(rear == nullptr){
            front= rear= temp;
            return;
        }
        rear->next= temp;
        rear= temp;
    }

    void dequeue(){
        if(front==nullptr){
            return;
        }
        qnode* temp= front;
        front= front->next;
        if(front==nullptr){
            rear= nullptr;
        }
        delete(temp);
    }

    int peek(){
        if(front == nullptr){
            cout << "Queue is empty." << endl;
            return -1; // Or you can throw an exception
        }
        return front->data;
    }
};

int main(){
    queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.dequeue();
    q.dequeue();
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    cout << "Queue Front: " << q.peek() << endl;
    return 0;
}
