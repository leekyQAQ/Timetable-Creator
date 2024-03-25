#pragma once
#include "User.h"
#include "event.h"
#include "timeTable.h"
#include <vector>
using namespace std;

class Teacher
{

public:
    Teacher();
    ~Teacher();
    virtual void Sing_in();
    virtual void Log_in();
    // Additional methods for teacher-specific functionality
    void displayTimetable();
    void modifyTimetable();
};

