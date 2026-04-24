#include <iostream>
using namespace std;

// Create a function template named powerOfTwo that calculates 2^N where N is the input value of a generic type T. 
// In a separate section of your code (or a separate file, conceptually), 
// provide an explicit instantiation of this function template for the float type.

template<typename T>
T powerOfTwo(const T& v) {
    return v * v;
}

int main() {
    cout << powerOfTwo(4) << "\n";
    cout << powerOfTwo(4.2) << "\n";
    cout << powerOfTwo<float>(4.2f) << "\n";
    return 0;
}