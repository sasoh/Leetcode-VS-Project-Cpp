#include <iterator>
#include <iostream>
#include <memory>
#include <string>
using namespace std;

// Design a class template named GenericArray that dynamically allocates an array of type T 
// and its size is specified in the constructor. The class must include a destructor to manage 
// memory and overload the subscript operator ([]) for element access.

template<typename T>
class GenericArray {
public:
    GenericArray(size_t size) : m_t{ make_unique<T[]>(size) }, m_size{ size } {
        for (int i{ 0 }; i < size; ++i) {
            m_t[i] = {};
        }
    }
    T& operator[](int index) {
        return m_t[index];
    }
    void print() {
        ostream_iterator<T> out(cout, " ");
        cout << "Elements: ";
        copy(m_t.get(), m_t.get() + m_size, out);
        cout << "\n";
    }
private:
    unique_ptr<T[]> m_t{};
    size_t m_size;
};

int main() {
    GenericArray<int> a1(4);
    a1.print();
    a1[1] = 3;
    a1.print();
    GenericArray<string> a2(4);
    a2.print();
    a2[1] = "test"s;
    a2.print();
    return 0;
}