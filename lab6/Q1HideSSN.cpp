// Copyright (c) Nick Rybicki, 3/8/22

#include <iostream>
using namespace std;

void hideSSN(const char* ssn, char mask, char* maskedssn) {
    int i;
    for (i = 0; ssn[i] != '\0'; i++) {
        maskedssn[i] = ssn[i];
    }
    maskedssn[i] = '\0';
    for (int j = 0; j < i-4; j++) {
        if (maskedssn[j] != '-')
            maskedssn[j] = mask;
    }
}

int main() {
    char ssn[] = "123-45-7890";
    char ssnmasked[13];
    hideSSN(ssn, '#', ssnmasked);

    cout << ssnmasked << endl;

    char ssn2[] = "761-49-0352";
    char ssnmasked2[13];
    hideSSN(ssn2, '*', ssnmasked2);

    cout << ssnmasked2 << endl;

    return 0;
}
