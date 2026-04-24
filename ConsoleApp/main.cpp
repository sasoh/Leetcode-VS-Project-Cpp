#include <iostream>
#include <string>
#include <ranges>
#include <vector>
#include <unordered_set>
#include <array>
#include <format>

//15.15 (Function Template) Create a sumRange function template that receives a range of
//values, sums them and returns the result.Use a range - based for statement and the += op -
//erator to perform your calculations.Test your code with a container of ints, a container
//of doubles and a container of strings.

template<typename T, std::ranges::input_range S>
    requires requires (T sum, std::ranges::range_value_t<S> v) {
    sum += v;
}
T sumRange(const S& range) {
    T sum{};
    for (const auto& v : range) {
        sum += v;
    }
    return sum;
}

int main() {
    std::array<int, 5> a1{ 1, 2, 3, 4, 5 };
    std::cout << std::format("Sum of a1 = {}\n", sumRange<int>(a1));
    std::vector<double> v2{ 1.0, 2.1, 3.2, 4.3 };
    std::cout << std::format("Sum of v2 = {}\n", sumRange<double>(v2));
    std::unordered_set<std::string> v3{ "ab", "cd", "ef" };
    std::cout << std::format("Sum of v3 = {}\n", sumRange<std::string>(v3));
    return 0;
}