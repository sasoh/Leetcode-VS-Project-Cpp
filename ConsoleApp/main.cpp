//  00001 = wink
//  00010 = double blink
//  00100 = close your eyes
//  01000 = jump
//  10000 = Reverse the order of the operations in the secret handshake.

#include <iostream>
#include <format>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std::string_literals;   

namespace secret_handshake {
    std::vector<std::string> commands(int n) {
        if (n == 0) return {};
        std::vector<std::string> r{};
        std::bitset<5> bits(n);
        static std::string p[] = {
            "wink"s,
            "double blink"s,
            "close your eyes"s,
            "jump"s,
        };
        for (size_t i{0}; i < 4; ++i) {
            if (!bits.test(i)) continue;
            r.push_back(p[i]);
        }
        if (bits.test(4)) {
            std::reverse(r.begin(), r.end());
        }        
        return r;
    }
}  // namespace secret_handshake

int main() {
    secret_handshake::commands(1);
    secret_handshake::commands(6);
    secret_handshake::commands(23);
    secret_handshake::commands(24);
    secret_handshake::commands(25);
    secret_handshake::commands(31);
    return 0;
}