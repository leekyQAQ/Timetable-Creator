#include "Student.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>
using namespace std;

Student::~Student() {

}
Student::Student(string department, string password, int id, timeTable memory) {
    m_department = department;
    vector<int> ID;
    for (int i = 0; i < memory.size;i++) {

    }
    memory.getEvent(ID);

}


ostream& operator<<(ostream& out, const Student& student) {
    for (const auto& courseStr : student.m_personalTimetable) {
        out << courseStr << endl;
    }
    return out;
}

