#include <iostream>

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int num, int denom) : numerator(num), denominator(denom) {
        if (denominator == 0) {
            std::cerr << "Error: Denominator cannot be zero" << std::endl;
            exit(1); // Exit with error status
        }
    }

    Fraction operator+(const Fraction& other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int denom = denominator * other.denominator;
        return simplifyFraction(num, denom);
    }

    Fraction operator-(const Fraction& other) const {
        int num = numerator * other.denominator - other.numerator * denominator;
        int denom = denominator * other.denominator;
        return simplifyFraction(num, denom);
    }

    Fraction operator*(const Fraction& other) const {
        int num = numerator * other.numerator;
        int denom = denominator * other.denominator;
        return simplifyFraction(num, denom);
    }

    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            std::cerr << "Error: Division by zero" << std::endl;
            exit(1); // Exit with error status
        }
        int num = numerator * other.denominator;
        int denom = denominator * other.numerator;
        return simplifyFraction(num, denom);
    }

    void print() const {
        std::cout << numerator << "/" << denominator;
    }

private:
    int gcd(int a, int b) const {
        return (b == 0) ? a : gcd(b, a % b);
    }

    Fraction simplifyFraction(int num, int denom) const {
        int divisor = gcd(num, denom);
        return Fraction(num / divisor, denom / divisor);
    }
};

int main() {
    Fraction fraction1(1, 2);
    Fraction fraction2(3, 4);
  //  fraction1=fraction1+fraction2;
    
    std::cout << "Addition: ";
    (fraction1 + fraction2).print();
    std::cout << std::endl;

    std::cout << "Subtraction: ";
    (fraction1 - fraction2).print();
    std::cout << std::endl;

    std::cout << "Multiplication: ";
    (fraction1 * fraction2).print();
    std::cout << std::endl;

    std::cout << "Division: ";
    (fraction1 / fraction2).print();
    std::cout << std::endl;

    return 0;
}
