#include<iostream>
#include "event.h"
#include "User.h"
#include <fstream>
#include"timeTable.h"
#include "Student.h"
#include"Teacher.h"
#include"Admin.h"
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
        int choice2;
        cout << "Login(1)/ Signup(2)" << endl;
        Student user;
        cin >> choice2;
        if (choice2 == 1){
            user.login(IDfile);
            user.SetDepartment(department);
            user.setTimetable(memory);
            //loop
            while (choice == 1){
                cout << "Displaytime table (1)/ Edit/Create timetable(2) / Exit(3)"<<endl;
                int newchoice;
                cin >> newchoice;
                if (newchoice == 1) {
                    cout << "Your timetable:" << endl;
                    cout << user;
                }
                else if (newchoice == 2) {
                    cout << "Add (1)/ Delete(2) courses" << endl;
                    cin >> newchoice;
                    if (newchoice == 1) {
                        user.selecttimetable(memory);
                        cout << user;
                        memory.updateFrom(user.gettimetable());
                        memory.outTimeTable();
                    }
                    else {
                        user.deletevent(memory);
                        memory.updateFrom(user.gettimetable());
                    }
                }
                else {
                    
                    break;
                }
            }
        }
        else {
            user.signin(IDfile);
        }
        IDfile.close();

    }
     if (choice == 2) {
        fstream IDfile("Teacherdata.txt");
        int choice2;
        cout << "Login(1)/ Signup(2)" << endl;
        Teacher user;
        cin >> choice2;
        if (choice2 == 1) {
            user.login(IDfile);
            user.SetDepartment(department);
            user.setTimetable(memory);
            //memory.updateFrom(user.gettimetable());
            
            //loop
            while (choice == 2) {
                cout << "Displaytime table (1)/ add course time(2) / Exit(3)" << endl;
                int newchoice;
                cin >> newchoice;
                if (newchoice == 1) {
                    cout << "Your timetable:" << endl;
                    cout << user;
                }
                else if (newchoice == 2) {
                    
                    user.changetime();
                    memory.updateFrom(user.gettimetable());
                    //memory.outTimeTable();
                }
                else {
                    break;
                }
            }
            
        }
        else {
            user.signin(IDfile);
        }
        IDfile.close();
    }
    if(choice==3) {
        cout << "placeholder for admin interface" << endl;
    }

    memory.saveToFile(file, filename);
    file.close();
    cout << "Program closed. Have a good day.";
    

}
