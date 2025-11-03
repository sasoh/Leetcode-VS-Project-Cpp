#include <iostream>
#include <vector>

using namespace std;

class Solution {
    template <typename T>
    void printMatrix(vector<vector<T>>& m) {
        for (int i = 0; i < m.size(); i++) {
            for (int j = 0; j < m[i].size(); j++) {
                cout << m[i][j] << " ";
            }
            cout << endl;
        }
    }

public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> matrix{static_cast<unsigned>(m), vector<int>(static_cast<unsigned>(n), 0)};

        int counter = 0;
        for (const auto& wall : walls) {
            matrix[wall[0]][wall[1]] = 1;
            counter++;
        }

        for (const auto& guard : guards) {
            // A guard can see every cell in the four cardinal directions (north, east, south, or west) 
            // starting from their position unless obstructed by a wall or another guard.
            auto x = guard[0];
            auto y = guard[1];
            matrix[x][y] = 2;
            counter++;

            // north
            for (int i = y - 1; i >= 0; i--) {
                if (matrix[x][i] == 1 || matrix[x][i] == 2) break;
                matrix[x][i] = 3;
                counter++;
            }

            // east
            for (int i = x + 1; i < m; i++) {
                if (matrix[i][y] == 1 || matrix[i][y] == 2) break;
                matrix[i][y] = 3;
                counter++;
            }

            // south
            for (int i = y + 1; i < n; i++) {
                if (matrix[x][i] == 1 || matrix[x][i] == 2) break;
                matrix[x][i] = 3;
                counter++;
            }

            // west
            for (int i = x - 1; i >= 0; i--) {
                if (matrix[i][y] == 1 || matrix[i][y] == 2) break;
                matrix[i][y] = 3;
                counter++;
            }
        }

        //int unguarded = 0;
        //for (int i = 0; i < m; i++) {
        //    for (int j = 0; j < n; j++) {
        //        if (matrix[i][j] == 0) unguarded++;
        //    }
        //}
        printf("Counter = %d ung = %d\n", counter, m * n - counter);
                
        return 0;
    }
};

static void test1() {
    constexpr auto m = 4;
    constexpr auto n = 6;
    vector<vector<int>> guards{ {0, 0}, {1, 1}, {2, 3} };
    vector<vector<int>> walls{ {0, 1}, {2, 2}, {1, 4} };
    Solution s;
    cout << "Unguarded = " << s.countUnguarded(m, n, guards, walls) << endl;
}

static void test2() {
    constexpr auto m = 3;
    constexpr auto n = 3;
    vector<vector<int>> guards{ {1, 1} };
    vector<vector<int>> walls{ {0, 1}, {1, 0}, {1, 2}, {2, 1} };
    Solution s;
    cout << "Unguarded = " << s.countUnguarded(m, n, guards, walls) << endl;
}

static void runTests() {
    test1();
    //test2();
}

int main() {
    runTests();
    return 0;
}