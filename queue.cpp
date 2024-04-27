/*
queue dta structure iis a fundamental concept in
 cs which follows the principle of
"FIRST IN ,FIRST OUT(FIFO)"
where the first element added to queeue is the first one 
to be removed.


*/
#include<iostream>

using namespace std;

class queue{
    int * arr;
    int front;
    int rear;
    int size;
    public:
    queue(){
        size=100001;
        arr= new int[size];
        front=0;
        rear=0;
    }
    void enqueue(int data){
        if(rear==size){
            cout<<"queue is full"<<endl;
        }
        else{
            arr[rear]=data;
            rear++;
        }
    }

    int dequeue(){
        if(front== rear){
            return -1;
        }
        else{
            int ans= arr[front];
            arr[front]=-1;
            front++;
            if(front== rear){
                front=0;
                rear=0;
            }
            return ans;
        }
    }
    int qfront(){
        if(front== rear){
            return -1;
        }
        else{
            return arr[front];
        }
    }

    bool isempty(){
        if(front== rear){
            return true;
        }
        else
        {
            return false;
        }

    }
};

