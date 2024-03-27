#include "Admin.h"

void Admin::login()
{
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

	event course(code, name, participants);
	fstream file_out("Event.txt");
	course.saveEventToFile(file_out);
	file_out.close();
}
