#include <iostream>
#include <memory>
#include <stdexcept>
#include <utility>
#include <algorithm>
using namespace std;

// int[]-based version (so we can show off unique_ptr)
class Matrix {
public:
    Matrix(size_t rows, size_t cols) : m_rows{ rows }, m_cols{ cols }, m_m{ make_unique<int[]>(rows * cols) } {}
    ~Matrix() noexcept {}
    Matrix(const Matrix& other) : m_rows{ other.m_rows }, m_cols{ other.m_cols }, m_m{ make_unique<int[]>(other.m_rows * other.m_cols) } {
        std::copy(other.m_m.get(), other.m_m.get() + (m_rows * m_cols), m_m.get());
    }
    Matrix& operator=(const Matrix& other) {
        m_rows = other.m_rows;
        m_cols = other.m_cols;
        m_m = make_unique<int[]>(m_rows * m_cols);
        std::copy(other.m_m.get(), other.m_m.get() + (m_rows * m_cols), m_m.get());
        return *this;
    }
    Matrix(Matrix&& other) noexcept : m_rows{ std::exchange(other.m_rows, 0) }, m_cols{ std::exchange(other.m_cols, 0) }, m_m{ std::move(other.m_m) } {}
    Matrix& operator=(Matrix&& other) noexcept {
        if (this != &other) {
            m_rows = std::exchange(other.m_rows, 0);
            m_rows = std::exchange(other.m_rows, 0);
            m_m = std::move(other.m_m);
        }
        return *this;
    }
    int& operator()(int row, int col) {
        if (row >= m_rows || col >= m_cols) {
            throw std::out_of_range("Index out of bounds");
        }
        return m_m[index(col, row)];
    }
    friend Matrix& operator+(const Matrix& m1, const Matrix& m2) {
        if (m1.m_rows != m2.m_rows || m1.m_cols != m2.m_cols) {
            throw std::invalid_argument("Matrix size mismatch");
        }
        Matrix r{m1};
        for (auto i{0}; i < m1.m_cols * m1.m_rows; ++i) {
            m1.m_m[i] += m2.m_m[i];
        }
        return r;
    }
    friend Matrix& operator*(const Matrix& m1, const Matrix& m2) {
        if (m1.m_rows != m2.m_rows || m1.m_cols != m2.m_cols) {
            throw std::invalid_argument("Matrix size mismatch");
        }
        Matrix r{ m1 };
        for (auto i{ 0 }; i < m1.m_cols * m1.m_rows; ++i) {
            m1.m_m[i] *= m2.m_m[i];
        }
        return r;
    }
    // TODO: iterator
private:
    size_t m_rows;
    size_t m_cols;
    std::unique_ptr<int[]> m_m{};

    constexpr inline const int index(int row, int col) const noexcept {
        return row + col * m_cols;
    }
};

int main() {
    return 0;
}
