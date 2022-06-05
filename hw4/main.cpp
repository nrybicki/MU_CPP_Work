// Copyright (c) Nick Rybicki, 4/29/2022
// Purpose: Query application for airports database

#define MYSQLPP_MYSQL_HEADERS_BURIED
#include <mysql++/mysql++.h>
#include <string>
#include <iostream>
#include "functions.h"
using namespace std;

int main(int argc, char* argv[]) {
    functions airportsQuery("cse278", "localhost", "cse278",
            "wVQABsJFQhwNdNbr");

    short int menuChoice = 0;
    while (menuChoice != 5) {
        airportsQuery.displayMenu();
        cout << "Enter menu choice: ";
        cin >> menuChoice;
        if (menuChoice < 1 || menuChoice > 5) {
            cout << " !! Wrong choice !! Try again!!\n" << endl;
            continue;
        }
        switch (menuChoice) {
            // select with one criterion
            case 1: airportsQuery.select1Criteria();
            break;
            // select with two criteria
            case 2: airportsQuery.select2Criteria();
            break;
            // aggregate with one criterion
            case 3: airportsQuery.aggregate();
            break;
            // grouping
            case 4: airportsQuery.group();
            break;
            case 5: cout << "Goodbye! Enjoy your flight!!" << endl;
            break;
        }
    }

    return 0;
}
