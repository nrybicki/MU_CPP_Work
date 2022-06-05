// Copyright (c) Nick Rybicki, 4/29/2022

#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <mysql++/mysql++.h>
#include <string>

class functions {
 private:
    std::string database;
    std::string server;
    std::string userID;
    std::string password;

 public:
    functions(std::string database, std::string server, std::string userID,
        std::string password);
    void displayMenu();
    void select1Criteria();
    void select2Criteria();
    void aggregate();
    void group();
};

#endif
