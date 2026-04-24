#include <iostream>
#include <format>
#include <array>
#include <type_traits>
using namespace std;

// Implement a function template named sum that takes an array 
// of any numeric type(int, float, double) and its size, 
// and returns the sum of all its elements.

template<typename T> requires std::is_arithmetic_v<T>
T sum(const T arr[], size_t size) {
    T sum{};
    for (int i{0}; i < size; ++i) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int a1[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    cout << "Sum = " << sum(a1, 9) << "\n";
    return 0;
}