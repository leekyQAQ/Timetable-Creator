#pragma once
#include<string>
#include<vector>
#include<fstream>
#include<iostream>
using namespace std;
class event
{
protected:
	int m_code;
	string m_eventName;
	double m_start;
	double m_end;
	int m_day;
	vector<int> m_participants;
public:
	event(int code, string name, double start, double end,int day, vector<int> ID);
	event(int code, string name, vector<int> ID);

	int getEventCode() { return m_code; }
	string getEventName() { return m_eventName; }
	double getEventStart() { return m_start; }
	double getEventEnd() { return m_end; }
	int getEventDay() { return m_day; }
	vector<int> getEventParticipants() { return m_participants; }

	void setEventStart(double start) { m_start = start; }
	void setEventEnd(double end) { m_end = end; }
	void setEventDay(int day) { m_day = day; }

	void addParticipants(int ID);
	void deleteParticipants(int ID);
	void saveEvent(fstream &file);
	void out();
};

