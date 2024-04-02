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
    
    string department;
    fstream file;
    int faculty;
    string filename;
    do{
    cout << "1. Faculty of Health Sciences." << endl;
    cout << "2. Faculty of Science." << endl;
    cout << "3. Faculty of Engineering." << endl;
    cout << "4. Faculty of Humanities." << endl;
    cout << "5. Faculty of Social Science." << endl;
    cout << "6. Faculty of Business." << endl;
    cout << "Enter the faculty (1 - 6): ";
    cin >> faculty;

    switch (faculty)
    {
    case 1:
        filename = "healthSciences_eventList.txt";
        department = "healthSciences";
        break;
    case 2:
        filename = "science_eventList.txt";
        department = "science";
        break;
    case 3:
        filename = "engineering_eventList.txt";
        department = "engineering";
        break;
    case 4:
        filename = "humanities_eventList.txt";
        department = "humanities";
        break;
    case 5:
        filename = "socialScience_eventList.txt";
        department = "socialScience";
        break;
    case 6:
        department = "Business";
        filename = "Business_eventList.txt";
        break;
    }
        file.open(filename);
        if (!file.is_open()) {
            cerr << "Could not open file for department "<< endl;

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
                       // cout << user;
                        memory.updateFrom(user.gettimetable());
                       // memory.outTimeTable();
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
        Admin user;
        user.login();
        int functionChose;
        do 
        {
            cout << "Add ID(1)/ Add course(2)/ Add meeting(3)/ Delete event(4)/ Delete ID(5) / Exit(6)"<< endl;
            cin >> functionChose;
            if (functionChose == 1)
            {
                user.addID();
            }
            if (functionChose == 2)
            {
                user.addCourses(memory);
            }
            if (functionChose == 3)
            {
                user.addMeeting(memory);
            }
            if (functionChose == 4)
            {
                user.deleteCourse(memory);
            }
            if (functionChose == 5)
            {
                user.deleteID();
            }

        } while (functionChose != 6);
    }

    memory.saveToFile(file, filename);
    file.close();
    cout << "Program closed. Have a good day.";
    

}
