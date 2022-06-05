#include <iostream>

int main() {
    char ch = 'A';
    while (ch <= 'Z') {
        std::cout << ch << ":" << int(ch) << std::endl;
        ch = ch + 1;
    }

    return 0;
}
