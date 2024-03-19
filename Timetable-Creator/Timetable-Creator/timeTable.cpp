#include "timeTable.h"
timeTable::timeTable(vector<event >timetable)
{
	m_timeTable = timetable;
}
bool timeTable::timeConfilctCheck()
{
	for (int day = 1; day <= 7; day++)
	{
		int numberOfEventInDay;
		for (event num : m_timeTable)
		{
			if (num.getEventDay() == day)
			{
				numberOfEventInDay++;
			}
		}
		for (int i = 0; i <= numberOfEventInDay; i++)
		{

		}
	}
}
void timeTable::saveTimetable(fstream& file)
{
	for (int i = 0; i = m_timeTable.size(); i++)
	{
		m_timeTable[i].saveEvent(file);

	}
}
