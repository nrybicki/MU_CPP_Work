// Copyright (c) Nick Rybicki, 3/1/2022

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
using namespace std;

int main() {
    // assign any variable names
    string filename;
    cout << "Enter a filename " << endl;
    cin >> filename;

    // verify that file can be read
    ifstream readfile(filename);
    if (!readfile.is_open()) {
        cout << "Could not open" << endl;
        return 1;
    }

    // initialize vector variables
    vector<string> lname(20);
    vector<string> fname(20);
    vector<int> mid1(20);
    vector<int> mid2(20);
    vector<int> finals(20);

    // read through file and assign values into corresponding vectors
    int index = -1;
    while (readfile.good()) {
        index++;
        readfile >> lname.at(index);
        readfile >> fname.at(index);
        readfile >> mid1.at(index);
        readfile >> mid2.at(index);
        readfile >> finals.at(index);
    }

    // close file
    readfile.close();

    // create new output file
    ofstream writefile("report.txt");

    // ensure the file was created
    if (!writefile.is_open()) {
        cout << "could not open the file" << endl;
        return 2;
    }

    // assign letter grade to each student by first calculating each student's exam average
    // also calculate the sum of exam scores to calculate average of each exam
    vector<char> ltrGrades(index);
    int mid1Sum = 0, mid2Sum = 0, finalsSum = 0;
    for (int i = 0; i < index; i++) {
        int examAvg = (mid1.at(i) + mid2.at(i) + finals.at(i)) / 3;
        mid1Sum += mid1.at(i);
        mid2Sum += mid2.at(i);
        finalsSum += finals.at(i);

        if (examAvg >= 90)
            ltrGrades.at(i) = 'A';
        else if (examAvg >= 80)
            ltrGrades.at(i) = 'B';
        else if (examAvg >= 70)
            ltrGrades.at(i) = 'C';
        else if (examAvg >= 60)
            ltrGrades.at(i) = 'D';
        else
            ltrGrades.at(i) = 'F';
    }

    // calcuate average of each exam
    double mid1Avg = (double) mid1Sum / index;
    double mid2Avg = (double) mid2Sum / index;
    double finalsAvg = (double) finalsSum / index;

    // write output to file
    int record_counter = 0;
    while (record_counter < index) {
        writefile << lname[record_counter] << "\t";
        writefile << fname[record_counter] << "\t";
        writefile << mid1[record_counter] << "\t";
        writefile << mid2[record_counter] << "\t";
        writefile << finals[record_counter] << "\t";
        writefile << ltrGrades[record_counter] << endl;
        record_counter++;
    }
    writefile << setprecision(4) << showpoint << "\nAverages: midterm1 " << mid1Avg << ", midterm2 " << mid2Avg << ", final " << finalsAvg << endl;

    // close the file
    writefile.close();

    return 0;
}
