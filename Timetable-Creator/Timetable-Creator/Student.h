#pragma once
#include "User.h"
#include "timeTable.h"
#include <vector>
#include <iostream>
#include <string>

class Student : public User {
private:
    std::string m_department; // Student's department
    timeTable m_timetable; // Full timetable for the department, managed by the timeTable class
    std::vector<std::string> m_personalTimetable; // Stores the student's personal timetable data

public:
    Student(); // Default constructor
    Student(const std::string& department, const std::string& password, int id); // Parameterized constructor
    virtual ~Student(); // Destructor

    // Getters and Setters for department
    std::string GetDepartment() const { return m_department; }
    void SetDepartment(const std::string& department) { m_department = department; }

    // Member functions for timetable management
    void readTimetableFromFile(const std::string& department);
    void generatePersonalTimetable();
    void resolveConflicts();
    void saveTimetableToFile(const std::string& filename);

    // Overloading the insertion (<<) operator to print the personal timetable
    friend std::ostream& operator<<(std::ostream& out, const Student& student);
};

