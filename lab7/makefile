main : main.o Bank.o BankAccount.o
	g++ main.o Bank.o BankAccount.o -o main

main.o : main.cpp Bank.h
	g++ -c main.cpp -o main.o

Bank.o : Bank.cpp Bank.h
	g++ -c Bank.cpp -o Bank.o

BankAccount.o : BankAccount.cpp BankAccount.h
	g++ -c BankAccount.cpp -o BankAccount.o

run : main
	./main