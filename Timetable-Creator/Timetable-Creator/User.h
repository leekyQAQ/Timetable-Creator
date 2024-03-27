#pragma once
using namespace std;
#include <string>
class User
{
protected:
	string m_password;
	int m_id;
public:
	User();
	User(string password, int id);
	virtual void login(fstream &file);
	virtual void signin(fstream &file);
	
};

