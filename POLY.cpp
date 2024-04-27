#include <iostream>
using namespace std;
class Base {
public:
    virtual void a() { cout << "Base::a()" << endl; }
    void a(double ) { cout << "Base::a(double )" << endl; }
    void a(int ) { cout << "Base::a(int )" << endl; }
    virtual ~Base() {}
};

class Derived : public Base {
public:
    void a() { cout << "Derived::a()" << endl; }
};

int main() {
    Derived* dPtr = new Derived;
    dPtr->a();
    dPtr->Base::a(1.2);
    dPtr->Base::a(3);
    //!dPtr->a(1.2);
    //!dPtr->a(3);
    delete dPtr;
    Base* bPtr = new Derived;
    bPtr->a();
    bPtr->a(1.2);
    bPtr->a(3);
    delete bPtr;
}
