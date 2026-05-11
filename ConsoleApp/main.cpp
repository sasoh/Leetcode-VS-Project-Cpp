//  Find the difference between the square of the sum and the sum of the squares of the first N natural numbers.

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

namespace difference_of_squares {
    int square_of_sum(int n) {
        auto sum = n * (n + 1) / 2;
        return sum * sum;
    }
    int sum_of_squares(int n) {
        return n * (n + 1) * (2 * n + 1) / 6;
    }
    int difference(int n) {
        return square_of_sum(n) - sum_of_squares(n);
    }
}  // namespace difference_of_squares

int main() {
    return 0;
}