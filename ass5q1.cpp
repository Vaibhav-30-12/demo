
#include <iostream>

using namespace std;
class money{
    int rupees;
    int paise;
    public:
    money(){
        rupees=paise=0;

    }
    money(int r ,int p):rupees(r),paise(p){
        normalize();
    }
    money(money&m){
        rupees=m.rupees;paise=m.paise;
        m.normalize();
    }
    ~money(){}
    void print();
    void normalize();
    money operator +(money &);
    money operator -(money &);
    money& operator*=(int);
    money& operator /=(int);
};
void money::print(){
    cout<<"valuse is  "<<rupees<<"."<<paise<<endl;

}
void money::normalize(){
rupees +=paise/100;
paise %=100;
}

money money::operator+(money &m) {
    money temp;
    temp.rupees = this->rupees + m.rupees;
    temp.paise = this->paise + m.paise;
    temp.normalize();
    return temp;
}
money money ::operator - (money &m){
    money temp;
    temp.rupees=this->rupees-m.rupees;
    temp.paise=this->paise-m.paise;
    temp.normalize();
    return temp;

}
money& money ::operator*=(int num){
    rupees *=num;
    paise *=num;
    rupees +=paise/100;
    paise %=100;
    return *this;
}

money& money::operator /=(int num){
    int totalpaise=rupees *100 +paise;
    totalpaise/=num;
    rupees =totalpaise/100;
    paise=totalpaise%100;
    return *this;

}
int main(){
    money m1,m2(100,550);
    money m3(m2);
    m1.print();
    m2.print();
    m3.print();
    m1*=3;
    m2/=2;
    m1.print();
    m2.print();
}
//<iomanip> setw()setfill()