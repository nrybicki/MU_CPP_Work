
#include <iostream>

class Sample {
    public:
    Sample(int xValue, int yValue) {
        xVal = xValue;
        yVal = yValue;
        std::cout << "constructor for " << xVal << " " << yVal << std::endl;
    }
    void show_data() {
        std::cout << "sample object (" << xVal << "," << yVal << ")" << std::endl;
    }
    ~Sample() {
        std::cout << "destructor for " << xVal << " " << yVal << std::endl;
    }

    private:
    int xVal;
    int yVal;
};

int main() {
    // int myInt;
    // int* myIntPtr;
    // int myVar;
    // int* myBill = nullptr;
    // myInt = 10;
    // myIntPtr = &myInt;
    // myVar = *myBill;
    // myVar = *myIntPtr + 10.5;
    // std::cout << myVar << std::endl;


    Sample* sample1 = new Sample(4,7);
    (sample1)->show_data();
    Sample sample2(10,2);
    delete sample1;

    return 0;
}
