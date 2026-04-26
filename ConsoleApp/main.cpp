#include <memory>
using namespace std;

// Define a class template for a Node in a singly linked list.
// The node must hold a value of generic type T and a pointer to the next node(which must be a pointer to a Node<T>).
// Include a constructor to initialize the value.

template<typename T>
class Node {
public:
    Node(T value) : m_value{ value }, m_next{ nullptr } {}
    void setNext(Node<T>& next) {
        m_next = make_shared<Node<T>>(next);
    }
private:
    T m_value{};
    shared_ptr<Node<T>> m_next{ nullptr };
};

int main() {
    Node<int> n1(2);
    Node<int> n2(3);
    Node<int> n3(4);
    n2.setNext(n1);
    n3.setNext(n2);
    return 0;
}