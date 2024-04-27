#include<iostream>
#include<cmath>

class triangle{
    double side1;
    double side2;
    double side3;

    public:
    triangle():side1(0),side2(0),side3(0){}
    triangle(double s1,double s2,double s3){
        side1=s1;
        side2=s2;
        side3=s3;
        
    }
    triangle(triangle &other){
        side1=other.side1;
        side2=other.side2;
        side3=other.side3;

    }
    ~triangle(){}
    
    double getPerimeter() const {
        return side1 + side2 + side3;
    }

    double getArea() const {
        double s = getPerimeter() / 2.0;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    bool isRightTriangle() const {
         double side1Sq = side1 * side1;
    double side2Sq = side2 * side2;
    double side3Sq = side3 * side3;
    
    // Check if any two sides' squares sum up to the square of the third side
    return (side1Sq + side2Sq == side3Sq) || 
           (side1Sq + side3Sq == side2Sq) || 
           (side2Sq + side3Sq == side1Sq);}


    };

    int main(){
        triangle statictraingle(3.0,4.0,5.0);

        triangle *dynamictriangle = new triangle(5.0,13.0,12.0);
        
    }