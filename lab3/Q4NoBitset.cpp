// Copyright (c) Nick Rybicki
#include <iostream>

int main() {
    // 1. Define an unsigned short integer (either unsigned short int or uint16_t) variable named findMeInBinary (1p)
    uint16_t findMeInBinary;

    // 2. Get the value for findMeInBinary from the user (1p)
    std::cout << "Enter an unsigned integer:" << std::endl;
    std::cin >> findMeInBinary;

    std::cout << findMeInBinary << std::endl;

    // 3. Print the most significant bit of findMeInBinary using bitwise operators (4p)
    uint16_t mask = 1 << 15;
    if ((findMeInBinary & mask) == 0)
        std::cout << "0" << std::endl;
    else
        std::cout << "1" << std::endl;

    // 4. Print the second least significant bit of findMeInBinary using bitwise operators (4p)
    mask = 1 << 1;
    if ((findMeInBinary & mask) == 0)
        std::cout << "0" << std::endl;
    else
        std::cout << "1" << std::endl;

    return 0;
}
