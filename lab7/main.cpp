// Copyright (c) Nick Rybicki, 03/29/2022
// Purpose: program to manage checking and savings accounts

#include <iostream>
#include <iomanip>
// #include "BankAccount.h" // used for 11.38 in Zybook
#include "Bank.h"
using namespace std;

int main() {
   /* main.cpp file lines for 11.38 in Zybook
   *
   BankAccount account("Mickey", 500.00, 1000.00);
   account.SetChecking(500);
   account.SetSavings(500);
   account.WithdrawSavings(100);
   account.WithdrawChecking(100);
   account.TransferToSavings(300);

   std::cout << account.GetName() << std::endl;
   std::cout << std::fixed << std::setprecision(2);
   std::cout << account.GetChecking() << std::endl;
   std::cout << account.GetSavings() << std::endl;
   *
   */
  
   // main.cpp file lines for 11.39 in Zybook
   Bank bank("Chase");
   bank.AddCustomer(BankAccount("Tara", 500.00, 1000.00));
   bank.AddCustomer(BankAccount("Norm", 100.00, 300.00));
   bank.AddCustomer(BankAccount("Joe", 800.00, 400.00));

   std::cout << bank.GetBankName() << " has "<< bank.GetSizeofBank() << " customer(s)." << std::endl;
   std::cout << std::fixed << std::setprecision(2);
   std::cout << "Total savings amount : " << bank.GetTotalSavings() << std::endl;
   std::cout << "Total checking amount : " << bank.GetTotalChecking() << std::endl;
   std::cout << "The richest customer : " << bank.GetTheRichestCustomer().GetName() << std::endl;

   bank.DropCustomer("Tara");
   std::cout << "The second richest customer : " << bank.GetTheRichestCustomer().GetName() << std::endl;
   
   return 0;
}
