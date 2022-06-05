// Copyright (c) Nick Rybicki, 3/5/2022

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <bitset>
#include <iomanip>
#include "functions.h"
using namespace std;

/* function to list all of the names of the nurses present in the inputted
    vector */
void listNames(string nurses[], int size) {
    cout << "--- Names of Nurses ---" << endl;
    for (int i = 0; i < size; i++) {
        cout << nurses[i] << endl;
    }
}

/* function to print the menu for the user to select from */
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


// user-defined functions
/* function to convert a string to lowercase (except first letter) or uppercase
*/
string changeCase(string str, char choice) {
    string newStr = str;
    if (choice == 'l') {
        newStr.at(0) = toupper(newStr.at(0));
        for (int i = 1; i < static_cast<int>(newStr.size()); i++) {
            newStr.at(i) = tolower(newStr.at(i));
        }
    } else if (choice == 'u') {
        for (int i = 0; i < static_cast<int>(newStr.size()); i++) {
            newStr.at(i) = toupper(newStr.at(i));
        }
    }
    return newStr;
}

int findNurse(const string nurses[], string nurseName, int size) {
    for (int i = 0; i < size; i++) {
        if ((nurses[i]).compare(nurseName) == 0)
            return i;
    }
    return -1;
}


/* Additions for HW2 Part2 */
// Functions for menu options 1 - 4
/* function for menu option 1 - List shift days of the nurse
* 
* inputs:   nurses - vector of strings that hold the Nurses' names
*           schedule - vector of 7 digit binary number representing days working for each nurse
* output:   None (void), just prints the Nurse's shift to the console
*/
void listNurseShift(string nurses[], bitset<7> schedule[], int size) {
    string nurseSelect;
    int nurseIndex = -1;
    while (true) {
        cout << ">> Enter a nurse name:" << endl;
        cin >> nurseSelect;
        nurseIndex = findNurse(nurses, changeCase(nurseSelect, 'l'), size);
        if (nurseIndex != -1)
            break;
        else
            cout << "!!! No record for " << nurseSelect << endl;
    }  // once while loop is done, complete with printing shift days for nurse
    cout << "---- Shift Days ----" << endl;
    bitset<7> nurseSchedule = schedule[nurseIndex];
    if (nurseSchedule.none()) {
        cout << nurseSelect << " does not have a shift this week" << endl;
    } else {
        if (nurseSchedule[0] == 1)
            cout << "Sunday" << endl;
        if (nurseSchedule[1] == 1)
            cout << "Monday" << endl;
        if (nurseSchedule[2] == 1)
            cout << "Tuesday" << endl;
        if (nurseSchedule[3] == 1)
            cout << "Wednesday" << endl;
        if (nurseSchedule[4] == 1)
            cout << "Thursday" << endl;
        if (nurseSchedule[5] == 1)
            cout << "Friday" << endl;
        if (nurseSchedule[6] == 1)
            cout << "Saturday" << endl;
    }
}

/* function for menu option 2 - List nurses on shift for the day
* 
* inputs:   nurses - vector of strings that hold the Nurses' names
*           schedule - vector of 7 digit binary number representing days working for each nurse
* output:   None (void), just prints the Nurses names and how many nurses work on the specified day
*/
void listNursesForDay(string nurses[], bitset<7> schedule[], int size) {
    string dayChoice;
    while (true) {
        cout << ">> Enter a day of the week:" << endl;
        cin >> dayChoice;
        dayChoice = changeCase(dayChoice, 'u');
        if (dayChoice.compare("SUNDAY") == 0 ||
            dayChoice.compare("MONDAY") == 0 ||
            dayChoice.compare("TUESDAY") == 0 ||
            dayChoice.compare("WEDNESDAY") == 0 ||
            dayChoice.compare("THURSDAY") == 0 ||
            dayChoice.compare("FRIDAY") == 0 ||
            dayChoice.compare("SATURDAY") == 0) {
            break;
        }
    }
    int nurseCount = 0, daySelect;
    if (dayChoice.compare("SUNDAY") == 0) {
        daySelect = 0;
    } else if (dayChoice.compare("MONDAY") == 0) {
        daySelect = 1;
    } else if (dayChoice.compare("TUESDAY") == 0) {
        daySelect = 2;
    } else if (dayChoice.compare("WEDNESDAY") == 0) {
        daySelect = 3;
    } else if (dayChoice.compare("THURSDAY") == 0) {
        daySelect = 4;
    } else if (dayChoice.compare("FRIDAY") == 0) {
        daySelect = 5;
    } else {
        daySelect = 6;
    }
    cout << "---- Nurses ----" << endl;
    for (int i = 0; i < size; i++) {
        if (schedule[i][daySelect] == 1) {
            cout << nurses[i] << endl;
            nurseCount++;
        }
    }
    cout << nurseCount << " nurse(s) work(s) on " << dayChoice << endl;
}

/* function for menu option 3 - List days that all nurses work
* 
* inputs:   schedule - vector of 7 digit binary number representing days working for each nurse
* output:   None (void), just prints the days that ALL nurses work
*/
void listDaysAllNurses(bitset<7> schedule[], int size) {
    cout << "--- Days that all nurses work ---" << endl;
    bitset<7> daysAllNursesWork = schedule[0];
    for (int i = 1; i < size; i++) {
        daysAllNursesWork &= schedule[i];
    }
    if (daysAllNursesWork.none()) {
        cout << "There is no day that all nurses work!" << endl;
    } else {
        if (daysAllNursesWork[0] == 1)
            cout << "Sunday" << endl;
        if (daysAllNursesWork[1] == 1)
            cout << "Monday" << endl;
        if (daysAllNursesWork[2] == 1)
            cout << "Tuesday" << endl;
        if (daysAllNursesWork[3] == 1)
            cout << "Wednesday" << endl;
        if (daysAllNursesWork[4] == 1)
            cout << "Thursday" << endl;
        if (daysAllNursesWork[5] == 1)
            cout << "Friday" << endl;
        if (daysAllNursesWork[6] == 1)
            cout << "Saturday" << endl;
    }
}

/* function for menu option 4 - List days that no nurse works
* 
* inputs:   schedule - vector of 7 digit binary number representing days working for each nurse
* output:   None (void), just prints the days that NO nurses work
*/
void listDaysNoNurses(bitset<7> schedule[], int size) {
    cout << "--- Days no nurse works ---" << endl;
    bitset<7> daysNoNursesWork = schedule[0];
    for (int i = 1; i < size; i++) {
        daysNoNursesWork |= schedule[i];
    }
    if (daysNoNursesWork.all()) {
        cout << "Each day at least one nurse has a shift!" << endl;
    } else {
        if (daysNoNursesWork[0] == 0)
            cout << "Sunday" << endl;
        if (daysNoNursesWork[1] == 0)
            cout << "Monday" << endl;
        if (daysNoNursesWork[2] == 0)
            cout << "Tuesday" << endl;
        if (daysNoNursesWork[3] == 0)
            cout << "Wednesday" << endl;
        if (daysNoNursesWork[4] == 0)
            cout << "Thursday" << endl;
        if (daysNoNursesWork[5] == 0)
            cout << "Friday" << endl;
        if (daysNoNursesWork[6] == 0)
            cout << "Saturday" << endl;
    }
}
