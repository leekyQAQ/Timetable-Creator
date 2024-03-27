#include "User.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
User::User() {
	m_password = "";
	m_id = 0;
}

User::User(string password, int id) {
	m_password = password;
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
		cout << "User ID not found. Please try again." << endl;
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
	/// ask the user to enter their id The id must already exist in the file
	cout << "Enter your user ID: ";
	cin >> inputId;

	// Check if the ID already exists in the file if not tell them that the id is invalid and try again
	int storedId;
	string storedPassword;
	bool idExists = false;

	while (file >> storedId >> storedPassword) {
		if (storedId == inputId) {
			idExists = true;
			break;
		}
	}
	if (!idExists) {
		cout << "User ID does not exists. Please choose a different ID." << endl;
		return;
	}

	// if the id exist in the file and don't have an passwrod attach to it than Ask the user to create a password
	string newPassword;
	cout << "Create a password: " ;
	cin >> newPassword;

	// Save the new user to the file make sure the the password is linked prited beside the user id since there will be many id with no password attached to it 
	ofstream file_out(file, ios_base::app);
	file_out << inputId << " " << newPassword << endl;
	file_out.close();

	cout << "Sign-up successful! You can now log in." << endl;

}