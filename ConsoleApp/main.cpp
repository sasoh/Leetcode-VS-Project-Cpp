#include <memory>
#include <iostream>
using namespace std;

// Design a simple generic container class MyVector<T> that internally uses a dynamic array (T*). 
// Include basic iterator support by defining a nested type alias iterator as a pointer to T (T*). 
// Implement the public methods begin() and end() to return the start and end iterators.

template<typename T>
class MyVector {
public:
    using iterator = T*;
    MyVector(int size) : m_size{ size }, m_array{ make_unique<T[]>(size) } {
        for (int i{ 0 }; i < m_size; ++i) {
            m_array[i] = T{};
        }
    }
    iterator begin() {
        return m_array.get();
    }
    iterator end() {
        return m_array.get() + m_size;
    }
private:
    unique_ptr<T[]> m_array{ nullptr };
    int m_size;
};

template<typename T>
void print(MyVector<T>& vector) {
    for (const auto& v : vector) {
        cout << v << " ";
    }
    cout << "\n";
}

int main() {
    MyVector<double> v1{ 4 };
    auto value = v1.begin();
    print(v1);
    *value = 3;
    print(v1);
    value += 1;
    *value = 2;
    print(v1);
    return 0;
}