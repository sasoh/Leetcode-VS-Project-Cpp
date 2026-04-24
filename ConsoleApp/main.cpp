#include <format>
#include <iostream>
#include <string>
using namespace std;

// Create a class template named Pair that can hold two values of potentially different types, T1 and T2.
// Include a public constructor that takes arguments for these two values and initializes them. Finally,
// include public member functions getFirst() and getSecond() to retrieve the stored values.

template<typename T1, typename T2>
class Pair {
public:
    Pair(const T1 t1, const T2& t2) : m_t1{ t1 }, m_t2{ t2 } {}
    T1 getFirst() { return m_t1; }
    T2 getSecond() { return m_t2; }
private:
    T1 m_t1{};
    T2 m_t2{};
};

int main() {
    Pair p1(2, "test"s);
    cout << format("Pair: {}, {}\n", p1.getFirst(), p1.getSecond());
    Pair p2("bbrr", 4.2); 
    cout << format("Pair: {}, {}\n", p2.getFirst(), p2.getSecond());
    return 0;
}