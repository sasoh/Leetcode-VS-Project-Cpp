#include <vector>
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <format>

namespace perfect_numbers {
    enum class classification {
        perfect,
        abundant,
        deficient
    };

    classification classify(int number);
    classification classify(int number)
    {
        if (number < 1) throw std::domain_error("Invalid number");
        size_t n{static_cast<size_t>(number)};
        size_t sum{};

        for (int i{1}, limit{number / 2}; i <= limit; ++i) {
            if (number % i != 0) continue;
            sum += static_cast<size_t>(i);
        }

        if (sum < n) return classification::deficient;
        if (sum == n) return classification::perfect;
        return classification::abundant;
    }
} // namespace perfect_numbers

int main() {
    //perfect_numbers::classify(6);
    //perfect_numbers::classify(28);
    //perfect_numbers::classify(12);
    //perfect_numbers::classify(24);
    //perfect_numbers::classify(8);
    std::cout << (perfect_numbers::classify(33550336) == perfect_numbers::classification::perfect) << '\n';
    return 0;
}