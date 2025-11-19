#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        vector<vector<int>> shortest{};
        for (int i = 0; i < dungeon.size(); i++) {
            auto r = dungeon[0];
            vector<int> row{};
            for (int j = 0; j < r.size(); j++) {
                row.push_back(INT_MIN);
            }
            shortest.push_back(row);
        }
        
        int rows = dungeon.size() - 1;
        int columns = dungeon[0].size() - 1;

        // fill known row & column
        for (int i = columns; i >= 0 ; i--) {
            if (i < columns) {
                shortest[rows][i] = dungeon[rows][i] + shortest[rows][i + 1];
            }
            else {
                shortest[rows][i] = dungeon[rows][i];
            }
        }

        for (int i = rows; i >= 0; i--) {
            if (i < rows) {
                shortest[i][columns] = dungeon[i][columns] + shortest[i + 1][columns];
            }
            else {
                shortest[i][columns] = dungeon[i][columns];
            }
        }

        // fill rest with minimum from neighbouring
        for (int i = columns - 1; i>= 0; i--) {
            for (int j = rows - 1; j >= 0; j--) {
                shortest[i][j] = dungeon[i][j] + min(shortest[i + 1][j], shortest[i][j + 1]);
            }
        }

        return 0;
    }
};

static void test1() {
    vector<vector<int>> dungeon{
        {-2, -3, 3},
        {-5, -10, 1},
        {10, 30, -5}
    };

    Solution s;
    s.calculateMinimumHP(dungeon);
}

static void runTests() {
    test1();
}

int main() {
    runTests();
    return 0;
}