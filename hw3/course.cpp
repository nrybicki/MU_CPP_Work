// Copyright (c) Nick Rybicki, 4/22/2022
// Purpose: Practice dynamic memory allocation through implementation of
//  a course class

#include "course.h"
#include <iostream>
#include <string>
#include <ostream>
#include <iomanip>
#include <algorithm>

// Main constructor
Course::Course(const std::string& courseName, const std::string& section,
                    int capacity) {
    Course::courseName = courseName;
    Course::section = section;
    Course::capacity = capacity;
    Course::numberOfStudents = 0;
    Course::students = new std::string[Course::capacity];
    std::cout << Course::courseName << "-" << Course::section;
    std::cout << " has been created!" << std::endl;
}

// Destructor
Course::~Course() {
    std::string oldCourseName = Course::courseName;
    delete[] Course::students;
    std::cout << oldCourseName << "-" << Course::section;
    std::cout << " has been deleted!" << std::endl;
}

/* Overloaded copy constructor that assigns origCourse data to current Course
* object
* 
* inputs:   origCourse - Course object whose data will be copied to current
* Course object
* output:   none, ends with printing confirmation message to console
*/
Course::Course(const Course& origCourse) {
    courseName = origCourse.getCourseName();
    section = origCourse.getSection();
    capacity = origCourse.getCourseCapacity();
    numberOfStudents = origCourse.getNumberOfStudents();
    students = new std::string[capacity];
    std::copy(origCourse.students, origCourse.students + origCourse.capacity,
        students);
    std::cout << "New " << courseName << "-" << section;
    std::cout << " has been created by the copy constructor!" << std::endl;
}

/* Overloaded copy assignment operator which assigns rhsCourse data to current
* Course object
* 
* inputs:   rhsCourse - Course object whose data will be copied to current
* Course object
* output:   returns reference to the current Course object and prints
* confirmation message
*/
Course& Course::operator=(const Course& rhsCourse) {
    std::string oldName = courseName, oldSection = section;
    courseName = rhsCourse.getCourseName();
    section = rhsCourse.getSection();
    capacity = rhsCourse.getCourseCapacity();
    numberOfStudents = rhsCourse.getNumberOfStudents();
    students = new std::string[capacity];
    std::copy(rhsCourse.students, rhsCourse.students + rhsCourse.capacity,
        students);
    std::cout << "The content of " << rhsCourse.getCourseName() << "-";
    std::cout << rhsCourse.getSection() << " was copied to " << oldName << "-";
    std::cout << oldSection << " using operator=" << std::endl;
    return *this;
}

/* Sets the course name and prints the name change
* 
* inputs:   name - string name to set as new course name
* output:  void, prints name change to console
*/
void Course::setCourseName(std::string name) {
    std::string oldName = Course::courseName;
    Course::courseName = name;
    std::cout << "Course name " << oldName << "-" << Course::section;
    std::cout << " has been changed to " << name << "-";
    std::cout << Course::section << std::endl;
}

/* Returns the course name string
* 
* inputs:   (none)
* output:  returns the string courseName
*/
std::string Course::getCourseName() const {
    return Course::courseName;
}

/* Sets the course section and prints the change
* 
* inputs:   section - string section to be set
* output:  void, just prints section change
*/
void Course::setSection(std::string section) {
    std::string oldSection = Course::section;
    Course::section = section;
    std::cout << "Course section " << Course::courseName << "-" << oldSection;
    std::cout << " has been changed to " << Course::section << std::endl;
}

/* Returns the section string
* 
* inputs:   (none)
* output:   returns the string section
*/
std::string Course::getSection() const {
    return Course::section;
}

/* Attempts to add a student to the course object, prints message if student
* added successfully or if the addition failed
* 
* inputs:   name - string name of student to be added to course object
* output:   void, prints out message to console
*/
void Course::addStudent(const std::string& name) {
    if (Course::numberOfStudents == Course::capacity) {
        std::cout << "The course " << Course::courseName << "-";
        std::cout << Course::section << " has reached maximum capacity!";
        std::cout << "\nYou need to increase the capacity!!" << std::endl;
    } else {
        students[Course::numberOfStudents++] = name;
        std::cout << name << " was added to " << Course::courseName << "-";
        std::cout << Course::section << " successfully" << std::endl;
    }
}

/* Attempts to drop a student from the course and moves the student at the last
* position to freed position, prints out message if drop is successful or
* failed
* 
* inputs:   name - string name of student to be dropped from the course object
* output:   void, prints message to console
*/
void Course::dropStudent(const std::string& name) {
    int index = -1;
    for (int i = 0; i < Course::numberOfStudents; i++) {
        if (Course::students[i] == name) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        std::cout << "Student: " << name << " was not found!" << std::endl;
    } else {
        Course::students[index] = Course::students[Course::numberOfStudents-1];
        Course::students[Course::numberOfStudents-1] = "";
        Course::numberOfStudents--;
        std::cout << "Student: " << name << " dropped the course ";
        std::cout << Course::courseName << "-" << Course::section << std::endl;
    }
}

