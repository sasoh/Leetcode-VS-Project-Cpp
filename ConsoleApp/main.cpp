#include <iostream>
#include <format>
using namespace std;

// Implement a function template named mySwap that takes two parameters by reference, and swaps their values. 
// Demonstrate its usage with int and float variables.

template<typename T>
void mySwap(T& a, T&b) {
    T temp{a};
    a = b;
    b = temp;
}

int main() {
    int a1 = 2;
    int a2 = 3;
    cout << format("a1 = {} a2 = {}\n", a1, a2);
    mySwap(a1, a2);
    cout << format("a1 = {} a2 = {}\n", a1, a2);
    return 0;
}