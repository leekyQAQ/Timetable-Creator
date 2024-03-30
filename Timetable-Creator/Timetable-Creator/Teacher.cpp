#include "Teacher.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>
using namespace std;

Teacher::~Teacher() {

}
Teacher::Teacher(string department, string password, int id, timeTable timmetable) {
    m_department = department;
    m_timetable = timetable;
}

void Teacher::generatePersonalTimetable() {
    
}


// Overloads the stream insertion operator to print the personal timetable
ostream& operator<<(ostream& out, const Teacher& teacher) {
    for (const auto& courseStr : teacher.m_personalTimetable) {
        out << courseStr << endl;
    }
    return out;
}
