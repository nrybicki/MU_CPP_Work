// Copyright (c) Nick Rybicki, 3/8/22

#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    cout << argc << " arguments entered" << endl;
    for (int i = 0; i < argc; i++) {
        cout << argv[i] << endl;
    }

    return 0;
}
