// Copyright (c) Nick Rybicki, 03/29/2022

#include <iostream>
#include <string>
#include "BankAccount.h"

/* BankAccount constructor with initialized inputs
*
* input: newName - name of BankAccount
*        amt1 - checking account balance
*        amt2 - savings account balance
*/
BankAccount::BankAccount(std::string newName, double amt1, double amt2) {
    BankAccount::name = newName;
    BankAccount::checkingBalance = amt1;
    BankAccount::savingsBalance = amt2;
}

/* set the customer name to parameter newName
*
* input: newName - new name to be set
* output: void
*/
void BankAccount::SetName(std::string newName) {
    BankAccount::name = newName;
}

/* return the customer name
*
* input: (none)
* output: returns the string name
*/
std::string BankAccount::GetName() {
    return BankAccount::name;
}

/* set the checking account balance to parameter amt
*
* input: amt - amount to set the checking data member equal to
* output: void
*/
void BankAccount::SetChecking(double amt) {
    BankAccount::checkingBalance = amt;
}

/* return the checking account balance
*
* input: (none)
* output: returns the double checking account balance
*/
double BankAccount::GetChecking() {
    return BankAccount::checkingBalance;
}

/* set the savings account balance to parameter amt
*
* input: amt - amount to set the savings data member equal to
* output: void
*/
void BankAccount::SetSavings(double amt) {
    BankAccount::savingsBalance = amt;
}

/* return the savings account balance
*
* input: (none)
* output: returns the double savings account balance
*/
double BankAccount::GetSavings() {
    return BankAccount::savingsBalance;
}

/* add parameter amt to the checking account balance (only if positive)
*
* input: amt - amount to add to checking account balance
* output: void
*/
void BankAccount::DepositChecking(double amt) {
    if (amt > 0)
        BankAccount::checkingBalance += amt;
}

/* add parameter amt to the savings account balance (only if positive)
*
* input: amt - amount to add to savings account balance
* output: void
*/
void BankAccount::DepositSavings(double amt) {
    if (amt > 0)
        BankAccount::savingsBalance += amt;
}

/* subtract parameter amt from the checking account balance (only if positive)
*
* input: amt - amount to subtract from checking account balance
* output: void
*/
void BankAccount::WithdrawChecking(double amt) {
    if (amt > 0)
        BankAccount::checkingBalance -= amt;
}

/* subtract parameter amt from the savings account balance (only if positive)
*
* input: amt - amount to subtract from savings account balance
* output: void
*/
void BankAccount::WithdrawSavings(double amt) {
    if (amt > 0)
        BankAccount::savingsBalance -= amt;
}

/* subtract parameter amt from the checking account balance and add to the savings account balance (only if positive)
*
* input: amt - amount to move from checking account to savings account
* output: void
*/
void BankAccount::TransferToSavings(double amt) {
    if (amt > 0) {
        BankAccount::checkingBalance -= amt;
        BankAccount::savingsBalance += amt;
    }
}