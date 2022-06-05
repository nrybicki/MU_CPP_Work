// Copyright (c) Nick Rybicki, 4/22/2022

#ifndef COURSE_H
#define COURSE_H
#include <string>
#include <ostream>

class Course {
    private:
    std::string courseName;
    std::string section;
    std::string* students;
    int numberOfStudents;
    int capacity;

    public:
    Course(const std::string& courseName, const std::string& section, int capacity);
    ~Course();
    // overload copy constructor
    Course(const Course& origCourse);
    // overload copy assignment operator
    Course& operator=(const Course& rhsCourse);
    void setCourseName(std::string name);
    std::string getCourseName() const;
    void setSection(std::string section);
    std::string getSection() const;
    void addStudent(const std::string& name);
    void dropStudent(const std::string& name);
    int getNumberOfStudents() const;
    int getCourseCapacity() const;
    void shrinkCapacity();
    void increaseCapacity(unsigned inc);
    std::string getStudents(int index);
    // overload operator+= as a member function
    Course& operator+=(const Course& rhsCourse);
    // define operator<< as a friend function for Course
    friend std::ostream& operator<<(std::ostream& out, const Course& rhsCourse);
};

#endif