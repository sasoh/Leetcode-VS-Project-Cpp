#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <format>

using namespace std::string_literals;

namespace {
    int toMinutes(int h, int m) {
        return h * 60 + m;
    }
    int hours(int m) {
        if (m > 0) {
            return (m / 60) % 24;
        }

        int hours = m / 60;
        if (m % 60 != 0) {
            hours--;
        }
        int wrappedNegative = hours % 24;
        int positiveHours = 24 + wrappedNegative;
        int wrappedPositive = positiveHours % 24;
        return wrappedPositive;
    }
    int minutes(int m) {
        if (m > 0) {
            return m % 60;
        }
        else {
            return (60 + m % 60) % 60;
        }
    }
}

namespace date_independent {
    class clock {
    public:
        clock(int h, int m);
        static clock at(int h, int m);
        clock plus(int m);
        bool operator==(const clock& other) const {
            return (&other == this) || (m_h == other.m_h && m_m == other.m_m);
        }
        bool operator!=(const clock& other) const {
            return !operator==(other);
        }
        explicit operator std::string() const noexcept {
            std::ostringstream oss;
            oss << std::setfill('0') << std::setw(2) << m_h << ":" << std::setw(2) << m_m;
            return oss.str();
        }
    private:
        int m_h{};
        int m_m{};
    };

    clock::clock(int h, int m)
    {
        int total = toMinutes(h, m);
        m_h = hours(total);
        m_m = minutes(total);
    }

    clock clock::at(int h, int m)
    {
        return clock{ h, m };
    }
    clock clock::plus(int m)
    {
        int total = toMinutes(m_h, m_m) + m;
        m_h = hours(total);
        m_m = minutes(total);
        return *this;
    }
}  // namespace date_independent

int main() {
    //auto c = date_independent::clock::at(1, -40);
    //auto c = date_independent::clock::at(0, 45).plus(40);
    //{ 10, 3, -30, "09:33", "subtract to previous hour" },
    //auto c = date_independent::clock::at(10, 3).plus(-30);
    //std::cout << std::format("{}: {}\n", "09:33"s, static_cast<std::string>(c));
    //{ 10, 3, -70, "08:53", "subtract more than an hour" },
    //{ -1, 15, "23:15", "negative hour" },
    //auto c = date_independent::clock::at(-1, 15);
    //std::cout << std::format("{}: {}\n", "23:15"s, static_cast<std::string>(c));
    //{ -25, 0, "23:00", "negative hour rolls over" },
    std::cout << std::format("{}: {}\n", "23:00"s, static_cast<std::string>(date_independent::clock::at(-25, 0)));
    //{ 1, -160, "22:20", "negative minutes roll over" },
    std::cout << std::format("{}: {}\n", "22:20"s, static_cast<std::string>(date_independent::clock::at(1, -160)));
    return 0;
}