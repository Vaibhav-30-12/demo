#include<iostream>
#include<string>
using namespace std;
template<class T>
class addelements{
    T element1;
    T element2;
    public:
    addelements(T e1,T e2):element1(e1),element2(e2){}
    T add(){
        return element1+element2;
    }

};
template<>
class addelements<string>{
    string element1;
    string element2;
    public:
    addelements(string e1,string e2):element1(e1),element2(e2){}

    string concatenate(){
        return element1+element2;
    }

};
int main(){
    addelements<int> intadd(3,5);
    cout<<intadd.add()<<endl;

    addelements<float> floatadd(3.5,5.5);
    cout<<floatadd.add()<<endl;

    addelements<string> stringcon("hello ","chai pilo chalo");
    cout<<stringcon.concatenate()<<endl;
    }