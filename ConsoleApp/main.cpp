#include <iostream>
#include <format>
#include <array>
using namespace std;

// Create a function template named printArray that takes an array 
// of any type and an integer representing the size of the array, 
// and then prints every element of the array on a single line, separated by spaces.

template<typename T, size_t size>
void printArray(const T a[]) {
    for (int i{ 0 }; i < size; ++i) {
        cout << a[i];
        if (i < size - 1) {
            cout << " ";
        }
    }
    cout << "\n";
}

int main() {
    int a1[]{ 1, 2, 3 };
    printArray<int, 3>(a1);
    double a2[]{ 1.2, 2.4, 3.7 };
    printArray<double, 3>(a2);
    return 0;
}