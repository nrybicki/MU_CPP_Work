// Copyright (c) Nick Rybicki, 03/29/2022

#include <iostream>
#include <string>
#include "Bank.h"

/* set the bankName to parameter Name, default value is an empty string
*
* input: name - name of the bank to be assigned
*/
Bank::Bank(std::string name) {
    Bank::bankName = name;
}

/* set the bankName to parameter newName
*
* input: newName - value of the new name for the bank
* output: void
*/
void Bank::SetBankName(std::string newName) {
    Bank::bankName = newName;
}

/* return the bank name
*
* input: (none)
* output: returns the string bank name
*/
std::string Bank::GetBankName() {
    return Bank::bankName;
}

/* add new bank customer b to the vector customers
*
* input: b - BankAccount object to add to vector of customers
* output: void
*/
void Bank::AddCustomer(BankAccount b) {
    Bank::customers.push_back(b);
}

/* removes a customer (by name) from the bank customer list. If the customer
*   is not found in the list no customer should be dropped.
*
* input: name - name of the customer to be removed from the vector
* output: void
*/
void Bank::DropCustomer(std::string name) {
    for (int i = 0; i < static_cast<int>(Bank::customers.size()); i++) {
        if (Bank::customers.at(i).GetName() == name)
            Bank::customers.erase(Bank::customers.begin() + i);
    }
}

/* returns the total number of customers
*
* input: (none)
* output: returns the number of customers
*/
int Bank::GetSizeofBank() {
    return Bank::customers.size();
}

/* returns the total savings amount of the bank
*
* input: (none)
* output: returns the sum of all savings amounts of all customers in the bank
*/
double Bank::GetTotalSavings() {
    double totalSavings = 0;
    for (BankAccount customer : Bank::customers) {
        totalSavings += customer.GetSavings();
    }
    return totalSavings;
}

/* returns the total checking amount of the bank
*
* input: (none)
* output: returns the sum of all checking amounts of all customers in the bank
*/
double Bank::GetTotalChecking() {
    double totalChecking = 0;
    for (BankAccount customer : Bank::customers) {
        totalChecking += customer.GetChecking();
    }
    return totalChecking;
}

/* returns the bank account that has the most money (checking + savings) in
*   the customer's account. If there is no registered customer in the bank,
*   it returns an empty bank account object.
*
* input: (none)
* output: returns a BankAccount object of the customer with the most money
*/
BankAccount Bank::GetTheRichestCustomer() {
    if (GetSizeofBank() == 0) {
        return BankAccount();
    }
    int richestCustomer = 0, i;
    double acctTotal = 0;
    for (i = 0; i < static_cast<int>(Bank::customers.size()); i++) {
        if ((Bank::customers.at(i).GetChecking() + Bank::customers.at(i).GetSavings()) > acctTotal) {
            acctTotal = Bank::customers.at(i).GetChecking() + Bank::customers.at(i).GetSavings();
            richestCustomer = i;
        }
    }
    return Bank::customers.at(richestCustomer);
}
