//  The first time you turn on a robot, a random name is generated in the format of 
//  two uppercase letters followed by three digits, such as RX837 or BC811.
//  Every once in a while we need to reset a robot to its factory settings, which means 
//  that its name gets wiped. The next time you ask, that robot will respond with a new random name.
//  The names must be random: they should not follow a predictable sequence.
//  Using random names means a risk of collisions. Your solution must ensure that every existing robot has a unique name.
#include <iostream>
#include <string>
#include <format>
#include <random>
#include <sstream>
#include <iomanip>

namespace robot_name {
    class robot {
    public:
        robot();
        std::string name() const;
        void reset();
    private:
        std::string m_name{};
        std::default_random_engine m_rengine{};
    };

    robot::robot() : m_rengine{ (std::random_device())() } {
        reset();
    }
    std::string robot::name() const {
        return m_name;
    }
    void robot::reset() {
        std::uniform_int_distribution letterDistribution{ 0, 25 };
        std::uniform_int_distribution numberDistribution{ 0, 999 };

        char letter1 = static_cast<char>(static_cast<int>('A') + letterDistribution(m_rengine)); 
        char letter2 = static_cast<char>(static_cast<int>('A') + letterDistribution(m_rengine)); 
        int number = numberDistribution(m_rengine);

        std::ostringstream ss{};
        ss << letter1 << letter2;
        ss << std::setw(3) << std::setfill('0') << number;
        m_name = ss.str();
    }
}  // namespace robot_name

int main() {
    using namespace robot_name;
    robot r;
    std::cout << r.name();
    std::cout << '\n';
    r.reset();
    std::cout << r.name();
    std::cout << '\n';
    r.reset();
    std::cout << r.name();
    std::cout << '\n';
    r.reset();
    std::cout << r.name();
    std::cout << '\n';

    return 0;
}