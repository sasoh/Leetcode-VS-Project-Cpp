#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <utility>
#include <numeric>
#include <format>
using namespace std;

int main() {
    auto m = unordered_map<string, vector<int>>{
        {"Susan", {92, 85, 100}},
        {"Eduardo", {83, 95, 79}},
        {"Azizi", {91, 89, 82}},
        {"Pantipa", {97, 91, 92}},
    };

    auto totalAvg{0.0};
    for (const pair<string, vector<int>>& i : m) {
        auto avg{ (accumulate(i.second.cbegin(), i.second.cend(), 0.0)) / i.second.size() };
        cout << format("Average for {} is {:.2f}\n", i.first, avg);
        totalAvg += avg;
    }

    auto classAvg{ totalAvg / m.size() };
    cout << format("Class average is {:0.2f}\n", classAvg);

    return 0;
}