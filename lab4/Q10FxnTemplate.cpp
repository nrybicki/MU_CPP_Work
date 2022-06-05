// Copyright (c) Nick Rybicki, 2/22

#include <iostream>
using namespace std;

template<typename T>
int GenericCheckOrder(T val1, T val2, T val3, T val4);

int main() {
    // CheckOrder tests from Q5
    cout << "100 200 300 400" << endl;
    cout << GenericCheckOrder(100, 200, 300, 400) << endl;

    cout << "400 300 200 100" << endl;
    cout << GenericCheckOrder(400, 300, 200, 100) << endl;

    cout << "100 500 300 400" << endl;
    cout << GenericCheckOrder(100, 500, 300, 400) << endl;

    cout << "a b z c" << endl;
    cout << GenericCheckOrder('a', 'b', 'z', 'c') << endl;

    cout << "bat hat mat sat" << endl;
    cout << GenericCheckOrder("bat", "hat", "mat", "sat") << endl;

    cout << "12.8 6.94 3.01 0.67" << endl;
    cout << GenericCheckOrder(12.8, 6.94, 3.01, 0.67) << endl;

    return 0;
}

template<typename T>
int GenericCheckOrder(T val1, T val2, T val3, T val4) {
    if (val1 > val2 && val2 > val3 && val3 > val4)
        return 1;
    else if (val4 > val3 && val3 > val2 && val2 > val1)
        return -1;
    else
        return 0;
}
