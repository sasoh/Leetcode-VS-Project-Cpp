//  The energy points are awarded according to the following rules:
//  
//      1. For each magical item, take the base value and find all the multiples of that value that are less than the level number.
//      2. Combine the sets of numbers.
//      3. Remove any duplicates.
//      4. Calculate the sum of all the numbers that are left.

#include <initializer_list>
#include <numeric>
#include <set>

namespace {
    auto multiplesBelow(int of, int limit) {
        std::set<int> m{};

        int nextMultiple = 1;
        while (of * nextMultiple < limit) {
            m.insert(of * nextMultiple);
            ++nextMultiple;
        }

        return m;
    }
}

namespace sum_of_multiples {
    int to(std::initializer_list<int> items, int level) {
        std::set<int> m{};

        for (auto i {items.begin()}; i != items.end(); ++i) {
            auto multiples = multiplesBelow(*i, level);
            m.insert(multiples.begin(), multiples.end());
        }

        return std::accumulate(m.begin(), m.end(), 0);
    }

}  // namespace sum_of_multiples

int main() {

    return 0;
}