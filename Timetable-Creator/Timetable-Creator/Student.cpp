#include "Student.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>
using namespace std;

Student::~Student() {

}
Student::Student(string department, string password, int id, timeTable timetable) {
    m_department = department;
    m_timetable = timetable;
}

void Student::generatePersonalTimetable() {
    
}


// Overloads the stream insertion operator to print the personal timetable
ostream& operator<<(ostream& out, const Student& student) {
    for (const auto& courseStr : student.m_personalTimetable) {
        out << courseStr << endl;
    }
    return out;
}

