#pragma once
#include "User.h"
#include "event.h"
#include "timeTable.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Student : public User {
private:
    string m_department; // Student's department
    timeTable m_timetable; // Full timetable for the department, managed by the timeTable class

public:

    Student(string department, string password, int id,timeTable memory); // Parameterized constructor
    ~Student(); 

    // Getters and Setters for department
    string GetDepartment() { return m_department; }
    void SetDepartment(string department) { m_department = department; }


    // Overloading the insertion (<<) operator to print the personal timetable
    friend ostream& operator<<(ostream& out, const Student& student);
};

