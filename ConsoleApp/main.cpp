#include <format>
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <ranges>
#include <algorithm>
using namespace std;

// Implement a class template named Stack that uses a std::vector internally to store elements of any type T.
// The stack must support the following public operations:
//      push(T element), 
//      T pop() (which removes and returns the top element), 
//      bool isEmpty() (to check if the stack is empty).

template<typename T>
class CustomStack {
public:
    CustomStack() : m_v{} {}
    void push(T element) {
        m_v.push_back(element);
    }
    T pop() {
        auto r = m_v.back();
        m_v.pop_back();
        return r;
    }
    bool isEmpty() {
        return m_v.size() == 0;
    }
    void printStack() {
        ostream_iterator<T> out{ cout, " " };
        cout << "Stack contents: ";
        ranges::copy(m_v, out);
        cout << "\n";
    }
private:
    vector<T> m_v{};
};

int main() {
    CustomStack<int> intStack{};
    intStack.push(3);
    intStack.push(2);
    intStack.push(6);
    intStack.push(78);
    intStack.printStack();
    intStack.pop();
    intStack.pop();
    intStack.printStack();
    intStack.pop();
    cout << "Empty = " << intStack.isEmpty() << "\n";
    intStack.printStack();
    intStack.pop();
    cout << "Empty = " << intStack.isEmpty() << "\n";

    CustomStack<std::string> stringStack{};
    stringStack.push("test 1"s);
    stringStack.push("test 2"s);
    stringStack.push("test 3"s);
    stringStack.printStack();
    return 0;
}