//Given a number n, determine what the nth prime is.

#include <utility>
#include <stdexcept>
#include <cmath>
using namespace std;

namespace queen_attack {
    using Coordinates = std::pair<int, int>;

    class chess_board {
    public:
        chess_board(const Coordinates& w, const Coordinates& b) : m_white(w), m_black(b) {
            if (w.first < 0 || w.first > 7 || w.second < 0 || w.second > 7 ||
                b.first < 0 || b.first > 7 || b.second < 0 || b.second > 7 ||
                ((w.first == b.first) && (w.second == b.second))) {
                throw std::domain_error("Invalid coordinates");
            }
        }
        const Coordinates white() const {
            return m_white;
        }
        const Coordinates black() const {
            return m_black;
        }
        bool can_attack() const {
            if (m_white.first == m_black.first || m_white.second == m_black.second) {
                return true;
            }
            if (std::abs(m_white.first - m_black.first) == std::abs(m_white.second - m_black.second)) {
                return true;
            }

            return false;
        }
    private:
        Coordinates m_white{};
        Coordinates m_black{};
    };

    //const auto white = std::make_pair(2, 2);
    //const auto black = std::make_pair(0, 3);
    //const queen_attack::chess_board board{ white, black };
    //REQUIRE(white == board.white());
    //REQUIRE(black == board.black());
}  // namespace queen_attack


int main() {
    return 0;
}