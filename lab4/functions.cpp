// Copyright (c) Nick Rybicki, 2/22

#include <iostream>
using namespace std;

int CheckOrder(int num1, int num2, int num3, int num4) {
    if (num1 > num2 && num2 > num3 && num3 > num4)
        return 1;
    else if (num4 > num3 && num3 > num2 && num2 > num1)
        return -1;
    else
        return 0;
}

int CheckOrder(const string& num1, const string& num2, const string& num3, const string& num4) {
    if (num1 > num2 && num2 > num3 && num3 > num4)
        return 1;
    else if (num4 > num3 && num3 > num2 && num2 > num1)
        return -1;
    else
        return 0;
}

int CheckOrder(double num1, double num2, double num3, double num4) {
    if (num1 > num2 && num2 > num3 && num3 > num4)
        return 1;
    else if (num4 > num3 && num3 > num2 && num2 > num1)
        return -1;
    else
        return 0;
}

int CheckOrder(char num1, char num2, char num3, char num4) {
    if (num1 > num2 && num2 > num3 && num3 > num4)
        return 1;
    else if (num4 > num3 && num3 > num2 && num2 > num1)
        return -1;
    else
        return 0;
}
