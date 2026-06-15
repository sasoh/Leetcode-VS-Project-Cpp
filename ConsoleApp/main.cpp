#include <algorithm>
#include <cctype>
#include <format>
#include <string>

namespace luhn {
    bool valid(const std::string& input);
    
    bool valid(const std::string& input)
    {
        std::string temp{input};
        temp.erase(std::remove_if(temp.begin(), temp.end(), isspace), temp.end());
        if (input.size() < 2) return false;
        
        if (std::remove_if(temp.begin(), temp.end(), isalpha) != temp.end()
            || std::remove_if(temp.begin(), temp.end(), ispunct) != temp.end()) return false;

        int sum{};
        int size = static_cast<int>(temp.size());
        for (int i{ size - 1 }; i >= 0; --i) {
            const int digit = std::stoi(temp.substr(i, 1));
            if ((size - i) % 2 == 0) {
                int doubled = 2 * digit;
                if (doubled > 9) {
                    sum += doubled - 9;
                }
                else {
                    sum += doubled;
                }
            }
            else {
                sum += digit;
            }
        }
        

        return (sum % 10 == 0);
    }
}  // namespace luhn

int main() {
    //luhn::valid("1")
    //luhn::valid("059");
    //luhn::valid("59");
    luhn::valid("055 444 285");
    //luhn::valid("8273 1232 7352 0569");
    return 0;
}