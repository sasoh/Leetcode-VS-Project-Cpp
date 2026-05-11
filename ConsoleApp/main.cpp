//The rules were deceptively simple. Pick any positive integer.
//If it's even, divide it by 2.
//If it's odd, multiply it by 3 and add 1.
//Then, repeat these steps with the result, continuing indefinitely.

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

namespace collatz_conjecture {
    int steps(int start) {
        if (start < 1) {
            throw std::domain_error("Number must be more than 1");
        }
        if (start == 1) {
            return 0;
        }
        if (start % 2 == 0) {
            return 1 + steps(start / 2);
        }
        else {
            return 1 + steps(3 * start + 1);
        }
    }
}  // namespace collatz_conjecture


int main() {
    auto a = collatz_conjecture::steps(16);
    auto b = collatz_conjecture::steps(12);
    auto c = collatz_conjecture::steps(100000);
    auto d = collatz_conjecture::steps(0);
    return 0;
}