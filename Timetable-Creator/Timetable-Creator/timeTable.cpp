#include "timeTable.h"

// Constructor for the timeTable class
timeTable::timeTable(vector<event> timetable)
{
	m_timeTable = timetable;
}
timeTable::timeTable()
{

}
int timeTable::getSize()
{
	return m_timeTable.size();
}
// Retrieve an event from the timetable based on event code
int timeTable::getEventCode(int number)
{
	return m_timeTable[number].getEventCode();
}
event timeTable::getEvent(int number)
{
	// Iterate through the timetable
	return m_timeTable[number];
}
event timeTable::getEventByCode(int code)
{
	// Iterate through the timetable
	for (event temp : m_timeTable)
	{
		// If event code matches, return the event
		if (temp.getEventCode() == code)
		{
			return temp;
		}
	}
}

// Retrieve the name of an event from the timetable based on event code
string timeTable::getEventName(int number)
{
	return m_timeTable[number].getEventName();
}

// Retrieve the start time of an event from the timetable based on event code
double timeTable::getEventStart(int number)
{
	return m_timeTable[number].getEventStart();
}

// Retrieve the end time of an event from the timetable based on event code
double timeTable::getEventEnd(int number)
{
	return m_timeTable[number].getEventEnd();
}
// Retrieve the day of an event from the timetable based on event code
int timeTable::getEventDay(int number)
{
	return m_timeTable[number].getEventDay();
}

// Retrieve the participants of an event from the timetable based on event code
vector<int> timeTable::getEventParticipants(int number)
{
	return m_timeTable[number].getEventParticipants();
}

// Check for conflicts in the timetable
bool timeTable::timeConfilctCheck()
{
	bool conflict = false;

	// Iterate through each day of the week
	for (int day = 1; day <= 7; day++)
	{
		vector<event> eventInDay;
		int numberOfEventInDay = 0;
		// Iterate through the timetable to find events on the current day
		for (event num : m_timeTable)
		{
			if (num.getEventDay() == day)
			{
				numberOfEventInDay++;

				eventInDay.push_back(num);
			}
		}
		// If there are more than one event on the same day, check for conflicts
		if (numberOfEventInDay > 1)
		{
			for (int i = 0; i < numberOfEventInDay; i++)
			{

				for (int j = i; j < numberOfEventInDay; j++)
				{
					bool conflictInLoop = false;
					// Check for conflicts between events
					if (eventInDay[i].getEventCode() != eventInDay[j].getEventCode())
					{
						if (eventInDay[j].getEventEnd() <= eventInDay[i].getEventEnd() && eventInDay[j].getEventEnd() >= eventInDay[i].getEventStart()) { conflictInLoop = true; }

						if (eventInDay[j].getEventStart() <= eventInDay[i].getEventEnd() && eventInDay[j].getEventStart() >= eventInDay[i].getEventStart()) { conflictInLoop = true; }

						if (conflictInLoop == true)
						{

							cout << "Conflict between " << eventInDay[i].getEventName() << " and " << eventInDay[j].getEventName() << endl;
							conflict = conflictInLoop;
						}
					}
				}

			}
		}
	}
	return conflict;
}
bool timeTable::timeCheck(event parameter)
{
	bool conflict = false;

	// Iterate through each day of the week
	/*for (int day = 1; day <= 7; day++)
	{
		vector<event> eventInDay;
		int numberOfEventInDay = 0;
		// Iterate through the timetable to find events on the current day
		for (event num : m_timeTable)
		{
			if (num.getEventDay() == day)
			{
				numberOfEventInDay++;

				eventInDay.push_back(num);
			}
		}
		// If there are more than one event on the same day, check for conflicts
		if (numberOfEventInDay > 1)
		{*/
			for (int i = 0; i < m_timeTable.size(); i++)
			{
					bool conflictInLoop = false;
					// Check for conflicts between events
					if (m_timeTable[i].getEventCode() != parameter.getEventCode())
					{
						if (parameter.getEventEnd() <= m_timeTable[i].getEventEnd() && parameter.getEventEnd() >= m_timeTable[i].getEventStart()) { conflictInLoop = true; }

						if (parameter.getEventStart() <= m_timeTable[i].getEventEnd() && parameter.getEventStart() >= m_timeTable[i].getEventStart()) { conflictInLoop = true; }

						if (conflictInLoop == true)
						{
							cout << "Conflict between " << m_timeTable[i].getEventName() << " and " << parameter.getEventName() << endl;
							conflict = conflictInLoop;
						}
					}
			}
		//}
	//}
	return conflict;
}

// Add an event to the timetable
void timeTable::addEventToTimetable(event add)
{
	m_timeTable.push_back(add);
}

// Delete an event from the timetable based on event code
void timeTable::deletEvent(int deleteCode)
{
	// Iterate through the timetable
	for (vector<event>::iterator it = m_timeTable.begin(); it != m_timeTable.end(); it++)
	{
		// If event code matches, delete the event
		if (it->getEventCode() == deleteCode)
		{
			it = m_timeTable.erase(it);
			break;
		}
	}
}

// Update the timetable from another timetable
void timeTable::updateFrom(timeTable timetable)
{
	// Retrieve the events from the other timetable
	vector<event> temp = timetable.getVector();

	// Update each event in the timetable
	for (int i = 0; i < temp.size(); i++)
	{
		updateFrom(temp[i]);
	}
}

// Update an event in the timetable
void timeTable::updateFrom(event update)
{
	event temp = update;
	// Iterate through the timetable
	for (int i = 0; i < m_timeTable.size(); i++)
	{
		// If event code matches, update the event
		if (m_timeTable[i].getEventCode() == temp.getEventCode())
		{
			m_timeTable[i] = temp;
			break;
		}
	}
}

// Save the timetable to a file
void timeTable::saveToFile(fstream& file, string fileName)
{
	file.close();
	file.open(fileName, ios::out | std::ios::trunc);

	// Write each event to the file
	for (int i = 0; i < m_timeTable.size(); i++)
	{
		m_timeTable[i].saveEventToFile(file);
	}
}
void timeTable::sort()
{
	int n = m_timeTable.size();
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			if (m_timeTable[j].getEventDay() > m_timeTable[j + 1].getEventDay()) {
				
				event temp = m_timeTable[j];
				m_timeTable[j] = m_timeTable[j + 1];
				m_timeTable[j + 1] = temp;
			}
		}
	}
}

// Output the timetable
void timeTable::outTimeTable()
{
	// Output each event in the timetable
	for (int i = 0; i < m_timeTable.size(); i++)
	{
		m_timeTable[i].out();
	}

}

