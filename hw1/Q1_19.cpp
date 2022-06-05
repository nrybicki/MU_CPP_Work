// Purpose: determine if the number is a power of two or not
// Copyright by Nick Rybicki , 2/17

#include <iostream>
#include <bitset>

int main() {

   /* Type your code here. */
   // init unsigned user integer and binary rep
   unsigned int userNum;
   std::bitset<32> userBits;
   
   // prompt user for int input
   std::cout << "Enter an unsigned integer number:" << std::endl;
   
   // store user input and display as binary
   std::cin >> userNum;
   userBits = userNum;
   std::cout << userNum << " = " << userBits << std::endl;
   
   // determine if number is power of two
   // binary number is power of two if there is only one bit on (one 1, rest 0s)
   bool powerOfTwo = userBits.count() == 1;
   
   // display result
   if (powerOfTwo)
      std::cout << "This number is a power of two." << std::endl;
   else
      std::cout << "This number is NOT a power of two." << std::endl;

   return 0;
}
