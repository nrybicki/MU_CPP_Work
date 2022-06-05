// Copyright (c) Nick Rybicki, 2/22

#include <iostream>
#include "functions.h"
using namespace std;

int main() {
    // Q5 part 2
    // CheckOrder Test 1
    cout << "100 200 300 400" << endl;
    cout << CheckOrder(100, 200, 300, 400) << endl;

    // CheckOrder Test 2
    cout << "400 300 200 100" << endl;
    cout << CheckOrder(400, 300, 200, 100) << endl;

    // CheckOrder Test 3
    cout << "100 500 300 400" << endl;
    cout << CheckOrder(100, 500, 300, 400) << endl;


    // Q5 part 3 - Test overloaded functions
    // Q5 part 5 - update test cases
    cout << "a b z c" << endl;
    cout << CheckOrder('a', 'b', 'z', 'c') << endl;

    cout << "bat hat mat sat" << endl;
    cout << CheckOrder("bat", "hat", "mat", "sat") << endl;

    cout << "12.8 6.94 3.01 0.67" << endl;
    cout << CheckOrder(12.8, 6.94, 3.01, 0.67) << endl;


    return 0;
}
