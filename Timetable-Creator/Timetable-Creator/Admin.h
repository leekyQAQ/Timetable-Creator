#pragma once
#include "User.h"
#include "Event.h"
class Admin : public User
{
public:
	Admin() : User("12345", 400541114) {}
	void login();
	void addID();
	void addCourses();
	void addMeeting();
	void saveInfo();


};