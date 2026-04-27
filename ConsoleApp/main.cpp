#include <iostream>
using namespace std;

// (C++11 + ) Write a variadic function template called print_all that can accept zero or more arguments of any type and print them all,
// separated by spaces.
// You must use a base case and a recursive case to unpack the parameter pack.

void print_all() {
    cout << "\n";
}

template<typename T, typename... Rs>
void print_all(T first, Rs... rest) {
    cout << first << " ";
    print_all(rest...);
}

int main() {
    print_all(3, 6, 2);
    print_all(-3.22, 4, "something");
    return 0;
}