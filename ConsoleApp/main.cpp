//  15.25 (Computing Values at Compile - Time with Metaprogramming) Using the techniques in Section 15.13.2,
//  create a template metafunction, a constexpr recursive function and a constexpr iterative function to 
//  calculate the sum of the squares of the int values from 1 through the argument value.

#include <iostream>
using namespace std;

template<int T>
class SumOfSquares {
public:
    static constexpr int value{ T * T + SumOfSquares<T - 1>::value };
};

template<>
class SumOfSquares<0> {
public:
    static constexpr int value{ 0 };
};

static constexpr int SumOfSquaresFunction(int value) {
    int result = 0;
    for (size_t i{ 0 }; i <= value; ++i) {
        result += i * i;
    }
    return result;
}

int main() {
    constexpr int value = 3;
    cout << SumOfSquares<value>::value << endl;
    cout << SumOfSquaresFunction(value) << endl;
    return 0;
}