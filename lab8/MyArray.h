// MyArray Class decleration

#pragma once
#include <iostream>
#include <initializer_list>

class MyArray {
    private:
    size_t asize = 0;
    int * aptr;  

    public:
    // constructors
    MyArray(size_t size);
    MyArray(std::initializer_list<int> list);
    MyArray(const MyArray& array); // copy constructor

    // operator=
    MyArray& operator=(const MyArray& rhs); // copy assignment operator
    
    // destructor
    ~MyArray();

    // size()
    size_t size() const noexcept;
    
    // toString()
    std::string toString() const;

    // operator[]
    int& operator[](size_t index);
    const int& operator[](size_t index) const;

    // operator==
    bool operator==(const MyArray& rhs) const noexcept;

    // operator+=
    MyArray& operator+=(int value);

    // friend operator>>
    friend std::istream& operator>>(std::istream& input, MyArray& rhs);
};
// non-member operator<<
std::ostream& operator<<(std::ostream& out, MyArray& rhs);
