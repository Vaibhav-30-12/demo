#include <iostream>
using namespace std;

class person
{
    string firstname;
    string lastname;
    char middleinitial;
    string title;


protected:
    void modifytitle(const string &);

public:
    person();
    person(const string &, const string &, char mi, const string &);
    const string &get_first_name() const;
    const string &get_last_name() const;
    char get_middle_initial()const;
    void print()const;//getter
    void IsA()const;
    ~person();


};

class student:public person{
    float gpa;
    string current_course;
    const string student_ID;
    static int num_students;

    public:
    student();
    student(float c,string & crs,const string &id,const string &fn, const string &ln, char mi,const string &fi)
    :person(fn,ln,mi,fi),gpa(c),current_course(crs),student_ID(id)
    {}

    

    /*copy constructor student s3(s1);
    with default copy constructor problem in dynamic memory */
    student(const student &);/*here we need to create a copy constructor as
     id number cant be same and 
     static numstudent cant be same for 2 students
      we need to increase it by creating copy constructor
     as every time we nake student we need to increment that static int num students which cant be done in default copy constructor*/

     void earn_PHD(){
        
        
        modifytitle("doctor" );
        return;



     }/* this cant be const as title needs to be changed*/

     float get_gpa ()const{//doesnt modify host object 
     /*cant write const heree because 
     */
        return gpa;
        };

   const string& current_course()const {
        return current_course;
    };

    const string & getstudentID()const;//

     void setcurrentcourse(const string &);

     void print ()const{

     }

void IsA()const;
static int getnumstudents();




    ~student();
    };


person::person(){}
person::person(const string & fn,const string & ln,char mi,const string &title)
:firstname(fn),lastname(ln),middleinitial(mi){
    modifytitle(title);

}

const string & person:: get_first_name ()const {
    return firstname;
}

const string& person::get_last_name()const{
    return lastname;
}

char person::get_middle_initial()const{
    return middleinitial;
}

void person::modifytitle(const string &newtitle){
    title=newtitle;


    
}
/*

*/


// // #include<iostream>

// // using namespace std;

// // class rational{
// //      long long int numer;
// //   long long int denom;
// //   long long int findGCD(long long int, long long int);
// //   public:
// //   rational(){}
// //   rational (long long int num,long long int denom);
// //   rational addrat(rational);
// //   rational operator +(rational);
// //   void print();
// //   void reducerat();
// //   rational & operator ++();
// //   friend const rational operator ++(rational &,int);

// // };
// // rational & rational::operator++(){
// //     numer=numer+denom;
// //     reducerat();
// //     return *this;
// // }


// // const rational operator++(rational& r,int dummy){
// //     rational temp(r.numer,r.denom);
// //     ++r;
// //     return temp;

// // }
// // long long int rational ::findGCD(long long int u,long long int v){
// //     return (v!=0) ?findGCD(v,u%v):u;
// // }

// // void rational ::reducerat(){
// //     long long int gcd=findGCD(numer,denom);
// //     numer=numer /gcd;
// //     denom=denom/gcd;

// // }


// // rational::rational (long long int numer, long long int denom){
// //     this->numer=numer;
// //     this->denom=denom;

// // }

// // void rational::print(){
// //     cout << numer << " / " << denom << endl;
// // }


// // rational rational ::addrat(rational B){
// //     rational r;
// //     r.numer=numer*B.denom+B.numer*denom;
// //     r.denom=denom*B.denom;
// //     return r;

// // }

// // int main(){
// //      rational ratA(1,2), ratB(1,4), ratResult1, ratResult2;
// //   cout << "ratA = ";
// //   ratA.print();
// //   cout << "ratB = ";
// //   ratB.print();

// //   ratResult1 = ratA++;
// //   cout << "\nValue of ratA++: ";
// //   ratResult1.print();
// //   cout << "ratA after postfix increment: ";
// //   ratA.print();

// //   ratResult2 = (++++ratB)++;
// //   cout << "\nValue of ++ratB: ";
// //   ratResult2.print();
// //   cout << "ratB after prefix increment: ";
// //   ratB.print();
// // rational arr[4];
// // arr[0]=ratA;
// // arr[0].print();

// // }



// #include <iostream>
// #include <cstring>
// #include <string>
// using namespace std;

// char & my_find(string &s, char c)
// {
//   int posn = s.find(c); 
//   return s[posn];
// }

// int main()
// {
//   string s = "Plaksha"; 
//   cout << s << endl;
//   my_find(s,'a') = '*';
//   cout << s << endl;
//   return 0;
// } 


#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int num, int denom) : numerator(num), denominator(denom) {}
Fraction():numerator(0),denominator(0){}
    void simplify() {
        int common = gcd(numerator, denominator);
        numerator /= common;
        denominator /= common;
    }

    int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }


    Fraction  operator +(Fraction f){

            Fraction frac;
            frac.numerator=numerator*f.denominator+f.numerator*denominator;
            frac.denominator= denominator*f.denominator;
             frac.simplify();
            return frac;

    }

    Fraction  operator -(Fraction f){
            Fraction frac;
            frac.numerator=numerator*f.denominator-f.numerator*denominator;
            frac.denominator= denominator*f.denominator;
            frac.simplify();
            return frac;



    }
    Fraction  operator *(Fraction f){

             Fraction frac;
             frac.numerator=numerator*f.numerator;
             frac.denominator=denominator*f.denominator;
             frac.simplify();
             return frac;
    }
    Fraction  operator /(Fraction f){

             Fraction frac;
             frac.numerator=numerator*f.denominator;
             frac.denominator=denominator*f.numerator;
             frac.simplify();
             return frac;
    }
//define the overloaded operators
 void display() const {
        std::cout << numerator << "/" << denominator;
    }
};

int main() {
    Fraction frac1(1, 2);
    Fraction frac2(3, 4);

    std::cout << "Fraction 1: ";
    frac1.display();
    std::cout << std::endl;

    std::cout << "Fraction 3: ";
    frac2.display();
    std::cout << std::endl;

    Fraction sum = frac1 + frac2;
    std::cout << "Sum: ";
    sum.display();
    std::cout << std::endl;

   Fraction diff = frac1 - frac2;
    std::cout << "Difference: ";
    diff.display();
    std::cout << std::endl;

    Fraction product = frac1 * frac2;
    std::cout << "Product: ";
    product.display();
    std::cout << std::endl;

    Fraction quotient = frac1 / frac2;
    std::cout << "Quotient: ";
    quotient.display();
    std::cout << std::endl;

    return 0;
}