/* Returns the number of students in the course
* 
* inputs:   (none)
* output:   integer number of students in the course object
*/
int Course::getNumberOfStudents() const {
    return Course::numberOfStudents;
}

/* Returns the capacity of the course
* 
* inputs:   (none)
* output:   integer capacity of the course
*/
int Course::getCourseCapacity() const {
    return Course::capacity;
}

/* Shrinks the capacity of the course to the number of students enrolled and
* displays message if the operation is done
* 
* inputs:   (none)
* output:   void, shrinks capacity (if possible) and displays message
*/
void Course::shrinkCapacity() {
    if (Course::numberOfStudents == Course::capacity) {
        std::cout << "No need to shrink !! Capacity is equal to the number of";
        std::cout << " students for " << Course::courseName << "-";
        std::cout << Course::section << std::endl;
    } else {
        Course::capacity = Course::numberOfStudents;
        std::string* temp = new std::string[Course::capacity];
        std::copy(Course::students, Course::students+Course::numberOfStudents,
            temp);
        Course::students = temp;
        std::cout << "The capacity of " << Course::courseName << "-";
        std::cout << Course::section << " is now equal to the number of";
        std::cout << " students" << std::endl;
    }
}

/* Increases capacity of course by inc amount and displays confirmation message
* 
* inputs:   inc - unsigned integer amount to increase capacity by
* output:   void, prints confirmation message
*/
void Course::increaseCapacity(unsigned inc) {
    Course::capacity += inc;
    std::string* temp = new std::string[Course::capacity];
    std::copy(Course::students, Course::students + Course::numberOfStudents,
        temp);
    Course::students = temp;
    std::cout << "The capacity of " << Course::courseName << "-";
    std::cout << Course::section << " has been increased by ";
    std::cout << inc << std::endl;
}

/* Returns the student name at index in the array
* 
* inputs:   index - integer index of student to be returned
* output:   returns string name of the student at index
*/
std::string Course::getStudents(int index) {
    return Course::students[index];
}

/* Overloaded operator+= which adds students from rhsCourse to current course
* object
* 
* inputs:   rhsCourse - constant course object whose students are to be added
to current course object
* output:   returns the current course objects reference
*/
Course& Course::operator+=(const Course& rhsCourse) {
    Course::capacity += rhsCourse.getCourseCapacity();
    std::string* temp = new std::string[Course::capacity];
    std::copy(Course::students, Course::students + Course::numberOfStudents,
        temp);
    Course::students = temp;
    for (int i = Course::numberOfStudents, j = 0; i < Course::capacity &&
        j < rhsCourse.getNumberOfStudents(); i++, j++) {
        Course::students[i] = rhsCourse.students[j];
    }
    Course::numberOfStudents += rhsCourse.getNumberOfStudents();
    std::cout << "The students of " << rhsCourse.getCourseName() << "-";
    std::cout << rhsCourse.getSection() << " have been added to ";
    std::cout << Course::courseName << "-" << Course::section << " with the ";
    std::cout << "operator+=" << std::endl;
    return *this;
}

/* Friend function ostream operator<< for printing relative Course information
* 
* inputs:   out - ostream object which the current course object's information
will be printed to
*           rhsCourse - the current object whose info will be printed to the
outstream out object
* output:   returns the ostream object reference
*/
std::ostream& operator<<(std::ostream& out, const Course& rhsCourse) {
    out << std::setfill('~') << std::setw(33) << "" << std::endl;
    out << std::setfill(' ');
    out << std::left << std::setw(11) << "Course Name" << ": ";
    out << rhsCourse.getCourseName() << std::endl;

    out << std::left << std::setw(11) << "Section" << ": ";
    out << rhsCourse.getSection() << std::endl;

    out << std::left << std::setw(11) << "Capacity" << ": ";
    out << rhsCourse.getCourseCapacity() << std::endl;

    out << std::left << std::setw(11) << "#ofStudents" << ": ";
    out << rhsCourse.getNumberOfStudents() << std::endl;

    out << std::right << std::setfill('-') << std::setw(21) << "Student List";
    out << std::setw(12) << "" << std::endl;

    out << std::setfill(' ');
    if (rhsCourse.getNumberOfStudents() == 0) {
        out << "(no students to list)" << std::endl;
    } else {
        for (int i = 0; i < rhsCourse.getNumberOfStudents(); i++) {
            out << i+1 << ". " << rhsCourse.students[i] << std::endl;
        }
    }
    return out;
}
