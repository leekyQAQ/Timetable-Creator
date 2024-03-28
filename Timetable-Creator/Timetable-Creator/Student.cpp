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
void Student::readTimetableFromFile(const string& department) {
    string filename;
    if (department == "Engineering") {
        filename = "engineering_eventList.txt";
    }
    else if (department == "Science") {
        filename = "science_eventList.txt";
    }
    // Add other departments as needed

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Could not open file for department: " << department << endl;
        return;
    }

    // Skip the header line
    string header;
    getline(file, header);

    // Clear the current timetable
    m_timetable.clear();

    // Read and store each line in the timetable
    string line;
    while (getline(file, line)) {
        m_timetable.push_back(line);
    }

    file.close();
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

ostream& operator<<(ostream& out, const Student& s) {
    out << "Timetable for department " << s.m_department << ":\n";
    for (const auto& entry : s.m_timetable) {
        out << entry << endl;
    }
    return out;
}

