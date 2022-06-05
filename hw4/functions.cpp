// Copyright (c) Nick Rybicki, 4/29/2022
// Purpose: Query application for airports database

#define MYSQLPP_MYSQL_HEADERS_BURIED
#include <mysql++/mysql++.h>
#include <string>
#include <iostream>
#include <iomanip>
#include "functions.h"
using namespace std;

/* Constructor
*   Creates new functions object to query Airports database
*/
functions::functions(string database, string server, string userID,
        string password) {
    functions::database = database;
    functions::server = server;
    functions::userID = userID;
    functions::password = password;
}

/* Display menu function
*   called in main to display function
*/
void functions::displayMenu() {
    cout << setfill('-') << setw(32) << "" << endl;
    cout << setfill(' ') << setw(3) << "" << "Airports Query Application";
    cout << setfill(' ') << setw(3) << "" << endl;
    cout << setfill('-') << setw(32) << "" << endl;
    cout << "1. Find airports in Canada by city" << endl;
    cout << "2. Find airports in Canada by city and altitude" << endl;
    cout << "3. Summary report on airports in Canada by average function";
    cout << endl;
    cout << "4. Summary report on airports in Canada by grouping" << endl;
    cout << "5. Exit" << endl;
}

/* Menu option 1 - Select based on 1 criterion
*   Select airports in Canada based on user selected City name
*/
void functions::select1Criteria() {
    cout << "Here are some city names in Canada:" << endl;
    // create and parse initial display query and store
    mysqlpp::Connection myDB(database.c_str(), server.c_str(), userID.c_str(),
        password.c_str());
    mysqlpp::Query queryInit = myDB.query();
    queryInit << "SELECT City FROM Airports WHERE Country='Canada' LIMIT 5;";
    queryInit.parse();
    mysqlpp::StoreQueryResult resultInit = queryInit.store();
    for (const auto& row : resultInit) {
        for (const auto& col : row) {
            cout << col;
        }
        cout << endl;
    }

    // take user input and complete new query with input
    string city;
    cout << "Enter the city name in Canada >> ";
    cin.ignore();;
    getline(cin, city);
    mysqlpp::Query query1Crit = myDB.query();
    query1Crit << "SELECT Name, Code, City, Country FROM Airports WHERE ";
    query1Crit << "Country='Canada' AND City='%0';";
    query1Crit.parse();
    mysqlpp::StoreQueryResult result = query1Crit.store(city);
    // display query results
    if (result.num_rows() == 0) {
        cout << "No airports matching those criteria" << endl;
    } else {
        cout << "Here are the airports in " << city << endl;
        short int colSizes[4] = {30, 6, 20, 7};
        cout << left << setfill(' ') << setw(colSizes[0]) << "Name";
        cout << setw(colSizes[1]) << "Code" << setw(colSizes[2]) << "City";
        cout << setw(colSizes[3]) << "Country" << endl;
        short int colCount;
        for (const auto& row : result) {
            colCount = 0;
            for (const auto& col : row) {
                cout << setw(colSizes[colCount++]) << col;
            }
            cout << endl;
        }
    }
    cout << endl;
}

/* Menu option 2 - Select based on 2 criteria
*   Select airports in Canada based on user selected City name and maximum
*   Altitude level
*/
void functions::select2Criteria() {
    // prompt and store user input for city name and altitude level
    string city;
    cout << "Enter a city name in Canada >> ";
    cin >> city;
    float altitude;
    cout << "Enter a maximum altitude >> ";
    cin >> altitude;

    // complete query
    mysqlpp::Connection myDB(database.c_str(), server.c_str(), userID.c_str(),
        password.c_str());
    mysqlpp::Query query2Crit = myDB.query();
    query2Crit << "SELECT Name, Code, Altitude, City, Country FROM Airports ";
    query2Crit << "WHERE Country='Canada'";
    query2Crit << " AND City='%0' AND Altitude<%1;";
    query2Crit.parse();
    mysqlpp::StoreQueryResult result = query2Crit.store(city, altitude);

    // display query results
    if (result.num_rows() == 0) {
        cout << "No airports matching those criteria" << endl;
    } else { 
        cout << "Here are the airports in " << city << " below " << altitude;
        cout << endl;
        short int colSizes[5] = {30, 6, 10, 20, 7};
        cout << left << setfill(' ') << setw(colSizes[0]) << "Name";
        cout << setw(colSizes[1]) << "Code" << setw(colSizes[2]) << "Altitude";
        cout << setw(colSizes[3]) << "City";
        cout << setw(colSizes[4]) << "Country" << endl;
        short int colCount;
        for (const auto& row : result) {
            colCount = 0;
            for (const auto& col : row) {
                cout << setw(colSizes[colCount++]) << col;
            }
            cout << endl;
        }
        }
    cout << endl;
}

/* Menu option 3 - Summary of airports using aggregate function
*   Prints a summary of airports in Canada using average aggregate function
*   using user inputted column
*/
void functions::aggregate() {
    // display averageable columns and prompt user for input
    string column;
    bool colValid = false;
    do {
        cout << "Columns to choose from:" << endl;
        cout << "Latitude\nLongitude\nAltitude\nTimezone" << endl;
        cout << "Select column to average >> ";
        cin >> column;
        if (column == "Latitude" || column == "Longitude"
                || column == "Altitude" || column == "Timezone")
            colValid = true;
    } while (!colValid);

    // complete query
    mysqlpp::Connection myDB(database.c_str(), server.c_str(), userID.c_str(),
        password.c_str());
    mysqlpp::Query queryAvg = myDB.query();
    queryAvg << "SELECT AVG(%0) FROM Airports WHERE Country='Canada' AND ";
    queryAvg << "City='Toronto';";
    queryAvg.parse();
    mysqlpp::StoreQueryResult result = queryAvg.store(column);

    // display results
    cout << "Average " << column << " for airports in Toronto, Canada: ";
    for (const auto& row : result) {
        for (const auto& col : row) {
            cout << col;
        }
        cout << endl;
    }
    cout << endl;
}

/* Menu option 4 - Summary of airports using grouping
*   Prints a summary of the number of airports in Canada grouped by Timezone
*/
void functions::group() {
    cout << "Summary of airports in Canada grouped by timezone" << endl;

    // complete query
    mysqlpp::Connection myDB(database.c_str(), server.c_str(), userID.c_str(),
    password.c_str());
    mysqlpp::Query queryGroup = myDB.query();
    queryGroup << "SELECT Timezone, COUNT(*) FROM Airports WHERE Country=";
    queryGroup << "'Canada' GROUP BY Timezone;";
    queryGroup.parse();
    mysqlpp::StoreQueryResult result = queryGroup.store();

    // display results
    cout << left << setfill(' ') << setw(10) << "Timezone" << setw(10);
    cout << "COUNT(*)" << endl;
    for (const auto& row : result) {
        for (const auto& col : row) {
            cout << setw(10) << col;
        }
        cout << endl;
    }
    cout << endl;
}
