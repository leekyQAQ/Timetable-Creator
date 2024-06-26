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
    int storedId; 
    string storedPassword;
    bool idFound = true;
    do{
    cout << "Enter your user ID: ";
    cin >> inputId;
    // make: geting each line the file and than check if the id is real or not
    // vector<string> allStoredPassword;
     //vector<int> allStoredID;
     // if it's real then ask to user for password
    while (file >> storedId >> storedPassword) {
        // allStoredID.push_back(storedId);
        // allStoredPassword.push_back(storedPassword);
        if (storedId == inputId) {
            idFound = false;
            string inputPassword;
            do {
                
                cout << "Enter your password: " << endl;
                cin >> inputPassword;

                if (inputPassword == storedPassword) {
                    cout << "Login successful! Welcome, User " << inputId << "." << endl;
                    m_id = storedId;
                    m_password = inputPassword;
                }
                else {
                    cout << "Incorrect password. Please try again." << endl;
                }
            } while (inputPassword != storedPassword);

            break;
        }
    }
    // than check the password in the same file to see if the password is correct
    if (idFound) {
        cout << "User ID not found. Please try again." << endl;
        file.clear();
        file.seekg(0, ios::beg);
    }
}while (idFound);
	/*string inputPassword;
	cout << "Enter your password: "<< endl;
	cin >> inputPassword;

	if (inputPassword == storedPassword) {
		cout << "Login successful! Welcome, User " << inputId << "." << endl;
        return true;
	}
	else {
		cout << "Incorrect password. Please try again."<< endl;
	}*/

}



void User::signin(fstream& file) {
    // Variables 
    int inputId;
    int storedId;
    string storedPassword;
    bool idExists = false;        vector<int> ids;
        vector<string> passwords;
    do {
        // User input
        cout << "Enter your user ID: ";
        cin >> inputId;

        // Vectors to store user IDs and passwords


        // Read the IDs and passwords from the file into the vectors and checks if the id is real
        while (file >> storedId >> storedPassword) {
            ids.push_back(storedId);  // Add the ID to the IDs vector
            passwords.push_back(storedPassword);  // Add the password to the passwords vector
            if (storedId == inputId) {
                idExists = true;
            }
        }

        file.clear();
        file.seekg(0, ios::beg);
        file.seekp(0, ios::beg);

        // If the input ID does not exist in the file, print an error message and return
        if (!idExists) {
            cout << "User ID does not exist. Please choose a different ID." << endl;

        }
    }
    while (!idExists);
    // Ask the user to create a new password
    string newPassword;
    cout << "Create a new password: ";
    cin >> newPassword;

    // Loop through the IDs vector
    
    for (int i = 0; i < ids.size(); i++) {
        if (ids[i] == inputId) {
            passwords[i] = newPassword;
        }
        file << ids[i] << " " << passwords[i] << endl;
    }
    
    cout << "Password Set successfully. Please open the program again to log in." << endl;
}

bool User::checkID(string filename, int ID)
{
    int storedId;
    string storedPassword;
    bool idExists = false;
    ifstream file(filename);
    while (file >> storedId >> storedPassword) {
        if (storedId == ID) {
            idExists = true;
            break;
        }
    }
    file.close();
    return idExists;
}
