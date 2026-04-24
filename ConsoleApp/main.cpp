#include <vector>
#include <ranges>
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <iostream>
using namespace std;

// Implement a class template named Queue(First - In, First - Out) that can hold elements of any type T.
// It should expose the following public methods:
//      enqueue(T element) (add to the back), 
//      T dequeue() (remove and return the front element), 
//      bool isEmpty().
// You may use a standard library container like std::vector or std::list internally.

template<typename T>
class CustomQueue {
public:
    CustomQueue() : m_q{} {}
    void enqueue(T element) {
        m_q.push_back(element);
    }
    T dequeue() {
        if (isEmpty()) {
            throw std::out_of_range("No elements in queue");
        }
        T r{ m_q.back() };
        m_q.pop_back();
        return r;
    }
    bool isEmpty() {
        return m_q.size() == 0;
    }
    void print() {
        ostream_iterator<T> out{ cout, " " };
        cout << "Queue contents = ";
        ranges::copy(m_q, out);
        cout << "\n";
    }
private:
    vector<T> m_q{};
};

int main() {
    CustomQueue<int> q1{};
    q1.enqueue(3);
    q1.enqueue(2);
    q1.enqueue(7);
    q1.enqueue(1);
    q1.print();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.print();
    cout << "Empty = " << q1.isEmpty() << "\n";
    q1.dequeue();
    cout << "Empty = " << q1.isEmpty() << "\n";
    return 0;
}