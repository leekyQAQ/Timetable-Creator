#pragma once
#include"event.h"
class timeTable
{
protected:
	vector<event> m_timeTable;
public:
	timeTable(vector<event >timetable);
	bool timeConfilctCheck();
	void saveTimetable(fstream& file);

};
ostream& operator<<(ostream& s, timeTable v);
