#pragma once
#include "User.h"
#include "Event.h"
#include "timeTable.h"
class Admin : public User
{
public:
	Admin() : User("12345", 123) {}
	void login();
	void addID();
	void addCourses();
	void addMeeting(timeTable &memory);
	void deleteCourse();
	void deleteID();
	string askFaculty();
	vector <event> getTeacherSchedule(int id, int selectday, string filename);

};