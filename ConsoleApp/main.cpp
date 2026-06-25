#include <utility>
#include <string>
#include <iostream>
#include <cmath>

namespace darts {
    //If the dart lands outside the target, player earns no points(0 points).
    //If the dart lands in the outer circle of the target, player earns 1 point.
    //If the dart lands in the middle circle of the target, player earns 5 points.
    //If the dart lands in the inner circle of the target, player earns 10 points.
    //darts::score(-0.1f, -0.1f)
    int score(float x, float y) {
        float d = std::sqrt(x * x + y * y);
        if (d <= 1) return 10;
        if (d <= 5) return 5;
        if (d <= 10) return 1;
        return 0;
    }
}  // namespace darts

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