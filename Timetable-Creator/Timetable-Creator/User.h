#pragma once
using namespace std;
#include <iostream>
#include <string>
#include <fstream>
class User
{
protected:
	string m_password;
	string m_department;
	int m_id;
public:
	User();
	User(string password, string department, int id);
	virtual void login();
	virtual void signin();
	
};

