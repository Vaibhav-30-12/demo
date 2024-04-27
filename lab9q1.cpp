#include <iostream>

using namespace std;

class Vec {
private:
    int *array; // Pointer to dynamic array
    int size;   // Size of the array

public:
    // Default constructor
    Vec() : array(nullptr), size(0) {}

    // Constructor with size parameter
    Vec(int sz) : size(sz) {
        array = new int[size](); // Initialize all elements to zero
    }

    // Constructor with size and value parameters
    Vec(int sz, int val) : size(sz) {
        array = new int[size]; // Allocate memory
        for (int i = 0; i < size; ++i) {
            array[i] = val; // Set all elements to the given value
        }
    }

    // Destructor
    ~Vec() {
        delete[] array; // Deallocate memory
    }

    // Copy constructor
    Vec(const Vec &other) : size(other.size) {
        array = new int[size]; // Allocate memory
        for (int i = 0; i < size; ++i) {
            array[i] = other.array[i]; // Copy elements
        }
    }

    // Overloaded assignment operator
    Vec& operator=(const Vec &other) {
        if (this != &other) { // Check for self-assignment
            // Deallocate existing memory
            delete[] array;
            // Allocate new memory
            size = other.size;
            array = new int[size];
            // Copy elements
            for (int i = 0; i < size; ++i) {
                array[i] = other.array[i];
            }
        }
        return *this;
    }

    // Method to print the contents of the array
    void printVec() const {
        for (int i = 0; i < size; ++i) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    // Overloaded + operator for element-wise addition
    Vec operator+(const Vec &other) const {
        Vec result(size); // Create a new Vec object
        for (int i = 0; i < size; ++i) {
            result.array[i] = array[i] + other.array[i]; // Perform element-wise addition
        }
        return result;
    }
};

int main() {
    // Testing the Vec class
    cout << "Testing constructors:" << endl;
    Vec v1; // Default constructor
    v1.printVec();

    Vec v2(5); // Constructor with size parameter
    v2.printVec();

    Vec v3(3, 100); // Constructor with size and value parameters
    v3.printVec();

    cout << "\nTesting copy constructor:" << endl;
    Vec v4 = v3; // Copy constructor
    v4.printVec();

    cout << "\nTesting overloaded assignment operator:" << endl;
    Vec v5;
    v5 = v2; // Overloaded assignment operator
    v5.printVec();

    cout << "\nTesting operator overloading:" << endl;
    Vec v6(4, 10), v7(4, 20);
    Vec v8 = v6 + v7; // Operator overloading (+)
    v8.printVec();

    return 0;
}
