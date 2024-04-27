#include<iostream>
using namespace std;

#include<stack>


class   Queue{
    stack <int> s1,s2;
    public:
    void enqueue(int);//adds an element to the queue
    int dequeue();// removes the front most element , and gives its value
    int front();// gives you the front elemnt's value
};

void    Queue::enqueue(int value){
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
    s1.push(value);
    while(s2.empty()!=0){
        s1.push(s1.top());
        s2.pop();
    }
}

int Queue::dequeue(){
       
}
int main(){

    stack<int> s2;
    Queue s1;
    s1.enqueue(12);
    s1.enqueue(13);
    s2.push(14);
    s2.push(15);

    
    return 0;


}