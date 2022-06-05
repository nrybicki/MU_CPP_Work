// Copyright (c) Nick Rybicki, 3/5/2022

#ifndef FUNCTIONS1_H
#define FUNCTIONS1_H

#include <vector>
#include <string>
#include <bitset>
using namespace std;

// functions for HW2 Part1
void listNames(string nurses[], int size);
void printMenu();

// functions for HW2 Part2
void listNurseShift(string nurses[], bitset<7> schedule[], int size);
void listNursesForDay(string nurses[], bitset<7> schedule[], int size);
void listDaysAllNurses(bitset<7> schedule[], int size);
void listDaysNoNurses(bitset<7> schedule[], int size);

// user added functions
string toLowerStr(string str);
int findNurse(string nurses[], string nurseName, int size);

#endif