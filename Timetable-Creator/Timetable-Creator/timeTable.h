//Zhao Beier 400511533
 #pragma once
#include"event.h"
class timeTable
{
protected:
	vector<event> m_timeTable;
public:
	timeTable(vector<event >timetable);
	timeTable(event first);
	vector<event> getVector() { return m_timeTable; }
	event getEvent(int code);
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
	//with memory
	void saveToFile(fstream& file, string fileName);
	void updateFrom(timeTable timetable);
	
	void outTimeTable();
};
