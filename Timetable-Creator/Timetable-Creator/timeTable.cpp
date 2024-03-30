#include "timeTable.h"

// Constructor for the timeTable class
timeTable::timeTable(vector<event> timetable)
{
	m_timeTable = timetable;
}
timeTable::timeTable(event first)
{
	m_timeTable.push_back(first);
}
int timeTable::getSize()
{
	return m_timeTable.size();
}
// Retrieve an event from the timetable based on event code
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
string timeTable::getEventName(int code)
{
	// Iterate through the timetable
	for (event temp : m_timeTable)
	{
		// If event code matches, return the event name
		if (temp.getEventCode() == code)
		{
			return temp.getEventName();
		}
	}
}

// Retrieve the start time of an event from the timetable based on event code
double timeTable::getEventStart(int code)
{
	// Iterate through the timetable
	for (event temp : m_timeTable)
	{
		// If event code matches, return the event start time
		if (temp.getEventCode() == code)
		{
			return temp.getEventStart();
		}
	}
}

// Retrieve the end time of an event from the timetable based on event code
double timeTable::getEventEnd(int code)
{
	// Iterate through the timetable
	for (event temp : m_timeTable)
	{
		// If event code matches, return the event end time
		if (temp.getEventCode() == code)
		{
			return temp.getEventEnd();
		}
	}
}

// Retrieve the day of an event from the timetable based on event code
int timeTable::getEventDay(int code)
{
	// Iterate through the timetable
	for (event temp : m_timeTable)
	{
		// If event code matches, return the event day
		if (temp.getEventCode() == code)
		{
			return temp.getEventDay();
		}
	}
}

// Retrieve the participants of an event from the timetable based on event code
vector<int> timeTable::getEventParticipants(int code)
{
	// Iterate through the timetable
	for (event temp : m_timeTable)
	{
		// If event code matches, return the event participants
		if (temp.getEventCode() == code)
		{
			return temp.getEventParticipants();
		}
	}
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
						if (eventInDay[j].getEventEnd() <= eventInDay[i].getEventEnd() && eventInDay[j].getEventEnd() >= eventInDay[i].getEventStart()) { conflict = true; }

						if (eventInDay[j].getEventStart() <= eventInDay[i].getEventEnd() && eventInDay[j].getEventStart() >= eventInDay[i].getEventStart()) { conflict = true; }

						if (conflict == true)
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

// Output the timetable
void timeTable::outTimeTable()
{
	// Output each event in the timetable
	for (int i = 0; i < m_timeTable.size(); i++)
	{
		m_timeTable[i].out();
	}
}
