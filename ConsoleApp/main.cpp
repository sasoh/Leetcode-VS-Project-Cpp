//Compute the prime factors of a given natural number.
//A prime number is only evenly divisible by itself and 1.
//Note that 1 is not a prime number.
#include <iostream>
#include <vector>
#include <utility>

using std::vector;
using std::pair;

namespace prime_factors {
    vector<long long> of(long long number) {
        vector<long long> r{};
        auto n = number;
        long long f{2};
        while (n > 1) {
            if (n % f != 0) {
                f++;
            }
            else {
                n /= f;
                r.push_back(f);
            }
        }
        return r;
    }
}  // namespace prime_factors

int main() {
    vector<pair<long long, vector<long long>>> tests{
        {1, {}},
        {2, {2}},
        {3, {3}},
        {9, {3, 3}},
        {4, {2, 2}},
        {8, {2, 2, 2}},
        {27, {3, 3, 3}},
        {625, {5, 5, 5, 5}},
        {6, {2, 3}},
        {12, {2, 2, 3}},
        {901255, {5, 17, 23, 461}},
        {93819012551, {11, 9539, 894119}}
    };

    for (const auto& [i, expected] : tests) {
        const auto& f = prime_factors::of(i);
        if (f == expected) {
            std::cout << "Correct result for " << i << "\n";
        }
        else {
            std::cout << "Incorrect result for " << i << "\n";
        }
    }
 
    return 0;
}