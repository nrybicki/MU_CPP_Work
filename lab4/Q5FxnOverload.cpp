// Copyright (c) Nick Rybicki, 2/22

#include <iostream>
using namespace std;

// Q5 part 4 - add functions' prototypes above main fxn
int CheckOrder(int num1, int num2, int num3, int num4);
int CheckOrder(const string& num1, const string& num2, const string& num3, const string& num4);
int CheckOrder(double num1, double num2, double num3, double num4);
int CheckOrder(char num1, char num2, char num3, char num4);

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

// Q5 part 4 - Move all functions below main
// Q5 part 1
int CheckOrder(int num1, int num2, int num3, int num4) {
    if (num1 > num2 && num2 > num3 && num3 > num4)
        return 1;
    else if (num4 > num3 && num3 > num2 && num2 > num1)
        return -1;
    else
        return 0;
}

// Q5 part 3
// overload CheckOrder for string type items
int CheckOrder(const string& num1, const string& num2, const string& num3, const string& num4) {
    if (num1 > num2 && num2 > num3 && num3 > num4)
        return 1;
    else if (num4 > num3 && num3 > num2 && num2 > num1)
        return -1;
    else
        return 0;
}
// overload CheckOrder for double type items
int CheckOrder(double num1, double num2, double num3, double num4) {
    if (num1 > num2 && num2 > num3 && num3 > num4)
        return 1;
    else if (num4 > num3 && num3 > num2 && num2 > num1)
        return -1;
    else
        return 0;
}
// overload CheckOrder for char type items
int CheckOrder(char num1, char num2, char num3, char num4) {
    if (num1 > num2 && num2 > num3 && num3 > num4)
        return 1;
    else if (num4 > num3 && num3 > num2 && num2 > num1)
        return -1;
    else
        return 0;
}
