// Purpose: write a program that calculates income tax
// Copyright by Nick Rybicki, 2/17

#include <iostream>
#include <cmath>

int main() {

   /* Type your code here. */
   // STEP 1
   // initialize variables for wages, taxable interest, unemployment comp., status, and taxes withheld
   int userWages, userInterest, userUnempComp, userStatus, userTaxWithheld;
   
   // store inputs to corresponding vars
   std::cin >> userWages;
   std::cin >> userInterest;
   std::cin >> userUnempComp;
   std::cin >> userStatus;
   std::cin >> userTaxWithheld;
   
   // calculate and display AGI
   int userAGI = userWages + userInterest + userUnempComp;
   std::cout << "AGI: $" << userAGI << std::endl;
   
   // display error if AGI exceeds $120,000 limit
   if (userAGI > 120000) {
      std::cout << "Error: Income too high to use this form" << std::endl;
      return 0;
   }
   
   
   // STEP 2
   // check userStatus is either 1 or 2, set to 1 if not
   if (userStatus != 2)
      userStatus = 1;
   
   // set deduction amount based on status, display to user
   int userDeduct = userStatus == 1 ? 12000 : 24000;
   std::cout << "Deduction: $" << userDeduct << std::endl;
   
   // calculate and display taxable income, AGI-deductions
   int userTaxIncome = userAGI - userDeduct < 0 ? 0 : userAGI - userDeduct;
   std::cout << "Taxable income: $" << userTaxIncome << std::endl;
   
   
   // STEP 3
   // calculate and display federal tax amount
   double userFedTax;
   switch (userStatus) {
      case 1:
         if (userTaxIncome <= 10000)
            userFedTax = userTaxIncome * 0.1;
         else if (userTaxIncome <= 40000)
            userFedTax = 1000 + (userTaxIncome - 10000) * 0.12;
         else if (userTaxIncome <= 85000)
            userFedTax = 4600 + (userTaxIncome - 40000) * 0.22;
         else
            userFedTax = 14500 + (userTaxIncome - 85000) * 0.24;
      break;
      case 2:
         if (userTaxIncome <= 20000)
            userFedTax = userTaxIncome * 0.1;
         else if (userTaxIncome <= 80000)
            userFedTax = 2000 + (userTaxIncome - 20000) * 0.12;
         else
            userFedTax = 9200 + (userTaxIncome - 80000) * 0.22;
      break;
   }
   std::cout << "Federal tax: $" << round(userFedTax) << std::endl;
   
   
   // STEP 4
   // calculate and display tax due, display refund if applicable
   double userTaxDue = userFedTax - userTaxWithheld;
   if (userTaxDue < 0)
      std::cout << "Tax refund: $" << round(userTaxDue) * -1 << std::endl;
   else
      std::cout << "Taxes Owed: $" << round(userTaxDue) << std::endl;

   return 0;
}
