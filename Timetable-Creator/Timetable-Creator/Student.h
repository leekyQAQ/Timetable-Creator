#pragma once
#include "User.h"
#include "event.h"
#include <vector>
#include "timeTable.h"
using namespace std;

class Student
{
public:
    Student();
    ~Student();
    virtual void Sing_in();
    virtual void Log_in();
    // Additional methods for student-specific functionality
    void displayTimetable();
    void chooseTimeslot();
    // ... other methods as needed
};

