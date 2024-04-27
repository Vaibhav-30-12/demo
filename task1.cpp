#include <iostream>

class MaxFinder {
private:
    int* data;
    int size;

public:
    MaxFinder(int size) : size(size) {
        data = new int[size];
    }

    ~MaxFinder() {
        delete[] data;
    }

    void inputValues() {
        std::cout << "Enter " << size << " data values:" << std::endl;
        for (int i = 0; i < size; ++i) {
            std::cin >> data[i];
        }
    }

    int findMax() {
        if (size == 0) {
            std::cerr << "Error: Empty data set" << std::endl;
            return -1; // Return a sentinel value indicating error
        }

        int max = data[0];
        for (int i = 1; i < size; ++i) {
            if (data[i] > max) {
                max = data[i];
            }
        }
        return max;
    }
};

int main() {
    int size;
    std::cout << "Enter the number of data values: ";
    std::cin >> size;

    MaxFinder finder(size);
    finder.inputValues();
    int max = finder.findMax();

    if (max != -1) {
        std::cout << "Maximum value in the data set: " << max << std::endl;
    }

    return 0;
}
