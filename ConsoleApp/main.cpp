#include <memory>
#include <iostream>
#include <string>
using namespace std;

// Create a generic class template named Printer that has one type parameter T 
// and a single member function print(T value) that prints the value.
// Then, provide a full template specialization of the Printer class 
// specifically for the type char* (C - style string) 
// The specialized version’s print() function should display the string contents enclosed in double quotes.

template<typename T>
void print(T value) {
    cout << "Value: " << value << "\n";
}

template<>
void print(char* value) {
    cout << "Value: \"" << value << "\"\n";
}

template<>
void print(const char* value) {
    cout << "Value: \"" << value << "\"\n";
}

int main() {
    print(3);
    print(5.24);
    print("something");
    print("something else"s);
    return 0;
}