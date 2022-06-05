// Copyright (c) Nick Rybicki, 03/29/2022

#ifndef BANK_H
#define BANK_H

#include <string>
#include <vector>
#include "BankAccount.h"

class Bank {
    public:
        // Constructors
        Bank(std::string name = "");

        // Functions
        void SetBankName(std::string newName);
        std::string GetBankName();
        void AddCustomer(BankAccount b);
        void DropCustomer(std::string name);
        int GetSizeofBank();
        double GetTotalSavings();
        double GetTotalChecking();
        BankAccount GetTheRichestCustomer();


    private:
        std::string bankName;
        std::vector<BankAccount> customers;

};

#endif