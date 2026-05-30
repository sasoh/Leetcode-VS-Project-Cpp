#include <iostream>
#include <format>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <stdexcept>
using std::format;
using std::cout;
using std::endl;
using namespace std::string_literals;

namespace binary_search {
    size_t find(std::vector<int> data, int number)
    {
        int lower = 0;
        int upper = data.size() - 1;
        while (lower <= upper) {
            int middle = (lower + upper) / 2;
            int current = data[middle];
            cout << format("[{}; {}] ({})\n", lower, upper, current);
            if (current == number) {
                return middle;
            }
            if (current < number) {
                lower = middle;
            }
            else {
                upper = middle;
            }
        }

        throw std::domain_error("Element not in collection");
    }
}  // namespace binary_search

int main() {
    const std::vector<int> data{ 1, 3, 4, 6, 8, 9, 11 };
    const std::size_t actual = binary_search::find(data, 3);
    const std::size_t expected = 2;
    cout << actual << " vs " << expected << endl;

    return 0;
}