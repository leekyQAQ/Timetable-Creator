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
    vector<string> m_timetable; // This will store your timetable data

public:
    Student(); // Assume default constructor is defined elsewhere
    ~Student(); // Assume destructor is defined elsewhere
    Student(string department, string password, int id); // Assume this is defined elsewhere

    string GetDepartment() { return m_department; }
    void SetDepartment(string department) { m_department = department; }

    void readTimetableFromFile(const string& department);
    void generatePersonalTimetable(); // Assume this is defined elsewhere
    void resolveConflicts(); // Assume this is defined elsewhere

    // A method to output the timetable
    friend ostream& operator<<(ostream& out, const Student& s);

    // Additional methods can be added as necessary
};
