#include <iostream>
using namespace std;

// Create a generic function template named printValue that takes a parameter of type T and prints its value.
// Then, provide an explicit template specialization of this function specifically for the type bool.
// The specialized version should print the strings “True” or “False” instead of the numeric values 1 or 0.

template<typename T>
void printValue(T value) {
    cout << value << "\n";
}

template<>
void printValue<bool>(bool value) {
    cout << (value == true ? "True" : "False") << "\n";
}

int main() {
    printValue(4);
    printValue(-25.2);
    printValue(false);
    printValue(true);
    return 0;
}