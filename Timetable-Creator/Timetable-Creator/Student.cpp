#include "Student.h"
#include <iostream>
using namespace std;
Student::Student() {
    m_department = " ";
}
Student::~Student() {

}
Student::Student(string department, string password, int id) {
    m_department = department;
}
void Student::readTimetableFromFile(const string& filename) {
    // Open the file(for different department I need to read different file and read data
    // Parse the data and store it in the class members
    // all do by vector
}

void Student::generatePersonalTimetable() {
    // Use the data stored from the file to create a timetable
    // for user they just type in the course code and then the vector will add their id in
    // Check for conflicts and call resolveConflicts if necessary
    // use vector to save it 
}

void Student::resolveConflicts() {
    // Implement logic to resolve any conflicts in the timetable
}


ostream& operator<<(ostream& out, Student timetableS) {

    out << "The time table: " << endl;
	return out;
}
