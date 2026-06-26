#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <format>
#include <algorithm>
#include <stdexcept>

namespace {
    int charToInt(char c) {
        return static_cast<int>(c - '0');
    }
}

namespace largest_series_product {
    int largest_product(const std::string& input, int span);
    
    int largest_product(const std::string& input, int span)
    {
        if (span < 1) throw std::domain_error("Span should be >= 1.");
        if (std::any_of(input.begin(), input.end(), isalpha)) throw std::domain_error("Input should be only digits.");
        if (span > static_cast<int>(input.size())) throw std::domain_error("Span should be equal or less than string length.");
        if (input.size() == 0) throw std::domain_error("String should not be empty.");

        // rolling window of size span?
        int max{ 0 };
        for (int i{ 0 }, limit{ static_cast<int>(input.size() - span + 1) }; i < limit; ++i) {
            int runningMultiple{1};
            for (int j{ i }; j < i + span; ++j) {
                //std::cout << input[j] << ' ';
                runningMultiple *= charToInt(input[j]);
            }
            if (runningMultiple > max) max = runningMultiple;
            //std::cout << '\n';
        }
        //for (int i = 0, limit = static_cast<int>(input.size()) - span; i < limit; ++i) {
        //    int multiple{1};
        //    for (int j = 0; j < span; ++j) {
        //        multiple *= static_cast<int>(input[j] - '0');
        //    }
        //    if (multiple > max) max = multiple;
        //}


        return max;
    }
}

int main() {
    //std::cout << largest_series_product::largest_product("28", 2) << '\n';
    std::cout << largest_series_product::largest_product("287", 2) << '\n';
    return 0;
}