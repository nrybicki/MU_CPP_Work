// Copyright (c) Nick Rybicki, 3/5/2022

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <bitset>
#include <iomanip>
#include "functionsPart1.h"
using namespace std;

void listNames(const vector<string>& nurses) {
    cout << "--- Names of Nurses ---" << endl;
    for (string name : nurses) {
        if (!name.empty())
            cout << name << endl;
        else
            break;
    }
}

void printMenu() {
    cout << setfill('-') << setw(32) << "" << endl;
    cout << " Nurse Shift Query Application" << endl;
    cout << setfill('-') << setw(32) << "" << endl;
    cout << " 1 List shift days of the nurse" << endl;
    cout << " 2 List nurses for the day" << endl;
    cout << " 3 List days that all nurses work" << endl;
    cout << " 4 List days no nurse works" << endl;
    cout << " 5 List names of nurses" << endl;
    cout << "-1 Exit" << endl;
    cout << setfill('-') << setw(32) << "" << endl;
}

// if needed, add other user-defined functions here
