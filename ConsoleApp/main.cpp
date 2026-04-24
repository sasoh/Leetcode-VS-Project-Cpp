#include <iostream>
using namespace std;

// Create a generic function template named process that 
// takes one parameter of type T and prints a message 
// indicating it’s the generic version. Then, create a regular,
// non-template overload of the same function that takes a 
// single int parameter and prints a message indicating it’s
// the specialized int version. Observe which function the 
// compiler chooses when called with an int and a double.

template<typename T>
void genericFunction(const T t) {
    cout << "generic variant\n";
}

template<>
void genericFunction(const int t) {
    cout << "int variant\n";
}

int main() {
    genericFunction(1);
    genericFunction(1.2);
    genericFunction("gr");
    return 0;
}