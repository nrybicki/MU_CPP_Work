// Copyright (c) Nick Rybicki, 2/22

#include <iostream>
#include <cctype>
using namespace std;

string onlyAlpha(string userStr) {
    string newStr = "";

    for (int i = 0; i < userStr.size(); i++) {
        if (isalpha(userStr.at(i)))
            newStr += userStr.at(i);
    }

    return newStr;
}

int main() {

    cout << "This !$ @ sentence." << endl;
    cout << onlyAlpha("This !$ @ sentence.") << endl;

    cout << "-Hello, 1 world$!" << endl;
    cout << onlyAlpha("-Hello, 1 world$!") << endl;
    
    cout << "Look!    Multiple spaces." << endl;
    cout << onlyAlpha("Look!    Multiple spaces.") << endl;
    
    cout << "flying" << endl;
    cout << onlyAlpha("flying") << endl;


    return 0;
}
