#include<iostream>
#include "event.h"
#include "User.h"
#include <fstream>
using namespace std;


int main() {
    // Open the file
    fstream file("Studentdata.txt");
    User user;
   
    user.signin(file);
    user.login(file);

    file.close();
}
