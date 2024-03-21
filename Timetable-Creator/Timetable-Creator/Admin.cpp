#include "Admin.h"
void Admin::log_in()
{
	int lineNum = 0;
	string ID, pass, IDhold, passHold;

	//count the number of line in the file
	ifstream file_in("AdminID.txt");
	while (!file_in.eof())
	{
		getline(file_in, IDhold);
		lineNum++;
	}
	file_in.close();

	//check the username
	ifstream file_in("AdminID.txt");
	cout << "Enter the user ID: ";
	cin >> ID;
	while (!file_in.eof())
	{

	}


}

void Admin::sign_in()
{
	string hold;
	bool check = true;

	cout << "Creat the User ID" << endl;
	cout << "Please enter your user ID: ";
	cin >> m_id;
	cout << "Make the password" << endl;
	do {
		cout << "Please Enter the Password: ";
		cin >> pass;
		cout << "Please Re-Enter your password: ";
		cin >> hold;
		if (pass != hold)
		{
			check = false;
			cout << "Password does't mach. Try again." << endl;
		}
	} while (!check);
	
	ofstream file_out("AdminID.txt");
	file_out << ID << " " << pass << endl;
	file_out.close();
}

void Admin::addID()
{

}
void Admin::addCourses()
{

}
void Admin::addMeeting()
{

}
