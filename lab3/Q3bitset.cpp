// Copyright (c) Nick Rybicki
#include <iostream>
#include <bitset>

int main() {
    // 1. Define a 16-bit length bitset object named test_number and assign 256U (2p)
    std::bitset<16> test_number(256U);

    // 2. Print how many bits are true (on)  in the test_number (2p)
    std::cout << test_number.count() << std::endl;

    // 3. Print the index of the bits which are on in test_number (3p)
    for (int i = 0; i < test_number.size(); i++) {
        if (test_number[i] == 1)
            std::cout << i << std::endl;
    }

    // 4. Apply 2 right shifts to the test_number and print the new value as in unsigned long type (3p)
    std::cout << (test_number >> 2).to_ulong() << std::endl;

    return 0;
}
