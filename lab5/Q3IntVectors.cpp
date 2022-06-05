// Copyright (c) Nick Rybicki, 3/1/2022

#include <iostream>
#include <vector>
using namespace std;

void printVector(const vector<int>& vec) {
    for (auto i : vec) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    // Define two integer vectors named A and B
    vector<int> A;
    vector<int> B;

    // Add numbers (10, 20, 30, 40, 50, 60, 70, 80, 90) to the integer vector A
    for (int i = 10; i < 100; i += 10) {
        A.push_back(i);
    }
    cout << "A: ";
    printVector(A);

    // Add numbers (100,200,300) to the integer vector B
    for (int i = 100; i <= 300; i += 100) {
        B.push_back(i);
    }
    cout << "B: ";
    printVector(B);

    // Insert 25 as a third element to the vector A
    A.insert(A.begin()+2, 25);
    cout << "A: ";
    printVector(A);

    // Insert the first three elements of A to the beginning of the B
    B.insert(B.begin(), A.begin(), A.begin()+3);
    cout << "B: ";
    printVector(B);

    // Erase the second last element of B
    B.erase(B.end()-2);
    cout << "B: ";
    printVector(B);

    // Erase the numbers between the second and fifth element of A
    A.erase(A.begin()+1, A.begin()+5);
    cout << "A: ";
    printVector(A);

    // Sum the first and the last element of A
    cout << A.at(0) + A.at(A.size()-1) << endl;

    return 0;
}
