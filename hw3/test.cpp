#include <iostream>
#include <string>
using namespace std;

int main() {
    int size = 3;
    string* arr = new std::string[size];
    arr[0] = "asdf";
    arr[1] = "qwer";
    arr[2] = "zxcv";
    for (int i = 0; i < size; i++) {
        cout << "-" << "" << arr[i] << "-" << endl;
    }
    arr[0] = arr[size-1];
    arr[size-1] = "";
    size--;
    for (int i = 0; i < size; i++) {
        cout << "-" << "" << arr[i] << "-" << endl;
    }
}
