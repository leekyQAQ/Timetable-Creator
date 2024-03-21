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

void User::login(fstream& file) {
	// ask the user for their id
	int inputId;
	cout << "Enter your user ID: ";
	cin >> inputId;
	// make: geting each line the file and than check if the id is real or not
	int storedId;
	string storedPassword;
	bool idFound = false;
	// if it's real then ask to user for password
	while (file >> storedId >> storedPassword) {
		if (storedId == inputId) {
			idFound = true;
			break;
		}
	}
	// than check the password in the same file to see if the password is correct
	if (!idFound) {
		cout << "User ID not found. Please try again or sign up." << endl;
		return;
	}
	string inputPassword;
	cout << "Enter your password: "<< endl;
	cin >> inputPassword;

	if (inputPassword == storedPassword) {
		cout << "Login successful! Welcome, User " << inputId << "." << endl;
	}
	else {
		cout << "Incorrect password. Please try again."<< endl;
	}

}


void User::signin(fstream& file) {
	int inputId;
	cout << "Enter your desired user ID: ";
	cin >> inputId;

	// Check if the ID already exists in the file
	int storedId;
	string storedPassword;
	bool idExists = false;

	while (file >> storedId >> storedPassword) {
		if (storedId == inputId) {
			idExists = true;
			break;
		}
	}

	if (idExists) {
		cout << "User ID already exists. Please log in or choose a different ID." << endl;
		return;
	}

	// Ask the user to create a password
	string newPassword;
	cout << "Create a password: " ;
	cin >> newPassword;

	// Save the new user to the file
	file << inputId << " " << newPassword << endl;
	cout << "Sign-up successful! You can now log in." << endl;
}