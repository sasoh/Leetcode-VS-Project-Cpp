#include <iostream>
#include <memory>
#include <stdexcept>
#include <utility>
#include <algorithm>
#include <random>
#include <limits>
using namespace std;

// int[]-based version (so we can show off unique_ptr)
class Matrix {
public:
    Matrix(int rows, int cols) : m_rows{ rows }, m_cols{ cols }, m_m{ make_unique<double[]>(rows * cols) } {}
    ~Matrix() noexcept {}
    Matrix(const Matrix& other) : m_rows{ other.m_rows }, m_cols{ other.m_cols }, m_m{ make_unique<double[]>(other.m_rows * other.m_cols) } {
        std::copy(other.m_m.get(), other.m_m.get() + (m_rows * m_cols), m_m.get());
    }
    Matrix& operator=(const Matrix& other) {
        m_rows = other.m_rows;
        m_cols = other.m_cols;
        m_m = make_unique<double[]>(m_rows * m_cols);
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
    const int rows() const noexcept { return m_rows; }
    const int cols() const noexcept { return m_cols; }
    double& operator()(int row, int col) {
        if (row >= m_rows || col >= m_cols) {
            throw std::out_of_range("Index out of bounds");
        }
        return m_m[index(col, row)];
    }
    const double& operator()(int row, int col) const {
        if (row >= m_rows || col >= m_cols) {
            throw std::out_of_range("Index out of bounds");
        }
        return m_m[index(col, row)];
    }
    Matrix operator+(const Matrix& other) const {
        if (m_rows != other.m_rows || m_cols != other.m_cols) {
            throw std::invalid_argument("Matrix size mismatch");
        }
        Matrix r{ *this };
        for (auto i{ 0 }; i < m_cols * m_rows; ++i) {
            r.m_m[i] += other.m_m[i];
        }
        return r;
    }
    Matrix operator*(const Matrix& other) const {
        if (m_rows != other.m_rows || m_cols != other.m_cols) {
            throw std::invalid_argument("Matrix size mismatch");
        }
        Matrix r{ *this };
        for (auto i{ 0 }; i < m_cols * m_rows; ++i) {
            r.m_m[i] *= other.m_m[i];
        }
        return r;
    }
    // TODO: iterator
private:
    int m_rows;
    int m_cols;
    std::unique_ptr<double[]> m_m{};

    constexpr inline const int index(int row, int col) const noexcept {
        return row + col * m_cols;
    }
};

void fill_with_random(Matrix& m, double min_val, double max_val) {
    static default_random_engine e{};
    static uniform_real_distribution gen{ min_val, max_val };

    // TODO: update to use iterator instead of conventional array
    for (auto i{ 0 }; i < m.rows(); ++i) {
        for (auto j{ 0 }; j < m.cols(); ++j) {
            m(i, j) = gen(e);
        }
    }
}

void print_matrix(const Matrix& m) {
    for (auto i{ 0 }; i < m.rows(); ++i) {
        for (auto j{ 0 }; j < m.cols(); ++j) {
            std::cout << m(i, j);
            std::cout << (j < m.cols() - 1 ? " " : "\n");
        }
    }
}

int main() {
    Matrix m1{3, 2};
    std::cout << "M1:\n";
    print_matrix(m1);
    fill_with_random(m1, 3, 10);
    std::cout << "M1 after randomizing:\n";
    print_matrix(m1);

    auto m2(m1);
    std::cout << "M2 (copy):\n";
    print_matrix(m2);
    fill_with_random(m1, 0, 3);
    std::cout << "M1 after randomizing:\n";
    print_matrix(m1);

    std::cout << "M1 + M2:\n";
    print_matrix(m1 + m2);

    std::cout << "M1 * M2:\n";
    print_matrix(m1 * m2);

    return 0;
}