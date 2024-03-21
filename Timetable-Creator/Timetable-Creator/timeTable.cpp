#include "timeTable.h"
timeTable::timeTable(vector<event >timetable)
{
	m_timeTable = timetable;
}
bool timeTable::timeConfilctCheck()
{
	bool conflict=false;

	for (int day = 1; day <= 7; day++)
	{
		vector<event> eventInDay;
		int numberOfEventInDay=0;
		for (event num : m_timeTable)
		{
			if (num.getEventDay() == day)
			{
				numberOfEventInDay++;
				
				eventInDay.push_back(num);
			}
		}
		if (numberOfEventInDay >1)
		{
			for (int i = 0; i < numberOfEventInDay; i++)
			{
				
				for (int j = 0; j < numberOfEventInDay; j++)
				{
					conflict = false;
					if (eventInDay[i].getEventCode() != eventInDay[j].getEventCode())
					{
						if(eventInDay[j].getEventEnd()<eventInDay[i].getEventEnd()&& eventInDay[j].getEventEnd() > eventInDay[i].getEventStart()) { conflict = true; }

						if (eventInDay[j].getEventStart() < eventInDay[i].getEventEnd() && eventInDay[j].getEventStart() > eventInDay[i].getEventStart()) { conflict = true; }

						if (conflict == true)
						{
							
							cout << "Conflict between " << eventInDay[i].getEventName() << " and " << eventInDay[j].getEventName() << endl;
							return conflict;
						}
					}
				}

			}
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
