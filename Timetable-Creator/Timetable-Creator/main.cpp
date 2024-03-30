#include<iostream>
#include "event.h"
#include "User.h"
#include <fstream>
#include"timeTable.h"
#include "Student.h"
#include"Teacher.h"
using namespace std;


int main() {

    /*
    // Open the file
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

    
    string filename;
    string department;
    cout << "Which department: " << endl;
    cin >> department;
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
    */
    fstream file("Business_eventList.txt");
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
    Teacher test("Business", "2345", 123, memory);
    test.changetime(memory);
    memory.outTimeTable();

}
