// MyArray implementation

#include <iostream>
#include <sstream>
#include <initializer_list>

#include "MyArray.h"

// Write the implementation of each members and non-members
MyArray::MyArray(size_t size) {
    asize = size;
    aptr = new int[asize];
}


MyArray::MyArray(std::initializer_list<int> list) {
    asize = list.size();
    aptr = new int[asize];
    std::copy(std::begin(list), std::end(list), aptr);
}


MyArray::~MyArray() {
    std::cout << "MyArray destructor" << std::endl;
    delete[] aptr;
}


size_t MyArray::size() const noexcept {
    return asize;
}


std::string MyArray::toString() const {
    std::ostringstream output;
    output << "{";
    for (size_t i = 0; i < asize - 1; i++) {
        output << aptr[i] << ", ";
    }
    output << aptr[asize - 1] << "}" << std::endl;
    return output.str();
}


int& MyArray::operator[](size_t index) {
    if (index >= asize) {
        throw std::out_of_range("Index out of range");
    }
    return aptr[index];
}
const int& MyArray::operator[](size_t index) const {
    if (index >= asize) {
        throw std::out_of_range("Index out of range");
    }
    return aptr[index];
}


bool MyArray::operator==(const MyArray& rhs) const noexcept {
    if (asize != rhs.asize) {
        return false;
    }
    for (size_t i = 0; i < asize; i++) {
        if (aptr[i] != rhs.aptr[i]) {
            return false;
        }
    }
    return true;
}


MyArray& MyArray::operator+=(int value) {
    for (size_t i = 0; i < asize; i++) {
        aptr[i] += value;
    }
    return *this;
}


std::istream& operator>>(std::istream& input, MyArray& rhs) {
    for (size_t i = 0; i < rhs.asize; i++) {
        input >> rhs.aptr[i];
    }
    return input;
}


std::ostream& operator<<(std::ostream& out, MyArray& rhs) {
    out << rhs.toString();
    return out;
}

// Part 2
MyArray::MyArray(const MyArray& original) {
    asize = original.size();
    aptr = new int[asize];
    std::copy(original.aptr, (original.aptr) + asize, this->aptr);
}

// Part 3
MyArray& MyArray::operator=(const MyArray& rhs) {
    std::cout << "MyArray copy assignment operator" << std::endl;
    asize = rhs.size();
    aptr = new int[asize];
    std::copy(rhs.aptr, (rhs.aptr) + asize, this->aptr);
    return *this;
}
