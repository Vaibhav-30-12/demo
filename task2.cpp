#include <iostream>
using namespace std;

// Base class
class Student {
        protected: int roll_number;
        public:
                   Student(int roll_number){
                           this->roll_number=roll_number;
                   }

};
class test:public Student{
        protected:
                float marks[4];
        public:
        
                test(int roll_number,float m1,float m2,float m3,float m4,float m5):Student( roll_number){
                    marks[0]=m1;
                    marks[1]=m2;
                    marks[2]=m3;
                    marks[3]=m4;
                    marks[4]=m5;

                }
// Derived class
};
class result:public test{
    public:
    result(int roll_number,float m1,float m2,float m3,float m4,float m5):test(roll_number, m1, m2, m3, m4, m5){}
    void display(){
        float total=0;
        for(int i=0;i<=4;i++){
            total+=marks[i];
        }
        float average=0;
        average=total/5;
        cout<<"the roll number of Student is"<<roll_number<<"\ntotal marks:"<<total<<"\naverage marks"<<average;


    }

};

int main() {
    int roll_no;
    cin>> roll_no;
    float m1,m2,m3,m4,m5;
    cin>>m1>>m2>>m3>>m4>>m5;


    result s1(roll_no,m1,m2,m3,m4,m5);
    s1.display();





    return 0;
}


// #include<iostream>
// using namespace std;
// class Sample {
// int x;
// public:
// Sample(){}
//  Sample(int n) : x(n) {}

//  Sample(Sample& Sam) { x = Sam.x; }
//  void showData() { cout << "x = " << x; }
// };
// class rational {
// private:
//     int numer;
//     int denom;

// public:
// rational(int n, int d) : numer(n), denom(d) {}
// const rational operator--(rational& r, int dummy)
// {
//  rational temp(r.numer,r.denom);
//  --r;
//  return temp;
// }};
// int main(){
//     rational obj(5, 2);
// obj--; // Invoking unary decrement operator


// }