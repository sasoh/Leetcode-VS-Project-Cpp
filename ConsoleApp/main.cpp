#include <iostream>
#include <format>
#include <array>
#include <type_traits>
#include <format>
using namespace std;

// Create a function template named compareAndPrint that 
// takes two parameters of potentially different types, T1 and T2.
// The function should explicitly convert both parameters to a common type (e.g., double)
// for comparison and then print which original value was larger.
template<typename T1, typename T2> requires std::is_arithmetic_v<T1> && std::is_arithmetic_v<T2>
void compareAndPrint(const T1& a, const T2& b) {
    auto ad = static_cast<double>(a);
    auto bd = static_cast<double>(b);
    cout << format("Comparing {} ({}) and {} ({}): {} is greater.\n", a, ad, b, bd, ad >= bd ? a : b);
}

int main() {
    compareAndPrint(10, 9.9);
    compareAndPrint('A', 60);
    compareAndPrint(100.5, 100.49);
    return 0;
}