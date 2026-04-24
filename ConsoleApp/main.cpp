#include <iostream>
#include <format>
using namespace std;

// Create a function template named myMax that accepts two parameters of the same type 
// and returns the larger of the two values. The function should work correctly for 
// standard data types like int, double, and char.

template<typename T>
T myMax(const T& a, const T& b) {
    return a >= b ? a : b;
}

int main() {
    cout << format("max1 = {}\n", myMax(1, 5));
    cout << format("max2 = {}\n", myMax(5, 1));
    cout << format("max3 = {}\n", myMax(2.3, 2.4));
    cout << format("max4 = {}\n", myMax(2.4, 2.3));
    cout << format("max5 = {}\n", myMax('a', 'c'));
    return 0;
}