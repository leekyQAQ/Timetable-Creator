#pragma once
#include "User.h"
class Admin : public User
{
protected:
	int m_id;
	string m_pass;
public:
	void log_in();
	void sign_in();
	void addID();
	void addCourses();
	void addMeeting();


};