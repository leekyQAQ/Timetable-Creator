#pragma once
using namespace std;
#include <iostream>
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
	virtual bool login(fstream &file);
	virtual void signin(fstream &file);
	bool checkID(string filename, int ID);
	
};

