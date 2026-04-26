#include <memory>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

// Create a class template named FixedSizeArray that takes both a type parameter T 
// and an integer non - type parameter N for the size of the array.
// The array should be a private standard C - style array of size N.
// Include a member function T get(int index) to access elements.

template<typename T, int N>
class FixedSizeArray {
public:
    FixedSizeArray() : m_ptr{ make_unique<T[]>(N) }, m_size{ N } {}
    T& get(int index) {
        return m_ptr[index];
    }
    void print() const {
        ostream_iterator<int> out{ cout, " " };
        cout << "Array contents: ";
        ranges::copy(m_ptr.get(), m_ptr.get() + m_size, out);
        cout << "\n";
    }
private:
    unique_ptr<T[]> m_ptr{ nullptr };
    int m_size{};
};

int main() {
    FixedSizeArray<int, 4> a1{};
    a1.print();
    a1.get(1) = 5;
    a1.get(3) = 7;
    a1.print();
    return 0;
}