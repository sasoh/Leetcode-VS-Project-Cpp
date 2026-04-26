#include <memory>
#include <iostream>
using namespace std;

// Create a class template named HoldingCell with two type parameters, T1 and T2. 
// Set the second type parameter, T2, to have a default type argument of int. 
// The class should hold two private members of types T1 and T2 and a constructor to initialize them.

template<typename T1, typename T2 = int>
class HoldingCell {
public:
    HoldingCell(const T1 t1, const T2 t2) : m_t1{ t1 }, m_t2{ t2 } {}
    void print() {
        cout << m_t1 << " " << m_t2 << "\n";
    }
private:
    T1 m_t1{};
    T2 m_t2{};
};

int main() {
    HoldingCell h1(2, 1);
    h1.print();
    HoldingCell h2(2.1, 3.6);
    h2.print();
    return 0;
}