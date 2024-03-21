#pragma once
#include "User.h"
class Admin : public User
{
public:
	Admin(){}
	void login();
	void signin();
	void addID();
	void addCourses();
	void addMeeting();
	void saveInfo();


};