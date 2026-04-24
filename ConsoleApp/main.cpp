#include <iostream>
#include <format>
#include <array>
using namespace std;

// Write a function template named findInArray that takes an array of type T,
// the array size, and a value of type T to search for.
// The function should return the index of the first occurrence of the value in the array,
// or -1 if the value is not found.

template<typename T>
int findInArray(const T array[], size_t size, T searched) {
    for (int i{0}; i < size; ++i) {
        if (array[i] == searched) {
            return i;
        }
    }
    return -1;
}

int main() {
    int a1[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    cout << findInArray<int>(a1, 9, 1) << "\n";
    return 0;
}