#include<iostream>
#include "event.h"
#include "User.h"
#include <fstream>
using namespace std;


int main() {
    // Open the file
    int choice;
    cout << "Welcome to the program" << endl;
    cout << "Are you 1)Student, 2)Teacher, 3)Admin" << endl;
    cin >> choice;
    if (choice == 1) {
        fstream file("Studentdata.txt");
        User user;
        cout << "Login(1)/ Signup(2)" << endl;
        cin >> choice;
        if (choice == 1){
            user.login(file);
        }
        else {
            user.signin(file);
        }
        file.close();
    }


}
