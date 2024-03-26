#include "Student.h"
#include <iostream>
using namespace std;
Student::Student() {
    m_department = " ";
}
Student::~Student() {

}
Student::Student(string department) {
    department = " ";
}
void Student::displayTimetable() {
    // Similar to the Teacher's method
    timeTable tt;
    /*
    tt.loadFromFile("timetable.txt");
    std::cout << tt.formatForDisplay();*/
}

void Student::chooseTimeslot() {
    // Implement logic for a student to choose a timeslot
    // This might involve presenting available times and letting the student select one
}
ostream& operator<<(ostream& out, Student timetableS) {

    out << "The time table: " << endl;
	return out;
}
