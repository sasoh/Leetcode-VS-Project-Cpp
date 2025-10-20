#include <iostream>

static void test1() {
    printf("end\n");
}

static void runTests() {
    test1();
}

int main() {
    runTests();
    return 0;
}