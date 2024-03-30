#include "Teacher.h"
#include <fstream>
#include <iostream>
using namespace std;

Teacher::~Teacher() {

}
Teacher::Teacher(string department, string password, int id, timeTable memory) :User(password, id) {
    m_department = department;

    for (int i = 0; i < memory.getSize(); i++) {
        event temp = memory.getEvent(i);
        vector<int> ID = temp.getEventParticipants();
        for (int j = 0; j < ID.size(); j++)
        {
            if (id == ID[j]) {
                m_timetable.addEventToTimetable(temp);
            }
        }
    }
}
void Teacher::changetime(timeTable memory) {
    string want;
    cout << "Do you want to change the time for the course? ( YES or NO)" << endl;
    cin >> want;
    if (want == "YES") {
        int code;
        cout << "Which course you want to change time" << endl;
        cin >> code;
        for (int j = 0; j < m_timetable.getSize(); j++) {
            event temp2 = m_timetable.getEvent(j);
            if (temp2.getEventCode() == code) {
                int start, end,day;
                
               // cout << temp2.getEventStart() << "-" << temp2.getEventEnd() << endl;
               /* cout << "Change the star time now" << endl;
                cin >> start;
                cout << "Change the end time now" << endl;
                cin >> end;
                cout << "Change the day now(1-5)" << endl;
                cin >> day;
                temp2.setEventStart(start);
                temp2.setEventEnd(end);
                temp2.setEventDay(day);*/
                do {
                    cout << "Change the star time now" << endl;
                    cin >> start;
                    cout << "Change the end time now" << endl;
                    cin >> end;
                    cout << "Change the day now(1-5)" << endl;
                    cin >> day;
                    temp2.setEventStart(start);
                    temp2.setEventEnd(end);
                    temp2.setEventDay(day);
                    if(m_timetable.timeConfilctCheck() == true)
                    {
                        cout << "There is a time conflict" << endl;
                    }
                } while (m_timetable.timeConfilctCheck() == true);
            }
            if (temp2.getEventCode() != code) {
                cout << "You are not allow to change anything of this cours" << endl;
            }
        }
        memory.updateFrom(m_timetable);
    }
    if (want == "NO") {
        return;
    }
}
ostream& operator<<(ostream& out, Teacher& teacher) {
    timeTable teachertimetable = teacher.gettimetable();
    out << "code" << "\t" << "course name" << "\t" << "start and end time of the course" << "\t" << "day" << "\t" << endl;
    for (int i = 0; i < teachertimetable.getSize(); i++) {
        event temp = teachertimetable.getEvent(i);
        out << temp.getEventCode() << "\t" << temp.getEventName() << "\t" << temp.getEventStart() << "-" << temp.getEventEnd() << "\t" << temp.getEventDay() << endl;
    }
    return out;
}
