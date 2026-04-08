#include <iostream>
#include "IntegerSet.h"
using namespace std;

int main() {
    IntegerSet empty{};
    cout << empty.toString();

    IntegerSet someValues{ {0, 1, 2, 3, 4} };
    cout << someValues.toString();

    IntegerSet otherValues{ {1, 5, 6, 7, 8} };
    cout << otherValues.toString();

    //IntegerSet unionOfValues = someValues.unionOfSets(otherValues);
    //cout << unionOfValues.toString();

    //IntegerSet intersectionOfValues = someValues.intersectionOfSets(otherValues);
    //cout << intersectionOfValues.toString();

    //intersectionOfValues.insertElement(2);
    //cout << intersectionOfValues.toString();

    cout << "Operator overloads:\n";
    IntegerSet sumValue = IntegerSet{someValues} + otherValues;
    cout << sumValue.toString();

    IntegerSet differenceValue = sumValue - otherValues;
    cout << differenceValue.toString();

    return 0;
}