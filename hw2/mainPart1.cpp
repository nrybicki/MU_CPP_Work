// Purpose: interactive menu that reads in input file and displays different
//  information regarding nurses and their schedules
// Copyright (c) Nick Rybicki, 3/5/2022

#include <iostream>
// include necessary libraries
#include "functionsPart1.h"
#include <string>
#include <fstream>
#include <vector>
#include <bitset>
#include <iomanip>
using namespace std;

int main() {
    // prompt user for filename
    string filename;
    cout << ">> Enter the file name with its extension:" << endl;
    cin >> filename;

    // check if file can be opened
    ifstream readfile(filename);
    if (!readfile.is_open()) {
        cout << "!!! Could not open the input file : " << filename << endl;
        return 1;
    }


    // initialize vectors for names and week schedule
    vector<string> nurses(5);
    vector<bitset<7>> schedule(5);

    // read file contents into vectors
    int index = -1;
    while (readfile.good()) {
        index++;
        if (index >= nurses.size()) {
            nurses.resize(nurses.size()*2);
            schedule.resize(schedule.size()*2);
        }
        readfile >> nurses.at(index);
        readfile >> schedule.at(index);
    }

    // close file
    readfile.close();


    // Run Main Program
    int menuChoice = 0;
    while (menuChoice != -1) {
        printMenu();
        cout << ">> Enter your choice:" << endl;
        cin >> menuChoice;
        if (menuChoice < -1 || menuChoice > 5) {
            cout << " !! Wrong choice !! Try again!" << endl;
            continue;
        }
        switch (menuChoice) {
            case 1: cout << "List shift days of the nurse" << endl;
                break;
            case 2: cout << "List nurses for the day" << endl;
                break;
            case 3: cout << "List days that all nurses work" << endl;
                break;
            case 4: cout << "List days no nurse works" << endl;
                break;
            case 5: listNames(nurses);
                break;
            default: break;
        }
    }
    cout << "Bye!" << endl;

    return 0;
}
