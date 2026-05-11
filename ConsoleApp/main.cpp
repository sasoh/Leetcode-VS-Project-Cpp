//Given a number n, determine what the nth prime is.

#include <iostream>
#include <string>
#include <stdexcept>
#include <cmath>
#include <limits>
#include <format>
using namespace std;

namespace nth_prime {
    bool isPrime(int n) {
        //std::cout << format("Checking if {} is prime\n", n);
        int limit = static_cast<int>(std::sqrt(n));
        for (size_t i{ 2 }; i <= limit; ++i) {
            // should not divide by any number
            //std::cout << format("Is {} a divisor? {}\n", i, n % i == 0);
            if (n % i == 0) return false;
        }
        return true;
    }

    int nth(int n) {
        if (n < 1) {
            throw std::domain_error("N >= 1");
        }

        int primeCount{};
        constexpr auto maxIterations = std::numeric_limits<int>::max();
        for (size_t i{ 2 }; i <= maxIterations; ++i) {
            if (!isPrime(i)) continue;
            primeCount++;
            if (primeCount == n) {
                return i;
            }
        }

        return 1;
    }
}  // namespace nth_prime

int main() {
    std::cout << std::format("prime {}\n", nth_prime::nth(1));
    std::cout << std::format("prime {}\n", nth_prime::nth(2));
    std::cout << std::format("prime {}\n", nth_prime::nth(3));
    std::cout << std::format("prime {}\n", nth_prime::nth(4));
    std::cout << std::format("prime {}\n", nth_prime::nth(5));
    std::cout << std::format("prime {}\n", nth_prime::nth(6));
    return 0;
}