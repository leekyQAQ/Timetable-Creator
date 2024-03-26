#pragma once
#include "User.h"
#include "event.h"
#include <vector>
#include "timeTable.h"
#include <fstream>
#include <iostream>
using namespace std;

class Student
{
    string m_department;
public:
    Student();
    ~Student();
    Student(string department);
    string Getdepartment() {return m_department; };
    void Setdepartment(string department) { m_department = department; };
    // Additional methods for student-specific functionality
    void displayTimetable();
    void chooseTimeslot();
    // ... other methods as needed
};
ostream& operator<<(ostream& out, Student timetableS);
