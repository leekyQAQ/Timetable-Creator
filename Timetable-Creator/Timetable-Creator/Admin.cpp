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

void Admin::addCourses()
{
	fstream file("Teacherdata.txt");
	int code, teacherID;
	string name;
	vector <int> participants;
	string filename = askFaculty();
	

	cout << "Enter the course code: ";
	cin >> code;
	cout << "Enter the course name: ";
	cin >> name;
	cout << "teacher ID list" << endl;
	string IDhold,pass;

	while (file>>IDhold>>pass)
		cout << IDhold << endl;

	cout << "Enter the Teacher ID: ";
	cin >> teacherID;

	participants.push_back(teacherID);

	event course(code, name, participants);
	fstream file_out(filename, ios::app);
	course.saveEventToFile(file_out);
	file_out.close();
}

//THIS PART NEED REWRITE
void Admin::addMeeting(timeTable &memory)
{
	int code, holdParticipants, day;
	double startTime, endTime;
	string name;
	vector <int> participants;
	timeTable teacherSchedule;
	

	bool timeConflict;

	cout << "Enter the meeting name: ";
	cin >> name;
	cout << "Enter the day of meeting: ";
	cin >> day;

	while (true)
	{
		cout << "Enter the participants IDs (enter -1 to end enering): ";
		cin >> holdParticipants;
			if (holdParticipants == -1){break;}


		for (int i = 0; i < memory.getSize(); i++)
		{
			//  cout << endl;
			
			vector<int> ID = memory.getEventParticipants(i);
			for (int j = 0; j < ID.size(); j++)
			{
				//  cout << ID[j]<<" ";
				if (holdParticipants == ID[j]&&day==memory.getEventDay(i))
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

void Admin::deleteCourse()
{
	int deleteCode;
	string filename = askFaculty();
	cout << "Enter the event code that you want to delete: ";
	cin >> deleteCode;

	int code, day, participantNum, hold;
	string name;
	double startTime, endTime;
	vector <int> participants;
	vector <event> courseVec;

	fstream file(filename);
	while (file >> code >> name >> startTime >> endTime >> day >> participantNum)
	{ 
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

		participants.clear();
	}

	file.clear();
	file.close();

	timeTable updatedData(courseVec);
	updatedData.outTimeTable();
	cout << endl;
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


string Admin::askFaculty()
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
		filename = "Business_eventList.txt";
		break;

	}

	return filename;
}


vector <event> Admin::getTeacherSchedule(int id, int selectday,string filename)
{
	vector <event>schedule; 
	int code, day,numParticipants, holdParticipant;
	string name;
	double startTime, endTime;
	vector<int> participants;
	bool mach;

	ifstream file(filename);
	while (!file.eof())
	{
		file >> code >> name >> startTime >> endTime >> day >> numParticipants;
		mach = false;
		for (int i = 0; i < numParticipants; i++)
		{
			file >> holdParticipant;
			participants.push_back(holdParticipant);
			if (holdParticipant == id&&day==selectday)
				mach = true;
		}

		if (mach)
		{
			event holdEvent(code, name, startTime, endTime, day, participants);
			schedule.push_back(holdEvent);
		}
	}

	return schedule;
}