#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* link;

   
    node(int x){
        data=x;
        link= nullptr;
    }
};

class Stack{

    private:
    node* top;
    public:
    Stack(){
        top= nullptr;
    }
    void push (int data){
        node* temp= new node(data);
        if(!temp){
            cout<<" stack overflow"<<endl;
            exit(1);
        }
        temp->data=data;
        temp->link= top;
        top= temp;      
    }

    void pop( ){
        node* temp;

        if( top==nullptr){
            cout<<"stack underflow "<<endl;
            exit(1);
        }
        else{
            temp=top;
            top= top->link;
            free( temp);
        }


    }

    bool isempty(){
        return top==nullptr;
    }
     int peek(){
        if(!isempty()){
            return top->data;
        }
        else
        exit(1);
     }

    void display(){
        node* temp;
        if(top==nullptr){
            cout<<"stack underflow";
            exit(1);
        }
        else{

            temp= top;
            while(temp!=nullptr){
                cout<< temp->data;
                temp= temp->link;
                if(temp!=nullptr){
                    cout<<" - > ";
                }
            }
        }
    }
};
int main()
{
    // Creating a stack
    Stack s;
 
    // Push the elements of stack
    s.push(11);
    s.push(22);
    s.push(33);
    s.push(44);
 
    // Display stack elements
    s.display();
 
    // Print top element of stack
    cout << "\nTop element is " << s.peek() << endl;
 
    // Delete top elements of stack
    s.pop();
    s.pop();
 
    // Display stack elements
    s.display();
 
    // Print top element of stack
    cout << "\nTop element is " << s.peek() << endl;
 
    return 0;
}