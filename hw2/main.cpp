// Purpose: interactive menu that reads in input file and displays different
//  information regarding nurses and their schedules (HW2 Part2)
// Copyright (c) Nick Rybicki, 3/7/2022

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <bitset>
#include <iomanip>
#include "functions.h"
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
    vector<string> nursesVec(1);
    vector<bitset<7>> scheduleVec(1);

    // read file contents into vectors
    int index = -1;
    while (readfile.good()) {
        index++;
        if (index >= static_cast<int>(nursesVec.size())) {
            nursesVec.resize(nursesVec.size()+1);
            scheduleVec.resize(scheduleVec.size()+1);
        }
        readfile >> nursesVec.at(index);
        readfile >> scheduleVec.at(index);
    }

    // close file
    readfile.close();

    // insert vector data to array
    string nurses[index];
    bitset<7> schedule[index];
    for (int i = 0; i < index; i++) {
        nurses[i] = nursesVec.at(i);
        schedule[i] = scheduleVec.at(i);
    }


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
            case 1: listNurseShift(nurses, schedule, index);
            break;
            case 2: listNursesForDay(nurses, schedule, index);
            break;
            case 3: listDaysAllNurses(schedule, index);
            break;
            case 4: listDaysNoNurses(schedule, index);
            break;
            case 5: listNames(nurses, index);
            break;
            default: break;
        }
    }
    cout << "Bye!" << endl;

    return 0;
}
