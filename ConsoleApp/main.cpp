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
using namespace std::string_literals;

namespace {
    static std::string normalize(const std::string& i) {
        std::string n{ i };

        n.erase(std::remove_if(n.begin(), n.end(), isspace), n.end());
        n.erase(std::remove_if(n.begin(), n.end(), ispunct), n.end());
        std::transform(n.begin(), n.end(), n.begin(), [](auto c) { return std::tolower(c); });

        size_t r{};
        size_t c{};
        double rootOfSize = std::sqrt(n.size());
        int ceil = std::ceil(rootOfSize);
        if (ceil * (ceil - 1) >= static_cast<int>(n.size())) {
            r = ceil - 1;
            c = ceil;
        }
        else {
            r = c = ceil;
        }

        std::string normalized{};
        std::vector<std::vector<char>> matrix{};
        for (size_t i{ 0 }; i < r; ++i) {
            std::string line = n.substr(i * c, c);
            std::vector<char> l{};
            for (size_t j{ 0 }; j < line.size(); ++j) {
                l.push_back(line[j]);
            }
            if (line.size() < c) {
                // add more
                for (size_t j{ 0 }; j < c - line.size(); ++j) {
                    l.push_back(' ');
                }
            }
            matrix.push_back(l);
        }

        for (size_t j{ 0 }; j < c; ++j) {
            std::string enc_line{};
            for (size_t i{ 0 }; i < r; ++i) {
                normalized.push_back(matrix[i][j]);
                enc_line.push_back(matrix[i][j]);
            }
            if (j < c - 1) {
                normalized.push_back(' ');
                enc_line.push_back(' ');
            }
            std::cout << std::format("enc {}\n", enc_line);
        }

        std::cout << std::format("'{}' -> '{}'\n", i, normalized);
        return normalized;
    }
}

namespace crypto_square {
    class cipher {
    public:
        cipher(const std::string& i = ""s);
        std::string normalized_cipher_text() const;
    private:
        std::string m_normalized_text{};
    };

    cipher::cipher(const std::string& i) : m_normalized_text{ normalize(i) }
    {}
    std::string cipher::normalized_cipher_text() const
    {
        return m_normalized_text;
    }
}  // namespace crypto_square

int main() {
    //crypto_square::cipher("8 character plaintext results in 3 chunks, the last one with a trailing space.").normalized_cipher_text();
    crypto_square::cipher("If man was meant to stay on the ground, god would have given us roots.").normalized_cipher_text();
    //crypto_square::cipher("This is fun!").normalized_cipher_text();
    //crypto_square::cipher("Chill out.").normalized_cipher_text();
    //crypto_square::cipher("@1,%!").normalized_cipher_text();
    return 0;
}