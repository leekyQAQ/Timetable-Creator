#pragma once
#include <iostream>
using namespace std;
#include <string>
#include <fstream>
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
	bool checkID(string filename, int ID);
	
};

