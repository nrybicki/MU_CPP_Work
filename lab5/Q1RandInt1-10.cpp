// Copyright (c) Nick Rybicki, 3/1/2022

#include <iostream>
#include <random>
using namespace std;

void printArray(const int arr[], int size) {
    for (int i = 1; i < size; i++) {
        cout << i << " repeats " << arr[i] << " times." << endl;
    }
}

int main() {
    random_device rnd; // will  be used to obtain a seed for the random number engine
    mt19937 gen(rnd()); // standard mersenne_twister_engine seeded with rnd()
    uniform_int_distribution<> distrib(1,10);

    int num;
    int histogram[11] = {0};

    for (int i = 0; i < 100; i++) {
        num = distrib(gen);
        histogram[num]++;
    }

    printArray(histogram, 11);

    return 0;
}
