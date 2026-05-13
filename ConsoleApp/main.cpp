// Sieve of Eratosthenes
// Write out all the numbers from 2 up to and including your given number.Then, follow these steps:
//   Find the next unmarked number (skipping over marked numbers). This is a prime number.
//   Mark all the multiples of that prime number as not prime.
// Repeat the steps until you've gone through every number. At the end, all the unmarked numbers are prime.

#include <iostream>
#include <vector>
#include <set>
using namespace std;

namespace sieve {
    auto primes(int n) {
        std::vector<int> r{};
        if (n < 2) return r;
        std::set<int> excluded{};
        for (int i{2}; i <= n; ++i) {
            if (excluded.find(i) != excluded.end()) continue;
            r.push_back(i);
            for (int j{1}; j <= n; j += 1) {
                excluded.insert(i * j);
            }
        }

        return r;
    }
}  // namespace sieve

int main() {
    const std::vector<int> expected{ 2, 3, 5, 7 };
    const std::vector<int> actual = sieve::primes(10);
    std::cout << (expected == actual) << std::endl;
    return 0;
}