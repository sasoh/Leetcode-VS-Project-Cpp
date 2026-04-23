#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

template<typename T>
vector<T> addVectors(const vector<T>& v1, const vector<T>& v2)
{
    vector<T> v{};
    transform(
        v1.cbegin(),
        v1.cend(),
        v2.cbegin(),
        back_inserter(v),
        [](const T& a, const T& b) { return a + b; }
    );
    return v;
}

int main() {
    vector<int> a{ 1, 2, 3, 4, 5, 6, 7 };
    vector<int> b{ 4, 5, 6, 7, 8, 9, 10 };
    auto sum = addVectors(a, b);
    ostream_iterator<int> out{ cout, " " };
    ranges::copy(sum, out);
    return 0;
}