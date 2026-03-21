#include <iostream>
#include <format>
#include <random>
using namespace std;

void test1() {
    default_random_engine engine{};
    uniform_int_distribution randomizer{1, 6};

    auto turn{0};
    auto point{0};
    do {
        ++turn;
        auto d1 = randomizer(engine);
        auto d2 = randomizer(engine);
        cout << format("Player rolled {} + {} = {}\n", d1, d2, d1 + d2);
        auto sum = d1 + d2;

        if (turn == 1) {
            if (sum == 7 || sum == 11) {
                cout << "Player wins!\n";
                break;
            }
            else if (sum == 2 || sum == 3 || sum == 12) {
                cout << "Player loses!\n";
                break;
            }
            else {
                point = sum;
                cout << format("Player point is {}\n", point);
            }
        }
        else {
            if (sum == point) {
                cout << "Player wins!\n";
                break;
            }
        }
    } while (1);
}

int main() {
    test1();
    return 0;
}