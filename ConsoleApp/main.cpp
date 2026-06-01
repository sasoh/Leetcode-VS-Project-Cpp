#include <algorithm>
#include <cctype>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using namespace std::string_literals;

namespace series {
    auto slice(const std::string& input, int n) {
        std::vector<std::string> r{};
        if (static_cast<size_t>(n) == input.size()) {
            r.push_back(input);
            return r;
        }
        if (n < 1 || static_cast<size_t>(n) > input.size()) {
            throw std::domain_error("Incorrect slice size.");
        }
        for (size_t i{0}, limit{input.size() - n}; i < limit; ++i) {
            r.push_back(input.substr(i, n));
        } 

        return r;
    }
}  // namespace series

int main() {
    //series::slice("9142", 2)
    return 0;
}