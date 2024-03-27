#include "Admin.h"

void Admin::login()
{
	int id;
	string pass;
	bool check = true;
	//check the user ID
	while (!check)
	{
		cout << "Please enter your ID (-1 to Exit): ";
		cin >> id;

		if (id == -1)
			return;

		else if (id != m_id)
		{
			cout << "Wrong ID. Try again" << endl;
			check = false;
		}

		else
			check = true;
	}
	//check the password
	while (!check)
	{
		cout << "Please enter the password (-1 to exit): ";
		cin >> pass;
		if (pass == "-1" )
			return;

		else if (pass != m_password)
		{
			cout << "Wrong password. Try again" << endl;
			check = false;
		}

		else
			check = true;
	}
	
}



void Admin::saveInfo()
{
	ofstream file_out("AdminID.txt");
	file_out << m_id << " " << m_password << endl;
	file_out.close();
}

void Admin::addID()
{
	int ID, hold;
	string filename;
	cout << "Enter 1 for student ID and 2 for teacher ID: ";
	cin >> hold;
	if (hold == 1)
		filename = "";
	else
		filename = "";

	cout << "Enter the ID: ";
	cin >> ID;
	ofstream file_out(filename);
	file_out << ID << endl;
	file_out.close();
}

void Admin::addCourses()
{
	int code;
	string name;
	vector <int> participants;
	cout << "Enter the course code: ";
	cin >> code;
	cout << "Enter the course name: ";
	cin >> name;

	event course(code, name, participants);
	fstream file_out("Event.txt");
	course.saveEventToFile(file_out);
	file_out.close();
}

void Admin::addMeeting()
{
	int code;
	string name;
	vector <int> participants;
	cout << "Enter the meeeting code: ";
	cin >> code;
	cout << "Enter the meeting name: ";
	cin >> name;

	event meeting(code, name, participants);
	fstream file_out("Event.txt");
	meeting.saveEventToFile(file_out);
	file_out.close();
}
