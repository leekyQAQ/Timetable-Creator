#include "Teacher.h"
Teacher::Teacher() {
    m_department = " ";
}
Teacher::~Teacher() {

}
Teacher::Teacher(string department, string password, int id) {
    m_department = department;
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
