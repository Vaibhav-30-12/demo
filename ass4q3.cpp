#include<iostream>
#include<string>
#include <string.h>
using namespace std;

class lastword{
    string in;
    public:
    lastword(){}
    lastword( string st):in(st){
        

    }
    void get_last_word(){

    int len=in.length();
    string temp;
    for(int i=len-1,x=0;i>=0;i--,x++){
        if(isspace(in[i])){
            break;
        }
        else{
            temp=in[i]+temp;
        }
        
    }
    int m=temp.length();
        cout<<"the size is "<<m<<endl;
        cout<<"the string is "<<temp;
    };
};

int main(){
    lastword s("hi guys chai pilo");
    s.get_last_word();
    
}