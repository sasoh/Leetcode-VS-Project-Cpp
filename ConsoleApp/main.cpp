#include <iostream>
#include <utility>
#include <format>
using namespace std;

class ClassTest {
public:
    explicit ClassTest(int a) : m_a{ a } {
        cout << "Construct " << m_a << "\n";
    }

    ClassTest(const ClassTest& other) : m_a{ other.m_a } {
        cout << "Copy construct " << m_a << "\n";
    }

    ClassTest& operator=(const ClassTest& other) {
        cout << "Copy assignment " << other.m_a << " to " << m_a << "\n";
        m_a = other.m_a;
        return *this;
    }

    ClassTest(ClassTest&& other) noexcept : m_a{ exchange(other.m_a, 0) } {
        cout << "Move construct " << m_a << "\n";
    }

    ClassTest& operator=(ClassTest&& other) noexcept {
        cout << "Move assignment " << other.m_a << " to " << m_a << "\n";
        if (this != &other) {
            m_a = exchange(other.m_a, 0);
        }
        return *this;
    }

    bool operator==(const ClassTest& other) const noexcept {
        cout << "operator== for " << m_a << "\n";
        return other.m_a == m_a;
    }

    bool operator!=(const ClassTest& other) const noexcept {
        cout << "operator!= for " << m_a << "\n";
        return !(*this == other);
    }
    
    ~ClassTest() {
        cout << "Destruct " << m_a << "\n";
    }
private:
    int m_a{ 0 };
};

//ClassTest make() {
//    ClassTest result{ 3 };
//    return result;
//}

void SpecialFunctionsTest() {
    ClassTest a{ 1 };
    ClassTest b{ 2 };
    ClassTest c{ 3 };
    //ClassTest c{ a }; // copy construct
    //ClassTest d = a; // copy construct
    // 
    //c = a; // copy assignment
    // 
    //ClassTest m{std::move(b)}; // move construct

    //c = std::move(b); // move operator

    //cout << format("a == b = {}\n", a == b); // operator==
    //cout << format("a != b = {}\n", a != b); // operator!=
}

int main() {
    //auto a = make();
    SpecialFunctionsTest();
}