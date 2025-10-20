#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <unordered_set>
#include <utility>

using namespace std;

class Solution {
    struct intPairHashFunction {
        size_t operator()(const pair<int, int>& x) const
        {
            return x.first ^ x.second;
        }
    };
    unordered_set<pair<int, int>, intPairHashFunction> processed{};
public:
    void rotate(vector<vector<int>>& matrix) {
        for (size_t i = 0; i < matrix.size(); i++) {
            auto& row = matrix[i];
            for (size_t j = 0; j < row.size(); j++) {
                if (processed.find({ i, j }) != processed.end()) continue;

                // 0, 0 -> 0, 2
                // 0, 1 -> 1, 2
                // 0, 2 -> 2, 2
                // 1, 0 -> 0, 1
                // 1, 1 -> 1, 1
                // 1, 2 -> 2, 1
                // 2, 0 -> 0, 0
                // 2, 1 -> 1, 0
                // 2, 2 -> 2, 0
                // newRow = column
                // newColumn = size - row
                int newRow = j;
                int newColumn = (matrix.size() - 1) - i;
                printf("swapping %d, %d (%d) and %d, %d (%d)\n", i, j, matrix[i][j], newRow, newColumn, matrix[newRow][newColumn]);

                int temp = matrix[newRow][newColumn];
                matrix[newRow][newColumn] = matrix[i][j];
                matrix[i][j] = temp;
                processed.emplace(newRow, newColumn);
            }
        }
    }
};

static void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& v : matrix) {
        for (size_t i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }
}

static void test1() {
    vector<vector<int>> matrix{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    Solution s;
    printMatrix(matrix);
    cout << "rotation...\n";
    s.rotate(matrix);
    // check output
    printMatrix(matrix);

    // expected [7,4,1],[8,5,2],[9,6,3]]

    printf("end\n");
}


static void runTests() {
    test1();
}

int main() {
    runTests();
    return 0;
}