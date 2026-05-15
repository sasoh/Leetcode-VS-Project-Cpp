//  An allergy test produces a single numeric score which contains the information about all the allergies 
//  the person has (that they were tested for).
//  The list of items (and their value) that were tested are:
//  eggs(1)
//  peanuts(2)
//  shellfish(4)
//  strawberries(8)
//  tomatoes(16)
//  chocolate(32)
//  pollen(64)
//  cats(128)
//  So if Tom is allergic to peanuts and chocolate, he gets a score of 34.
//  Now, given just that score of 34, your program should be able to say:
//      Whether Tom is allergic to any one of those allergens listed above.
//      All the allergens Tom is allergic to.
//  Note: a given score may include allergens not listed above (i.e.allergens that score 256, 512, 1024, etc.).
//  Your program should ignore those components of the score. For example, if the allergy score is 257, your 
//  program should only report the eggs(1) allergy.

#include <iostream>
#include <string>
#include <unordered_set>
#include <bitset>
#include <cmath>
#include <cstdint>
#include <format>

using namespace std::string_literals;

namespace {
    static const std::string allergens[]{
        "eggs"s,
        "peanuts"s,
        "shellfish"s,
        "strawberries"s,
        "tomatoes"s,
        "chocolate"s,
        "pollen"s,
        "cats"s,
    };
}

namespace allergies {
    class allergy_test {
    public:
        explicit allergy_test(unsigned int level) : m_level{ level <= 256 ? level : level % 256 } {
            std::cout << std::format("Set m_level to {}\n", m_level.to_string());
        }
        bool is_allergic_to(const std::string& item) const;
        std::unordered_set<std::string> get_allergies() const;
    private:
        std::bitset<8> m_level{};
    };

    bool allergy_test::is_allergic_to(const std::string& item) const
    {
        for (size_t i{ 0 }; i < 8; ++i) {
            if (allergens[i] == item && m_level[i]) {
                return true;
            }
        }
        return false;
    }
    std::unordered_set<std::string> allergy_test::get_allergies() const
    {
        std::unordered_set<std::string> r{};
        for (size_t i{ 0 }; i < 8; ++i) {
            if (m_level[i]) {
                r.emplace(allergens[i]);
            }
        }
        return r;
    }
}  // namespace allergies

int main() {
    //auto a1 = allergies::allergy_test(55);
    //std::cout << a1.is_allergic_to("eggs") << std::endl;
    //std::cout << a1.is_allergic_to("peanuts") << std::endl;
    //std::cout << a1.is_allergic_to("shellfish") << std::endl;
    //std::cout << a1.is_allergic_to("strawberries") << std::endl;
    //auto a2 = allergies::allergy_test(505);
    //auto a3 = allergies::allergy_test(5500);
    //auto a = allergies::allergy_test(32);
    //auto b = a.is_allergic_to("chocolate");
    //auto a = allergies::allergy_test(128);
    auto a = allergies::allergy_test(192);
    //auto b = a.is_allergic_to("cats");
    return 0;
}