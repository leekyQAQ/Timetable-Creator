#
#
#
#
#
#



**Timetable Creator Proposal** 

Zen Inaba 

Moses Lei 

Zhao Beier 

Yingjie Zou 

Section: C04
#








# Project Description:
The project aims to create a timetable management system for students, teachers, and administrators. The system will provide a login interface for these three user types, each having different functionalities.

Upon launching the program, users are presented with three options: Student, Teacher, or Admin. Each user type has a unique ID and password, stored in separate text files (student\_data.txt, teacher\_data.txt). The system validates the entered ID and password. If the ID is not valid or the password is incorrect, the user is prompted to re-enter the information or sign up.

For sign-up, the system checks if the entered ID is valid and not already linked to a password. If these conditions are met, the user can create a new password, which is then saved in the respective text file.

Once logged in, users can manage their timetables. They can view their current timetable, add or delete courses. The system reads the available courses from a file (course.txt), checks for time conflicts, and updates the timetable accordingly. The updated timetable is saved to a text file associated with the user’s ID.

The admin has additional functionalities. They can add or delete courses, add meetings, and manage IDs. All changes are updated in the respective text files.
#

# ` `C++ Concepts:

|Concept|Description|
| :-: | :-: |
|Classes|<p>User Class</p><p>Event Class</p><p>Timetable class</p><p>Student class</p><p>Teacher class</p><p>Administrator class</p>|
|Inheritance|teacher class, student class, and administrator are derived class of user class|
|Aggregation|<p>`  `-Event class is aggregation class of timetable class</p><p>`  `-timetable class is aggregation class of student and teacher class</p>|
|Overloaded Operators |<p>(overload operator<<) Display Event information (Event class)</p><p>(overload operator<<) Display Timetable (Timetable Class)</p><p>(overload operator =) assign the right-side value to the left one (for all classes)</p>|
|Constructor|- event class have two overloaded constructors, one for administrator addCourses function with 3 parameters, one for addMeeting function with 6 parameters.|


|vector|- Vector allows us to keep adding events to the timetable without knowing the total number. |
| :- | :- |
|Pointers|Pointers will be used to store addresses of variables and objects.|
|<p>File Input/Output</p><p></p>|<p>- Output the timetable to a dataset file</p><p>- Read the courses with correlated ID from dataset file</p>|
|Polymorphism/virtual function|<p>This concept will be used to allow making a different log-in without sign-in first.</p><p>In this project, log\_in function of User class is the virtual function. </p>|
** 

**Description of key elements:**
# Classes:
1. **User Class:**

Base class for Student, Teacher, and Admin classes. Contains common attributes like ID validation, password and department.

1. **Student Class:**

Manages student-specific functionalities such as viewing and editing the timetable.  

1. **Teacher Class:**

Manages teacher-specific functionalities such as adding and deleting courses.  

1. **Admin Class:**

Manages admin-specific functionalities, including the ability to add or delete courses, manage IDs, and schedule teacher meetings.

1. **Timetable Class:**

This class is used to check time conflicts of events, and act as cache during runtime

1. **Event Class:**

This class is used to hold class information. So that all the information relative to the lecture could be managed easily

# Functions:
1. **StudentLogin Function:**

Handles the login process specifically for students. Asks for the student ID, validates it against the data stored in a .txt file. If the ID is valid, prompt the password. If the password is correct, the student is logged in. If either the ID is invalid or the password is incorrect, the function provides an option to sign up.



1. **TeacherLogin Function:**

Manages the login process for teachers. Similar to the student login, it validates the entered teacher ID against the data in .txt file If the ID is valid, prompts for the password. If the password is correct, the teacher is successfully logged in. If the ID is invalid or the password is incorrect, the function suggests signing up. 

1. **AdminLogin Function(virtual):**

Handles the login process specifically for administrators. Prompts for the admin username and password, checking them against the predefined admin credentials. If both are correct, the admin is successfully logged in.



1. **Edit/create timetable function:**

From courses.txt. Read the student's optional courses and the courses that have been selected and display them. After a student selects or deletes a course, add or remove the student's name from the course that has the corresponding course code

1. **Display timetable (overload operator<<):**

List the course content stored in studentTimetableVector one by one.

1. **Add time function:**

Assign a schedule to courses with a corresponding teacher ID that currently lacks a time assignment, and then save this information in the courses.txt file. It's important to note that the schedule can only be added once and cannot be modified thereafter.

1. **Set department function:**

Switch to a different department to access files from a different department.

1. **Add courses function:**

construct a lecture class obj with the course name, corresponding course code, and teacher ID, and save into the courses.txt file (publish a course).

1. **Delete courses function:**

delete the course with corresponding course code in the courses.txt file.

1. **Add Meeting function:**

Display the timetable of the selected teachers for the day, and check if there is any time conflict after the user enters the meeting start time, and finally write the meeting name, ID, time, and participant ID into the courses.txt.

1. **Add teacher/Student ID:**

According to the input department, user type, the ID is stored in the corresponding txt file.

1. **Check Id function:**

Function checks ID in .txt files. 

1. **Time conflict check function:**

Check whether there is a conflict between the start and end times of the lecture stored in the vector, give a response if there is a conflict, and write the content of the vector to a txt file if not.



