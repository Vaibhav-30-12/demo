#include<iostream>
using namespace std;
#include<cmath>

class point{
    double x;
    double y;
    public:
    public:
    point(){
        x=y=0;
    }
    point(double x1,double y1):x(x1),y(y1){}

    double distance(point other){
        double temp;
        temp=sqrt(pow(x-other.x,2)+pow(y-other.y,2));
        return temp;
    }
};
int main(){
    point p1(3,4);
    point p2(6,8);

    double dis=p1.distance(p2);
    cout<<dis;
}