#pragma once
#include "User.h"
#include "Event.h"
class Admin : public User
{
public:
	Admin(){}
	void login();
	void addID();
	void addCourses();
	void addMeeting();
	void saveInfo();


};