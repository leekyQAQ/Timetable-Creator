#include "User.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
User::User() {
	m_password = "";
	m_department = "";
	m_id = 0;
}

User::User(string password, string department, int id) {
	m_password = password;
	m_department = department;
	m_id = id;
}

void User::login() {
	fstream read("Teacherdata");
	if (read) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}
}

void User::signin() {

}