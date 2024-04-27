#include <iostream>
 #include <cmath>
 using namespace std;

// // Abstract base class Shape
// class Shape {
// public:
//     // Pure virtual function to compute the area of a shape
//     virtual double Area() const = 0;

//     // Virtual destructor to ensure proper cleanup
//     virtual ~Shape() {}
// };

// // Derived class Rectangle
// class Rectangle : public Shape {
// protected:
//     double length;
//     double width;

// public:
//     Rectangle(double l, double w) : length(l), width(w) {}

//     // Redefine the Area() method for Rectangle
//     double Area() const override {
//         return length * width;
//     }
// };

// // Derived class Square
// class Square : public Rectangle {
// public:
//     Square(double side) : Rectangle(side, side) {}
// };

// // Derived class Circle
// class Circle : public Shape {
// protected:
//     double radius;

// public:
//     Circle(double r) : radius(r) {}

//     // Redefine the Area() method for Circle
//     double Area() const override {
//         return M_PI * radius * radius;
//     }
// };

// // Derived class Triangle
// class Triangle : public Shape {
// protected:
//     double base;
//     double height;

// public:
//     Triangle(double b, double h) : base(b), height(h) {}

//     // Redefine the Area() method for Triangle
//     double Area() const override {
//         return 0.5 * base * height;
//     }
// };

// int main() {
//     // Create an array of pointers to Shape objects
//     Shape* shapes[4];

//     // Assign elements in the array to instances of different shapes
//     shapes[0] = new Rectangle(5, 3);
//     shapes[1] = new Square(4);
//     shapes[2] = new Circle(2);
//     shapes[3] = new Triangle(4, 6);

//     // Loop through the array and invoke the Area() function for each shape
//     for (int i = 0; i < 4; ++i) {
//         std::cout << "Area of shape " << i+1 << ": " << shapes[i]->Area() << std::endl;
//     }

//     // Cleanup: delete dynamically allocated memory
//     for (int i = 0; i < 4; ++i) {
//         delete shapes[i];
//     }

//     return 0;
// }

class complex {
  long int real;
  long int img;
  public:
complex (){};

complex(long long int real,long long int img){

this->real=real;

this->img=img;

}

complex(complex &c){
real=c.real;

img=c.img;}

complex operator+(complex b){
complex temp;

temp.real=real+b.real;

temp.img=img+b.img;

return temp;}



complex operator*(complex b){

//(ac-bd)+ i(bc+ad).   a+ib to c+id
complex temp;

real= (real*b.real)-(img*b.img);

img=(img*b.real)+(real*b.img);

return temp;}






// rest of the class definition goes here below
  
void print() const{
cout<<real<<"+  i"<<img<<endl;

}


}; 
int main(){
    complex c1(2,3);
    complex c2(3,5);
    c2=c1;
    complex c3(c2);
   // c3=c1+c2;
    c3.print();

}