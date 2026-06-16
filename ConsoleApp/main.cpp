#include <string>
#include <cmath>

namespace armstrong_numbers {
    //armstrong_numbers::is_armstrong_number(5)
    bool is_armstrong_number(int number) {
        //An Armstrong number is a number that is the sum of its own digits each raised to the power of the number of digits.
        size_t digitCount = std::to_string(number).size();
        auto sum{ 0 };
        int temp{ number };
        do {
            int rem = temp % 10;
            temp /= 10;
            sum += std::pow(rem, digitCount);
        } while (temp > 0);

        return (sum == number);
    }
}  // namespace armstrong_numbers

int main() {
    return 0;
}