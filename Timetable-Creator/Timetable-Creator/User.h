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
public:
	User();
	User(string password, string department);
	virtual void login() = 0;
	virtual void signin() = 0;

};

