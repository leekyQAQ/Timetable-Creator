#pragma once
#include "User.h"
#include "event.h"
#include <fstream>
#include "timeTable.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Teacher : public User {
private:
    string m_department; // Student's department
    timeTable m_timetable; // Full timetable for the department, managed by the timeTable class
    /*std::vector<string> m_personalTimetable; // Stores the student's personal timetable data*/

public:
    Teacher(); // Default constructor
    Teacher(string department, string password, int id); // Parameterized constructor
    ~Teacher();

    // Getters and Setters for department
    string GetDepartment() { return m_department; }
    void SetDepartment(string department) { m_department = department; }

    // Member functions for timetable management
    void generatePersonalTimetable();

    // Overloading the insertion (<<) operator to print the personal timetable
    friend ostream& operator<<(ostream& out, const Teacher& teacher);
};

