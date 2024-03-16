#include "event.h"
event::event(int code, string name, double start, double end, int day, vector<int> ID)
{
	m_code = code;
	m_eventName = name;
	m_start = start;
	m_end = end;
	m_day = day;
	m_participants = ID;
}
event::event(int code, string name, vector<int> ID)
{
	 m_code=code;
	 m_eventName=name;
	 m_start=-1;
	 m_end=-1;
	 m_day=-1;
	 m_participants=ID;
}
void event::addParticipants(int ID)
{
	m_participants.push_back(ID); 
}
void event::deleteParticipants(int ID)
{
	for (int i = 0; i < m_participants.size(); i++) {
		// Check if the current participant's ID matches the specified ID
		if (m_participants.at(i) == ID) {
			// If there's a match, erase the participant from the vector
			m_participants.erase(m_participants.begin() + i);
			// Return from the function immediately after erasing the participant
			return;
		}
	}


}
void event::saveEvent(fstream &file)
{
	// Move the file pointer to the end of the file
	file.seekp(0, std::ios::end);

	// Write event-related information to the file
	// Use getEventCode(), getEventName(), getEventStart(), getEventEnd(), and getEventDay() to retrieve event information
	file << getEventCode() << " " << getEventName() << " " << getEventStart() << " " << getEventEnd() << " " << getEventDay() << " ";

	// Write the number of participants to the file
	file << m_participants.size() << " ";

	// Iterate over the participants vector and write each participant to the file
	for (int i = 0; i < m_participants.size(); i++) {
		file << m_participants.at(i) << " ";
	}

	// Write a newline character to place the new event information on the next line
	file << std::endl;

}
void event::out()
{//a display function for testing. same structure as saveEvent function
	cout << getEventCode() << " " << getEventName() << " " << getEventStart() << " " << getEventEnd() << " " << getEventDay() << " " << m_participants.size() << " ";

	for (int i = 0; i < m_participants.size(); i++)
	{
		cout << m_participants.at(i) << " ";
	}
	cout << endl;
}