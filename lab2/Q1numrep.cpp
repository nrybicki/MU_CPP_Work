#include <iostream>
#include <bitset>

int main() {
    unsigned int num;
    std::cout << "Enter an unsigned integer number less than 2^16 in decimal: " << std::endl;
    std::cin >> num;
    std::cout << "Octal  :" << std::oct << num << std::endl;
    std::cout << "Hex    :" << std::hex << num << std::endl;
    std::cout << "Binary :" << std::bitset<16> (num) << std::endl;

    return 0;
}