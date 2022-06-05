// Purpose: program that checks a password for certain requirements
// Copyright by Nick Rybicki, 2/17

#include <iostream>
#include <cctype>

int main() {

   /* Type your code here. */
   // declare boolean variables
   bool pwLength = false, pwLetter = false, pwNumber = false, pwSpecChar = false;
   
   // get user input password
   std::string password;
   std::cin >> password;
   
   // use for loop to check conditions
   for (int i = 0; i < password.size(); i++) {
      if (isalpha(password[i]))
         pwLetter = true;
      
      if (isdigit(password[i]))
         pwNumber = true;
      
      if (ispunct(password[i]))
         pwSpecChar = true;
   }
   pwLength = (password.size() >= 8);
   
   // print appropriate error messages
   if (!pwLength)
      std::cout << "Too short" << std::endl;
   
   if (!pwLetter)
      std::cout << "Missing letter" << std::endl;
      
   if (!pwNumber)
      std::cout << "Missing number" << std::endl;
      
   if (!pwSpecChar)
      std::cout << "Missing special" << std::endl;
      
   if (pwLength && pwLetter && pwNumber && pwSpecChar)
      std::cout << "OK" << std::endl;

   return 0;
}
