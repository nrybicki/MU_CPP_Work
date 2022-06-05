// Purpose: determine if a number is a power of two or not, without bitset library
// Copyright by Nick Rybicki, 2/17

#include <iostream>

int main() {

   /* Type your code here. */
   // initialize user input
   unsigned int userNum;
   
   // prompt user for input
   std::cout << "Enter an unsigned integer number:" << std::endl;
   
   // store user input
   std::cin >> userNum;
   
   // calculate binary representation of userNum
   std::string userBits = "";
   int onBits = 0;
   
   for (int i = 0; i < 32; i++) {
      onBits += ((userNum >> i) & 1U) == 1 ? 1 : 0;
      
      std::string bit = std::to_string( ((userNum >> i) & 1U) == 1 ? 1 : 0 );
      userBits = bit + userBits;
   }
   
   // display userNum and binary rep
   std::cout << userNum << " = " << userBits << std::endl;
   
   // determine if the number is a power of two
   // counter var onBits, if onBits == 1 -> true, else false
   if (onBits == 1)
      std::cout << "This number is a power of two." << std::endl;
   else
      std::cout << "This number is NOT a power of two." << std::endl;

   return 0;
}
