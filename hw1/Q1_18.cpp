// Purpose: determine if the user inputted number is even or odd
// Copyright by Nick Rybicki, 2/17

#include <iostream>

int main() {

   /* Type your code here. */
   // initialize user number variable
   int userNum;
   
   // prompt user for int input
   std::cout << "Enter an integer number" << std::endl;
   
   // retrieve and store user input
   std::cin >> userNum;
   
   // determine if number is odd or even
   // last bit = 0 - even; last bit = 1 - odd
   // initialize mask (W=32 b/c int = -2^32 to 2^(32)-1
   int mask = 1;
   bool isOdd = userNum & mask;
   
   // display result using if statement
   if (isOdd)
      std::cout << userNum << " is an odd number." << std::endl;
   else
      std::cout << userNum << " is an even number." << std::endl;

   return 0;
}
