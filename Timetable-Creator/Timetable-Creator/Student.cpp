#include "Student.h"
#include <fstream>
#include <sstream>
#include <algorithm>
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
    // Shows all courses available for selection
    // For now, let's just assume we display courses directly from m_timetable vector
    for (int i = 0; i < m_timetable.size(); ++i) {
        std::cout << (i + 1) << ": " << m_timetable[i] << std::endl;
    }

    // Asks the student for their course selection
    std::cout << "Enter the course number to add to your timetable, or 0 to finish:" << std::endl;
    int choice;
    std::cin >> choice;

    // Process selection until the user decides to finish with 0
    while (choice != 0) {
        if (choice > 0 && choice <= m_timetable.size()) {
            // Add course to personal timetable
            // We're directly storing course strings here, but you'll need to adjust if using event objects
            m_personalTimetable.push_back(m_timetable[choice - 1]);
        }
        else {
            std::cout << "Invalid course number. Please try again." << std::endl;
        }
        std::cin >> choice;
    }

    // Assuming resolveConflicts() is properly defined elsewhere
    resolveConflicts();

    // Sort the personal timetable (if required). This is just a placeholder.
    // Actual sorting would depend on how your events are structured.
}

void Student::resolveConflicts() {
    // Implement logic to resolve any conflicts in the timetable
}
void Student::saveTimetableToFile(const std::string& filename) {
    // Save the personal timetable to the file
    std::ofstream file(filename);

    // Check if we're able to open the file
    if (!file.is_open()) {
        std::cerr << "Could not open file to save timetable." << endl;
        return;
    }

    // Assuming event objects have a method to convert to a string for file output
    for (const auto& course : m_personalTimetable) {
        file << course.toString() << endl; // You will need to replace 'toString()' with actual method
    }

    file.close();
}
// Overloads the stream insertion operator to print the personal timetable
ostream& operator<<(ostream& out, const Student& student) {
    for (const auto& courseStr : student.m_personalTimetable) {
        out << courseStr << endl;
    }
    return out;
}

