// Copyright (c) Nick Rybicki, 5/3/2022

#include <iostream>
using namespace std;

int foo(int var1) {
    int var3 = var1;
    // var3 = var3 + 20;
    asm("addl $20, -0x4(%rbp)");
    return var3;
}

int main() {
    int x = 9;
    int y = x * 30;
    int var = foo(x);
    cout << var << endl;

    return 0;
}
