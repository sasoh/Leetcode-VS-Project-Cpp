#include <algorithm>
#include <cctype>
#include <iostream>
#include <stdexcept>
#include <string>
using std::cout;
using std::endl;
using namespace std::string_literals;

namespace phone_number {
    class phone_number {
    public:
        phone_number(const std::string& n);
        std::string number() const;
    private:
        std::string clean_number(const std::string& n);
        std::string m_number{};
    };

    phone_number::phone_number(const std::string& n) : m_number{ clean_number(n) } {}

    std::string phone_number::number() const
    {
        return m_number;
    }

    namespace {
        int char_to_int(char c) {
            return c - '0';
        }
    }

    std::string phone_number::clean_number(const std::string& n)
    {
        std::string trimmed{ n };
        if (trimmed.size() < 10) throw std::domain_error("Incorrect input number.");
        trimmed.erase(remove_if(trimmed.begin(), trimmed.end(), isspace), trimmed.end());
        for (size_t i{0}; i < trimmed.size(); ++i) {
            char c = trimmed[i];
            if (isdigit(c)) continue;
            if (c == '+' || c == '.' || c == '-' || c == '(' || c == ')') continue;
            throw std::domain_error("Incorrect input number.");
        }
        trimmed.erase(remove_if(trimmed.begin(), trimmed.end(), ispunct), trimmed.end());

        if (trimmed[0] == '1' && trimmed.size() > 10) trimmed.erase(0, 1);
        if (char_to_int(trimmed[0]) < 2) throw std::domain_error("Incorrect input number.");
        if (char_to_int(trimmed[3]) < 2) throw std::domain_error("Incorrect input number.");

        if (trimmed.size() > 10) throw std::domain_error("Incorrect input number.");
        return trimmed;
    }
}  // namespace phone_number

int main() {
    //phone_number::phone_number("223.456.7890");
    phone_number::phone_number("(223) 456-7890");
    return 0;
}