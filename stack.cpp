#include<iostream>

#include<stack>
using namespace std;



class Stack{
    //propertieszz
    public:

    int top;
    int * arr;
    int size;

    Stack(int size){
        this->size=size;
        arr=new int [size];
        top=-1;
        }


    void push(int element){
        if(size-top>1){
            top++;
            arr[top]=element;
        }
        else{
            cout<<"stack overflow ..."<<endl;
        }
    }
        void pop(){
            if(top>=0){
                top--;
            }
            else{
                cout<<"stackunderflow"<<endl;
            }
        }
                    
    int peek(){
        if(top>=0)
        return arr[top];
        else{
            cout<<"stack is empty"<<endl;
            return -1;
        }
    }

    bool isempty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }
    }  
;

int main(){
    // stack<int> s1;


    // s1.push(1);
    // s1.push(2);

    // s1.pop();

    // cout<< "printing top element    :  "<< s1.top()<<endl;


    // if(s1.empty()){

    //     cout<<"stack is empty"<<endl;
    // }
    // else{
    //     cout<<"stack is not emptyY"<<endl;
    // }
 
    // cout<<"the size of stack is  : "<<s1.size()<<endl;


    Stack st(5);
    st.push(22);
    st.push(34);
    st.push(77);
    cout<<st.peek()<<endl;

    st.pop();
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;

    if(st.isempty()){
        cout<<"stack is empty"<<endl;

    }
    else{
        cout<<" stack is not empty"<<endl;
    }




    
    }



    class twostack{
        private:
        int * arr;
        int top1;
        int top2;
        int size;

        public:

        twostack(int s){
            this->size= s;
            top1=-1;
            top2=s;
            arr= new int [s];
        }
        void push1(int num){
            if (top2-top1>1){
                // atleast 1 empty sapce is present
                top1++;
                arr[top1]=num;
            }
            else{
                cout<<"stack overflow"<<endl;
            }

        }
        void push2 (int num){
            if(top2- top1>1){
                top2--;
                arr[top2]=num;
            }
            else{
                cout<<"stack overflow   .."<<endl;
            }
        }
        int pop1(){
            if(top1>=0){
                int ans=arr[top1];
                top1--;
                return ans;
            }
            else{
                return -1;
            }
        }

        int pop2(){
                if(top2<size){
                int ans=arr[top2];
                top2++;
                return ans;
            }
            else{
                return -1;
            }

        }

    }; 