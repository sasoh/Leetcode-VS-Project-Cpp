#include <iostream>
#include "IntegerSet.h"
using namespace std;

int main() {
    IntegerSet s1{};
    cout << s1.toString();

    IntegerSet s2{ {0, 1, 10, 20, 30, 50} };
    cout << s2.toString();

    IntegerSet s3{ {0, 1, 11, 12, 13, 14, 15} };
    cout << s3.toString();

    IntegerSet s4 = s2.unionOfSets(s3);
    cout << s4.toString();

    IntegerSet s5 = s2.intersectionOfSets(s3);
    cout << s5.toString();

    s5.insertElement(2);
    cout << s5.toString();

    return 0;
}