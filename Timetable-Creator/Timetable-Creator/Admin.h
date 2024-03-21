#pragma once
#include "User.h"
class Admin : public User
{
public:
	void log_in();
	void sign_in();
	void addID();
	void addCourses();
	void addMeeting();


};