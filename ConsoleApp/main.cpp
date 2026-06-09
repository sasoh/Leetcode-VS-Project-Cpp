#include <algorithm>
#include <cctype>
#include <format>
#include <iostream>
#include <string>
#include <map>
#include <format>
#include <vector>
#include <stdexcept>
#include <locale>
#include <cmath>
#include <iomanip>
#include <ios>
using namespace std::string_literals;

namespace etl {
    std::map<char, int> transform(const std::map<int, std::vector<char>>& other)
    {
        std::map<char, int> r{};

        std::for_each(other.begin(), other.end(), [&](auto pair) {
            
            auto [points, characters] = pair;
            std::for_each(characters.begin(), characters.end(), [&](const char c) {
                r[std::tolower(c)] = points;
            });
        }); 

        return r;
    }
}  // namespace etl

int main() {
    const std::map<int, std::vector<char>> old{ {1, {'A', 'E', 'I', 'O', 'U'}} };
    const auto actual = etl::transform(old);
    const std::map<char, int> expected{
        {'a', 1}, {'e', 1}, {'i', 1}, {'o', 1}, {'u', 1} };
    //REQUIRE(expected == actual);    
    std::cout << std::boolalpha << (actual == expected) << '\n';
    return 0;
}