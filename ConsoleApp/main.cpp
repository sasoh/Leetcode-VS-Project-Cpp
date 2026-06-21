#include <vector>

namespace pascals_triangle {
    std::vector<std::vector<int>> generate_rows(int count)
    {
        std::vector<std::vector<int>> r{};

        for (size_t i{ 0 }; i < count; ++i) {
            std::vector<int> row{};
            for (size_t j{ 0 }; j <= i; ++j) {
                if (i == 0 || j == 0 || j == i) {
                    row.push_back(1);
                }
                else {
                    auto prev = r[i - 1];
                    row.push_back(prev[j - 1] + prev[j]);
                }
            }

            r.push_back(row);
        }

        return r;
    }
}  // namespace pascals_triangle

int main() {
    const std::vector<std::vector<int>> actual{ pascals_triangle::generate_rows(3) };
    return 0;
}