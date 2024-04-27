#include <iostream>

using namespace std;

class Shape {
public:
    virtual void draw() = 0;
    virtual ~Shape() { cout << "~Shape()" << endl; }
};

class Circle : public Shape {
public:
Circle(){}
    void draw() { cout << "Circle::draw()" << endl; }
    ~Circle() { cout << "~Circle()" << endl; }
};

class Square : public Shape {
public:
Square(

)
{}    void draw() { cout << "Square::draw()" << endl; }
    ~Square() { cout << "~Square()" << endl; }
};

class Triangle : public Shape {
public:
Triangle(){}
    void draw() { cout << "Triangle::draw()" << endl; }
    ~Triangle() { cout << "~Triangle()" << endl; }
};

int main() {

    
    Shape *s1[2] = {new Circle, new Square, new Triangle};

    for (size_t i = 0; i < sizeof(s1) / sizeof(*s1); i++)
        s1[i].draw();

    for (size_t i = 0; i < sizeof(s1) / sizeof(*s1); i++) {
        delete s1;
        s[i] = 0;
    }

return 0;
}