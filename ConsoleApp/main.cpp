#include <utility>
#include <string>
#include <iostream>

namespace robot_simulator {
    enum class Bearing {
        EAST = 0,
        SOUTH = 1,
        WEST = 2,
        NORTH = 3
    };

    class Robot {
    public:
        Robot();
        Robot(std::pair<int, int> position, Bearing bearing);
        const std::pair<int, int> get_position() const;
        Bearing get_bearing() const;
        void execute_sequence(const std::string& sequence);
        void turn_left();
        void turn_right();
        void advance();
    private:
        std::pair<int, int> m_pos{};
        Bearing m_bearing{};
    };

    Robot::Robot() : m_pos{ 0, 0 }, m_bearing{ Bearing::NORTH } {}

    Robot::Robot(std::pair<int, int> position, Bearing bearing) : m_pos{ position }, m_bearing{ bearing } {}

    const std::pair<int, int> Robot::get_position() const
    {
        return m_pos;
    }

    Bearing Robot::get_bearing() const
    {
        return m_bearing;
    }

    void Robot::execute_sequence(const std::string& sequence)
    {
        for (const auto& c : sequence) {
            if (c == 'A') advance();
            if (c == 'L') turn_left();
            if (c == 'R') turn_right();
        }
    }

    void Robot::turn_left()
    {
        int direction = (int)m_bearing;
        direction--;
        if (direction < 0) direction = 3;
        m_bearing = static_cast<Bearing>(direction);
    }

    void Robot::turn_right()
    {
        int direction = (int)m_bearing;
        direction++;
        if (direction > 3) direction = 0;
        m_bearing = static_cast<Bearing>(direction);
    }

    void Robot::advance()
    {
        if (m_bearing == Bearing::EAST) {
            m_pos.first++;
        }
        else if (m_bearing == Bearing::SOUTH) {
            m_pos.second--;
        }
        else if (m_bearing == Bearing::WEST) {
            m_pos.first--;
        }
        else {
            m_pos.second++;
        }
    }
}  // namespace robot_simulator

int main() {
    //const Robot r;
    //const std::pair<int, int> expected_robot_position{ 0, 0 };
    //REQUIRE(expected_robot_position == r.get_position());
    //REQUIRE(Bearing::NORTH == r.get_bearing());

    //const std::pair<int, int> robot_position{ -1, -1 };
    //const Bearing robot_bearing{ Bearing::SOUTH };
    //const Robot r{ robot_position, robot_bearing };
    return 0;
}