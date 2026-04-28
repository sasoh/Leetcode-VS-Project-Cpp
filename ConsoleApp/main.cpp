#include <algorithm>
#include <format>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// A finance company is carrying out a study on the worst stock investments and would like to acquire a program to do so.
// The program must be able to analyze a chronological series of stock values in order to show the largest loss that it 
// is possible to make by buying a share at a given time t0 and by selling it at a later date t1.
// The loss will be expressed as the difference in value between t0 and t1.If there is no loss, the loss will be worth 0.

static auto maximumLoss(vector<int> prices) {
    auto maxLoss{ 0 };
    auto pivot{ prices[0] };
    auto pivotBottom{ prices[0] };
    for (int i = 1; i < prices.size(); ++i) {
        if (pivot < prices[i]) {
            maxLoss = min(maxLoss, pivotBottom - pivot);
            pivot = prices[i];
            pivotBottom = pivot;
        }
        if (pivotBottom > prices[i]) {
            pivotBottom = prices[i];
            maxLoss = min(maxLoss, pivotBottom - pivot);
        }
    }

    return maxLoss;
}

int main()
{
    cout << format("Maximum loss: {}, expected: {}\n", maximumLoss({ 3, 2, 4, 2, 1, 5 }), -3);
    cout << format("Maximum loss: {}, expected: {}\n", maximumLoss({ 5, 3, 4, 2, 3, 1 }), -4);
    cout << format("Maximum loss: {}, expected: {}\n", maximumLoss({ 1, 2, 4, 4, 5 }), 0);
    cout << format("Maximum loss: {}, expected: {}\n", maximumLoss({ 3, 2, 10, 7, 15, 14 }), -3);
}