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
class Printer {
public:
    void print(T value) {
        cout << "Value: " << value << "\n";
    }
};

template<>
class Printer<char *> {
public:
    void print(char* value) {
        cout << "Value (c): \"" << value << "\"\n";
    }
};

template<>
class Printer<const char*> {
public:
    void print(const char* value) {
        cout << "Value (cc): \"" << value << "\"\n";
    }
};

int main() {
    Printer<int> pi{};
    pi.print(3);
    Printer<double> pd{};
    pd.print(7.2);
    Printer<char*> pc{};
    char chars[] = "something";
    pc.print(chars);
    Printer<const char*> pcc{};
    pcc.print("something else");
    return 0;
}