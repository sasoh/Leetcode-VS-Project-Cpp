#include <format>
#include <iostream>

#include <vector>
#include <array>
#include <string>
using namespace std::string_literals;

namespace {
    static std::array<std::string, 8> song_animals[]{
        "fly"s,
        "spider"s,
        "bird"s,
        "cat"s,
        "dog"s,
        "goat"s,
        "cow"s,
        "horse"s,
    };
    static std::array<std::string, 8> song_animals_second[]{
        ""s,
        "It wriggled and jiggled and tickled inside her."s,
        "How absurd to swallow a bird!"s,
        "Imagine that, to swallow a cat!"s,
        "What a hog, to swallow a dog!"s,
        "Just opened her throat and swallowed a goat!"s,
        "I don't know how she swallowed a cow!"s,
    };
    static std::string verse_end{"I don't know why she swallowed the fly. Perhaps she'll die."s};
    static std::string song_end{"She's dead, of course!"s};
}

namespace food_chain {
    std::string verse(size_t n);
    std::string verses(size_t from, size_t to);
    std::string sing();

    std::string verse(size_t n)
    {
        std::string r{ "I know an old lady who swallowed a " };
        r.append(song_animals->at(n - 1) + '.');

        if (n < song_animals->size()) {
            for (size_t i{ n - 1 }; i > 0; --i) {
                if (i == n - 1) {
                    r.append('\n' + song_animals_second->at(i));
                }

                if (i == 2) {
                    r.append("\nShe swallowed the " + song_animals->at(i) + " to catch the " + song_animals->at(i - 1) + " that wriggled and jiggled and tickled inside her.");
                }
                else {
                    r.append("\nShe swallowed the " + song_animals->at(i) + " to catch the " + song_animals->at(i - 1) + ".");
                }
            }

            r.append('\n' + verse_end);
        }
        else {
            r.append('\n' + song_end);
        }

        return r;
    }
    std::string verses(size_t from, size_t to)
    {
        std::string r{};

        for (size_t i{from}; i <= to; ++i) {
            r += verse(i);
            if (i < to) {
                r += "\n\n";
            }
        }

        return r;
    }
    std::string sing()
    {
        return verses(1, 8);
    }
}  // namespace food_chain


int main() {
    //std::cout << food_chain::verse(1) << '\n';
    //std::cout << food_chain::verse(8) << '\n';
    //std::cout << food_chain::verse(2) << '\n';
    //std::cout << food_chain::verse(4) << '\n';
    //std::cout << food_chain::verses(1, 4) << '\n';
    std::cout << food_chain::sing() << '\n';
    return 0;
}