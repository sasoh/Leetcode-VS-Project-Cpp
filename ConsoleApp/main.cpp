#include <iostream>
#include <string>
using namespace std;

// Write a function template named combine that accepts two values of the same type T
// and returns the result of applying the addition operator (+) to them. 
// Test the function with int (which performs addition) and with std::string (which performs concatenation).

template<typename T>
T combine(const T& a, const T& b) {
    return a + b;
}

int main() {
    cout << "Sum = " << combine(3, 5) << "\n";
    cout << "Sum = " << combine("efji"s, "grhbfu"s) << "\n";
    return 0;
}