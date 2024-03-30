#include<iostream>
#include "event.h"
#include "User.h"
#include <fstream>
#include"timeTable.h"
#include "Student.h"
using namespace std;


int main() {



   /* // Open the file
    int choice;
    cout << "Welcome to the program" << endl;
    cout << "Are you 1)Student, 2)Teacher, 3)Admin" << endl;
    cin >> choice;
    if (choice == 1) {
        fstream file("Studentdata.txt");
        User user;
        cout << "Login(1)/ Signup(2)" << endl;
        cin >> choice;
        if (choice == 1){
            user.login(file);
        }
        else {
            user.signin(file);
        }
        file.close();
    }
    else if (choice == 2) {
        fstream file("Teacherdata.txt");
        User user;
        cout << "Login(1)/ Signup(2)" << endl;
        cin >> choice;
        if (choice == 1) {
            user.login(file);
        }
        else {
            user.signin(file);
        }
        file.close();
    }
    else {
        cout << "placeholder" << endl;
    }
   */
    
    string filename;
    string department;
    cout << "Which department: (Health Sciences / Science / Engineering / Humanities / Social Science / Business)" << endl;
    cin >> department;
    if (department == "Engineering") {
        filename = "Engineering_eventList.txt";
    }
    else if (department == "Science") {
        filename = "Science_eventList.txt";
    }
    else if (department == "Health Sciences") {
        filename = "Health_Sciences_eventList.txt";
    }
    else if (department == "Humanities") {
        filename = "Humanities_eventList.txt";
    }
    else if (department == "Business") {
        filename = "Business_eventList.txt";
    }
    else if (department == "Social Science") {
        filename = "Social_Science_eventList.txt";
    }

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Could not open file for department: " << department << endl;

    }


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
    memory.outTimeTable();
    vector<int> id = { 1,1,1 };
    cout<<memory.timeCheck(event(10, "test", 8.0, 11.0, 1, id) );
    
}
