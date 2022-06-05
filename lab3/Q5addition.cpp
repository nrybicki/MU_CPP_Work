// Copyright (c) Nick Rybicki & Ryan Campbell
#include <iostream>
#include <cstdlib>

int main() {
  // Initialize two random numbers and correct sum to check user guess
  //std::srand(time(0));
  int num1 = rand() % 100;
  int num2 = rand() % 100;
  int sum = num1 + num2;

  // Display question and initialize user sum guess
  std::cout << "Question " << num1 << "+" << num2 << "=?" << std::endl;
  int userSum = 0;

  // Prompt user for first guess
  std::cout << "Answer:";
  std::cin >> userSum;
  if (userSum == sum) {
    std::cout << "Good job!" << std::endl;
  } else {
    std::cout << "Oops! You have one more attempt. Try again!" << std::endl;
    std::cout << "Answer:";
    std::cin >> userSum;
    if (userSum == sum) {
      std::cout << "Good job!" << std::endl;
    } else {
      std::cout << "Sorry, " << userSum << " is not correct!" << std::endl;
      std::cout << "The correct answer is " << sum << "." << std::endl;
    }
  }
  
  return 0;
}
