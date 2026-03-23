#include <iostream>
#include <format>
#include <random>
using namespace std;

//int rollDice() {
//    static default_random_engine engine{};
//    static uniform_int_distribution randomizer{ 1, 6 };
//    auto d1 = randomizer(engine);
//    auto d2 = randomizer(engine);
//    cout << format("Player rolled {} + {} = {}\n", d1, d2, d1 + d2);
//    return  d1 + d2;
//}
//
//void test1() {
//    enum class Status { keepRolling, won, lost };
//    Status gameStatus{ Status::keepRolling };
//    int point{ 0 };
//
//    switch (const int sum{ rollDice() }) {
//        case 7:
//        case 11:
//            gameStatus = Status::won;
//            break;
//        case 2:
//        case 3:
//        case 12:
//            gameStatus = Status::lost;
//            break;
//        default:
//            point = sum;
//            cout << format("Point is {}\n", point);
//    }
//    while (gameStatus == Status::keepRolling) {
//        if (const int sum{ rollDice() }; sum == point) {
//            gameStatus = Status::won;
//            cout << format("Player won!\n");
//        }
//        else if (sum == 7) {
//            gameStatus = Status::lost;
//            cout << format("Player lost!\n");
//        }
//    }
//}

// Hanoi towers
void hanoi(int numberToMove, int startPeg, int targetPeg, int temporaryPeg) {
    if (numberToMove == 1) {
        cout << startPeg << " -> " << targetPeg << "\n";
        return;
    }
    hanoi(numberToMove - 1, startPeg, temporaryPeg, targetPeg);
    cout << startPeg << " -> " << targetPeg << "\n";
    hanoi(numberToMove - 1, temporaryPeg, targetPeg, startPeg);
}

int main() {
    hanoi(3, 1, 2, 3);
    return 0;
}