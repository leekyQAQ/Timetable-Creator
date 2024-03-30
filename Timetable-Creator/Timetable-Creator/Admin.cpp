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

void Admin::addID()
{
	int ID, hold;
	string filename;
	bool check = false;
	cout << "Enter 1 for student ID and 2 for teacher ID: ";
	cin >> hold;
	if (hold == 1)
		filename = "Studentdata.txt";
	else
		filename = "Teacherdata.txt";

	do
	{
		cout << "Enter the ID (-1 to Exit): ";
		cin >> ID;
		if (ID == -1)
			return;

		check = checkID(filename, ID);
		if (check == true)
			cout << "ID already exist. Please try again. " << endl;

	} while (check);
	
	ofstream file_out(filename, ios::app);
	file_out << ID << " -1" << endl; // -1 is a default password
	file_out.close();
}

void Admin::addCourses()
{
	int code, faculty;
	string name, filename;
	vector <int> participants;

	cout << "1. Faculty of Health Sciences." << endl;
	cout << "2. Faculty of Science." << endl;
	cout << "3. Faculty of Engineering." << endl;
	cout << "4. Faculty of Humanities." << endl;
	cout << "5. Faculty of Social Science." << endl;
	cout << "6. Faculty of Business." << endl;
	cout << "Enter the faculty (1 - 6): ";
	cin >> faculty;

	switch (faculty)
	{
	case 1:
		filename = "healthSciences_eventList.txt";
		break;
	case 2:
		filename = "science_eventList.txt";
		break;
	case 3:
		filename = "engineering_eventList.txt";
		break;
	case 4:
		filename = "humanities_eventList.txt";
		break;
	case 5:
		filename = "socialScience_eventList.txt";
		break;
	case 6:
		filename = "business_eventList.txt";
		break;

	}
	cout << "Enter the course code: ";
	cin >> code;
	cout << "Enter the course name: ";
	cin >> name;

	event course(code, name, participants);
	fstream file_out(filename, ios::app);
	course.saveEventToFile(file_out);
	file_out.close();
}
//THIS PART NEED REWRITE
/*void Admin::addMeeting()
{
	int code;
	string name;
	vector <int> participants;
	cout << "Enter the meeeting code: ";
	cin >> code;
	cout << "Enter the meeting name: ";
	cin >> name;

	event meeting(code, name, participants);
	fstream file_out("Event.txt", ios::app);
	meeting.saveEventToFile(file_out);
	file_out.close();
}*/

void Admin::deleteCourse()
{
	int faculty;
	string filename;

	cout << "1. Faculty of Health Sciences." << endl;
	cout << "2. Faculty of Science." << endl;
	cout << "3. Faculty of Engineering." << endl;
	cout << "4. Faculty of Humanities." << endl;
	cout << "5. Faculty of Social Science." << endl;
	cout << "6. Faculty of Business." << endl;
	cout << "Enter the faculty (1 - 6): ";
	cin >> faculty;

	switch (faculty)
	{
	case 1:
		filename = "healthSciences_eventList.txt";
		break;
	case 2:
		filename = "science_eventList.txt";
		break;
	case 3:
		filename = "engineering_eventList.txt";
		break;
	case 4:
		filename = "humanities_eventList.txt";
		break;
	case 5:
		filename = "socialScience_eventList.txt";
		break;
	case 6:
		filename = "business_eventList.txt";
		break;

	}
	
	int deleteCode;
	cout << "Enter the course code that you want to delete: ";
	cin >> deleteCode;

	int code, day, participantNum, hold;
	string name;
	double startTime, endTime;
	vector <int> participants;
	vector <event> courseVec;

	fstream file(filename);
	while (!file.eof())
	{
		file >> code >> name >> startTime >> endTime >> day >> participantNum; 
		for (int i = 0; i < participantNum; i++)
		{
			file >> hold;
			participants.push_back(hold);
		}

		if (code != deleteCode)
		{
			event course(code, name, startTime, endTime, day, participants);
			courseVec.push_back(course);
		}
	}

	file.clear();
	file.close();

	timeTable updatedData(courseVec);
	updatedData.saveToFile(file, filename); 
	file.close();

}

void Admin::deleteID()
{
	int ID, IDhold, studentOrTeacher;
	bool check;
	string filename, passwordHold;
	vector<int> IDs;
	vector<string> passwords;
	cout << "Enter 1 for Student ID and 2 for Teacher ID: ";
	cin >> studentOrTeacher;
	if (studentOrTeacher == 1)
		filename = "Studentdata.txt";

	else
		filename = "Teacherdata.txt";

	do
	{
		cout << "Enter the ID taht you want to delete: ";
		cin >> ID;
		check = checkID(filename, ID);
		if (check = false)
			cout << "ID doesn't exist. please try again." << endl;
	} while (!check);

	ifstream file_in(filename);
	while (file_in >> IDhold >> passwordHold)
	{
		if (ID != IDhold)
		{
			IDs.push_back(IDhold);
			passwords.push_back(passwordHold);
		}
	}
	file_in.close();

	ofstream file_out(filename);
	for (int i = 0; i < IDs.size(); i++)
		file_out << IDs[i] << " " << passwords[i] << endl;

	file_out.close();
}