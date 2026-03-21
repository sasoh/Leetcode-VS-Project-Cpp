#include <iostream>
#include <limits>
#include <format>

using std::cout;
using std::cin;
using std::format;

void test1() {
    //4.12
    //(Bar - Chart Printing Program) One interesting application of computers is to dis -
    //play graphs and bar charts.Write an application that reads five numbers between 1 and
    //30. For each number that’s read, your program should display the same number of adja -
    //cent asterisks.For example, if your program reads the number 7, it should display
    //******* .Display the bars of asterisks after you read all five numbers

    //vector<int> inputs{};
    //for (int i{0}; i < 5; ++i) {
    //    int x{0};
    //    do {
    //        cout << format("Input number {}: ", i + 1);
    //        cin >> x;
    //    } while (x < 1 || x > 30);
    //    inputs.push_back(x);
    //}

    //cout << "Graphs:\n";
    //for (int i{0}; i < inputs.size(); ++i) {
    //    cout << format("{:2}: ", inputs[i]);
    //    for (int j{0}; j < inputs[i]; ++j) {
    //        cout << '*';
    //    }
    //    cout << '\n';
    //}

    //// (Calculating the Value of π) 
    //double v{ 0.0 };
    //int terms{ 100 };
    //cout << format("Accuracy at {} terms\n", terms);
    //cout << format("{:<10} {:<}\n", "term", "pi");
    //for (int i{ 0 }, delim{ 1 }; i < terms; ++i) {
    //    int sign{ i % 2 == 1 ? -1 : 1 };
    //    v += sign * 4.0 / delim;
    //    delim += 2;
    //    cout << format("{:<10} {:<.8f}\n", i + 1, v);
    //}
}

int main() {
    test1();
    return 0;
}