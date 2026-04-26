#include <iterator>
#include <iostream>
#include <memory>
#include <string>
#include <format>
using namespace std;

// Create a class template named Calculator with two private member variables, num1 and num2, both of type T. 
// Include a constructor to initialize these members. 
// The class must provide public member functions for arithmetic operations: 
//      add(), 
//      subtract(), 
//      multiply(), 
//      divide(),
// all returning a value of type T.

template<typename T>
class Calculator {
public:
    Calculator(const T num1, const T num2) : m_num1{ num1 }, m_num2{ num2 } {}
    T add() {
        return m_num1 + m_num2;
    }
    T subtract() {
        return m_num1 - m_num2;
    }
    T multiply() {
        return m_num1 * m_num2;
    }
    T divide() {
        return m_num1 / m_num2;
    }
private:
    T m_num1;
    T m_num2;
};

int main() {
    Calculator c1(3, 5);
    cout << format("{}, {}, {}, {}\n", c1.add(), c1.subtract(), c1.multiply(), c1.divide());
    Calculator c2(7.5, 2.0);
    cout << format("{}, {}, {}, {}\n", c2.add(), c2.subtract(), c2.multiply(), c2.divide());
    return 0;
}