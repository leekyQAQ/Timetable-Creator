#include "User.h"
#include <string>
using namespace std;
User::User() {
	m_password = "";
	m_department = "";
}

User::User(string password, string department) {
	m_password = password;
	m_department = department;
}

void User::login() {
	
}

void User::signin() {

}