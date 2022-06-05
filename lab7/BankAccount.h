// Copyright (c) Nick Rybicki, 03/29/2022

#ifndef BANKACCOUNTH
#define BANKACCOUNTH

#include <string>

class BankAccount {
    public:
        // Constructors
        BankAccount(std::string newName = "", double amt1 = 0, double amt2 = 0);

        // Functions
        void SetName(std::string newName);
        std::string GetName();
        void SetChecking(double amt);
        double GetChecking();
        void SetSavings(double amt);
        double GetSavings();
        void DepositChecking(double amt);
        void DepositSavings(double amt);
        void WithdrawChecking(double amt);
        void WithdrawSavings(double amt);
        void TransferToSavings(double amt);
   
   private:
        std::string name;
        double savingsBalance;
        double checkingBalance;
};

#endif