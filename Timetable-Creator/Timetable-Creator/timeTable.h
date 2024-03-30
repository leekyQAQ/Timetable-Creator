//Zhao Beier 400511533
 #pragma once
#include"event.h"
class timeTable
{
protected:
	vector<event> m_timeTable;
public:
	timeTable();
	timeTable(vector<event >timetable);

	vector<event> getVector() { return m_timeTable; }
	event getEventByCode(int code);
	event getEvent(int number);
	string getEventName(int code);
	double getEventStart(int code);
	double getEventEnd(int code);
	int getEventDay(int code);
	vector<int> getEventParticipants(int code);
	int getSize();
	//with event
	void addEventToTimetable(event add);
	void deletEvent(int code);
    void updateFrom(event update);
	//with self
	bool timeConfilctCheck();
	bool timeCheck(event parameter);
	//with memory
	void saveToFile(fstream& file, string fileName);
	void updateFrom(timeTable timetable);
	
	void outTimeTable();
};
