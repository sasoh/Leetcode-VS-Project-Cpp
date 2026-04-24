#include <iostream>
#include <string>
using namespace std;

// Write a simple function template that prints a value of a generic type T. 
// Write the template definition first using the keyword class and then change it to use the keyword typename. 
// Explain the modern preference for typename in this context.

template<typename T>
void print(const T& v) {
    cout << v << "\n";
}

int main() {
    print(3);
    print(3.2);
    print("GLB");
    return 0;
}