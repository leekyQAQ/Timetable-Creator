#include "User.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

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
    // Variable to store the input ID
    int inputId;

    // Ask the user to enter their ID
    cout << "Enter your user ID: ";
    cin >> inputId;

    // Vectors to store user IDs and passwords
    vector<int> ids;
    vector<string> passwords;

    // Variables to store the ID and password read from the file
    int storedId;
    string storedPassword;

    // Flag to check if the input ID exists in the file
    bool idExists = false;

    // Read the IDs and passwords from the file into the vectors
    while (file >> storedId >> storedPassword) {
        ids.push_back(storedId);  // Add the ID to the IDs vector
        passwords.push_back(storedPassword);  // Add the password to the passwords vector
        if (storedId == inputId) {
            idExists = true;  // If the ID exists in the file, set the flag to true
        }
    }

    // If the input ID does not exist in the file, print an error message and return
    if (!idExists) {
        cout << "User ID does not exist. Please choose a different ID." << endl;
        return;
    }

    // Ask the user to create a new password
    string newPassword;
    cout << "Create a new password: ";
    cin >> newPassword;

    // Loop through the IDs vector
    for (int i = 0; i < ids.size(); i++) {
        // If the ID is the input ID, update the password in the passwords vector
        if (ids[i] == inputId) {
            passwords[i] = newPassword;
        }
        // Write the ID and password to the file
        file << ids[i] << " " << passwords[i] << endl;
    }

    // Print a success message
    cout << "Password Set successfully. You can now log in." << endl;
}
