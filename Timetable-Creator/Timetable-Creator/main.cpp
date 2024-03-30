#include<iostream>
#include "event.h"
#include "User.h"
#include <fstream>
#include"timeTable.h"
#include "Student.h"
#include"Teacher.h"
using namespace std;


int main() {
    cout << "Welcome to the program" << endl;
    string filename;
    string department;
    fstream file;
    do {
        //choose file to read
        cout << "Which department: (Health Sciences / Science / Engineering / Humanities / Social Science / Business)" << endl;
        cin >> department;
        if (department == "Engineering") {
            filename = "engineering_eventList.txt";
        }
        else if (department == "Science") {
            filename = "science_eventList.txt";
        }
        else if (department == "Health Sciences") {
            filename = "healthSciences_eventList.txt";
        }
        else if (department == "Humanities") {
            filename = "humanities_eventList.txt";
        }
        else if (department == "Business") {
            filename = "business_eventList.txt";
        }
        else if (department == "Social Science") {
            filename = "socialScience_eventList.txt";
        }

        file.open(filename);
        if (!file.is_open()) {
            cerr << "Could not open file for department: " << department << endl;

        }
    } while (!file.is_open());

    //initialize memory
    vector<event> temp;
    string tempstr;
    int count = 0;
    while (getline(file, tempstr))
    {
        count++;
    }
    file.clear();
    file.seekg(0, ios::beg);
    for (int i = 0; i < count; i++)
    {
        int code, size, day;
        double start, end;
        string name;
        vector<int> ID;
        file >> code >> name >> start >> end >> day >> size;
        for (int j = 0; j < size; j++)
        {
            int id;
            file >> id;
            ID.push_back(id);
        }

        temp.push_back(event(code, name, start, end, day, ID));

    }
    timeTable memory(temp);

    // Open the ID file
    int choice;

    cout << "Are you 1)Student, 2)Teacher, 3)Admin" << endl;
    cin >> choice;

    if (choice == 1) {
        fstream IDfile("Studentdata.txt");
        
        cout << "Login(1)/ Signup(2)" << endl;
        Student user;
        cin >> choice;
        if (choice == 1){
            user.login(IDfile);
            user.SetDepartment(department);
            
            user.setTimetable(memory);
        }
        else {
            user.signin(IDfile);
        }
        IDfile.close();
        cout << "placeholder for student interface"<<endl;

        //selec course
        cout << "your timetable:" << endl;
        cout << user;
        user.selecttimetable(memory);
       memory.updateFrom(user.gettimetable());

    }
    else if (choice == 2) {
        fstream IDfile("Teacherdata.txt");
        cout << "Login(1)/ Signup(2)" << endl;
        Teacher user;
        cin >> choice;
        if (choice == 1) {
            user.login(IDfile);
            user.SetDepartment(department);
            user.setTimetable(memory);
        }
        else {
            user.signin(IDfile);
        }
        IDfile.close();
        cout << "placeholder for teacher interface";

        //add course time
        cout << "your timetable:" << endl;
        cout << user;
        user.changetime();
        memory.updateFrom(user.gettimetable());
        //memory.outTimeTable();
    }
    else {
        cout << "placeholder" << endl;
    }

    
    

}
