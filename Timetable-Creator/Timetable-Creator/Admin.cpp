#include "Admin.h"

void Admin::login()
{
	int id;
	string pass;
	bool check = false;
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
	check = false;
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

void Admin::addCourses(timeTable &memory)
{
	fstream file("Teacherdata.txt");
	int code, teacherID;
	string name;
	vector <int> participants;
	bool check;
	
	do{
		check = false;
		cout << "Enter the course code: ";
		cin >> code;
		for (int i = 0; i < memory.getSize(); i++)
		{
			if (code == memory.getEventCode(i))
			{
				cout << "This code already exist. please try another code." << endl;
				check = true;
			}
		}

	} while (check);

	cout << "Enter the course name: ";
	cin >> name;

	cout << "teacher ID list" << endl;
	string pass;
	int IDhold;
	vector <int> teacherIDs;

	while (file >> IDhold >> pass)
	{
		cout << IDhold << endl;
		teacherIDs.push_back(IDhold);
	}
	file.close();
		
	check = true;
	do
	{
		cout << "Enter the Teacher ID: ";
		cin >> teacherID;
		for (int i = 0; i < teacherIDs.size(); i++)
		{
			if (teacherID == teacherIDs[i])
			{
				participants.push_back(teacherID);
				check = false;
				break;
			}
		}

		if (check)
			cout << "ID doesn't Exist. please try again." << endl;
		
	} while (check == true);
	
	event course(code, name, participants);
	memory.addEventToTimetable(course);
	cout << "Course added sucsessfully. " << endl;
}

//THIS PART NEED REWRITE
void Admin::addMeeting(timeTable &memory)
{
	int code, holdParticipants, day;
	double startTime, endTime;
	string name;
	vector <int> participants;
	timeTable teacherSchedule;
	bool check, timeConflict;

	cout << "Enter the meeting name: ";
	cin >> name;
	cout << "Enter the day of meeting: ";
	cin >> day;
	fstream file("Teacherdata.txt");
	cout << "teacher ID list" << endl;
	string pass;
	int IDhold;
	

	while (file >> IDhold >> pass)
	{
		cout << IDhold << endl;
		
	}
	file.close();

	while (true)
	{
		cout << "Enter the participants ID (enter -1 to end enering): ";
		cin >> holdParticipants;
			if (holdParticipants == -1){break;}

			//check if user already enter the ID
			check = false;
			for (int i = 0; i < participants.size(); i++)
				if (holdParticipants == participants[i])
					check = true;
			
			if (checkID("Teacherdata.txt", holdParticipants))
			{
				if (check) {cout << "You already added this ID" << endl;}

				else {
					for (int i = 0; i < memory.getSize(); i++)
					{
						//  cout << endl;

						vector<int> ID = memory.getEventParticipants(i);
						for (int j = 0; j < ID.size(); j++)
						{
							//  cout << ID[j]<<" ";
							if (holdParticipants == ID[j] && day == memory.getEventDay(i))
							{
								// cout << "my id" << m_id;
								 //temp.out();
								teacherSchedule.addEventToTimetable(memory.getEvent(i));
								ID.clear();

								break;
							}
						}
					}
					participants.push_back(holdParticipants);
				}
			}
			else { cout << "ID doesn't mach. Please try again." << endl; }
	}

	cout << "Schedules for teachers are following:" << endl;
	cout << "code  name  start-end  day   " << endl;
	for (int i = 0; i < teacherSchedule.getSize(); i++)
	{
		event temp = teacherSchedule.getEvent(i);
		cout << temp.getEventCode() << "\t" << temp.getEventName() << "\t" << temp.getEventStart() << "-" << temp.getEventEnd() << "\t" << temp.getEventDay() << endl;
	}
	//checkCode
	bool codeCheck = false;
	do {
		codeCheck = false;
		cout << "Enter the meeeting code(should be negative): ";
		cin >> code;
		for (int i = 0; i < memory.getSize(); i++)
		{
			if (memory.getEventCode(i) == code)
			{
				cout << "the code is occupied" << endl;
				codeCheck = true;
			}
		}
	} while (codeCheck);
	//cheech time
	do
	{
		cout << "Enter the starting time: ";
		cin >> startTime;
		cout << "Enter the ending time: ";
		cin >> endTime;
		 
		event meetingholder(code, name, startTime, endTime, day, participants);
		timeConflict = teacherSchedule.timeCheck(meetingholder);
		
		if (timeConflict)
			cout << "Please enter the time again." << endl;
	} while (timeConflict);
	
	event meeting(code, name, startTime, endTime, day, participants);
	meeting.out();
	memory.addEventToTimetable(meeting);
	//fstream file_out(filename, ios::app);

	//meeting.saveEventToFile(file_out);
	//file_out.close();
}

void Admin::deleteCourse(timeTable &memory)
{
	int deleteCode;
	bool check;

	cout << "Following are the list of course codes in this faculty; " << endl;
	for (int i = 0; i < memory.getSize(); i++)
		cout << memory.getEventCode(i)<<"  "<<memory.getEventName(i) << endl;
	
	do
	{
		check = true; 
		cout << "Enter the event code that you want to delete: ";
		cin >> deleteCode;
		for (int i = 0; i < memory.getSize(); i++)
		{
			if (deleteCode == memory.getEventCode(i))
			{
				check = false;
				break;
			}
		}

		if (check)
			cout << "Code does't mach. Please try again." << endl;
	} while (check);
	

	memory.deletEvent(deleteCode);
	cout << "Event deleted" << endl;

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
		cout << "Enter the ID that you want to delete: ";
		cin >> ID;
		check = checkID(filename, ID);
		if (check == false)
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